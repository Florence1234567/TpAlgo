#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#include "Objects/Character.h"
#include "Game/GameMap.h"
#include "Player/PlayerCharacter.h"
#include "Player/PlayerController.h"
#include "UI/PlayerUI/ActionQueueUI.h"
#include "UI/PlayerUI/ActionContextMenuUI.h"
#include "UI/PlayerUI/InventoryUI.h"
#include "Enemy/EnemyCharacter.h"

int main() {
    sf::Vector2u windowSize(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Le meilleur jeu");
    window.setFramerateLimit(120);

    try
    {
        GameMap gameMap(windowSize.x, windowSize.y);

        sf::RenderTexture backgroundTexture(sf::Vector2u(windowSize.x, windowSize.y));
        backgroundTexture.clear(sf::Color::Transparent); 
        gameMap.Display(backgroundTexture);               
        backgroundTexture.display();
        sf::Sprite backgroundSprite(backgroundTexture.getTexture());

        sf::FloatRect grassBounds = gameMap.GetFenceBounds();

        //Create player
        PlayerCharacter Player(windowSize.x / 2, windowSize.y / 2, 2, 50.0f, 100.f);
        PlayerController PController(&Player, &gameMap);

        ActionQueueUI ActionQueueUI(PController, windowSize, 50);
        sf::Vector2f contextMenuPosition(ActionQueueUI.getPosition().x, ActionQueueUI.getPosition().y + ActionQueueUI.getPanelSize().y);
        ActionContextMenuUI ContextMenuUI(&PController, contextMenuPosition);
        InventoryUI InventoryUI(PController, Player, windowSize, 50);

        //Enemies
        auto Chicken = std::make_unique<EnemyCharacter>(windowSize.x / 3, windowSize.y / 3, 2, 50.0f, 100.f, EnemyType::Chicken, "Chicken");
        EnemyCharacter* ChickenPtr = Chicken.get();
        gameMap.AddEnemy(std::move(Chicken));

        auto Cow = std::make_unique<EnemyCharacter>(windowSize.x / 4, windowSize.y / 3, 2, 50.0f, 100.f, EnemyType::Cow, "Cow");
        EnemyCharacter* CowPtr = Cow.get();
        gameMap.AddEnemy(std::move(Cow));

        auto Chicken2 = std::make_unique<EnemyCharacter>(windowSize.x / 2, windowSize.y / 3, 2, 50.0f, 100.f, EnemyType::Chicken, "Chicken");
        EnemyCharacter* ChickenPtr2 = Chicken2.get();
        gameMap.AddEnemy(std::move(Chicken2));

        sf::Clock dtClock;
        while (window.isOpen())
        {
            while (const std::optional<sf::Event>& event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (PController.IsContextMenuOpen())
                    ContextMenuUI.HandleEvent(*event, &window);

                PController.HandleEvent(*event, grassBounds, &window);
                InventoryUI.HandleEvent(*event, &window);
            }

            // Update
            sf::Time dt = dtClock.restart();
            Player.Update(dt);
            ChickenPtr->Update(dt);
            ChickenPtr->UpdateSprite(dt);

            CowPtr->Update(dt);
            CowPtr->UpdateSprite(dt);

            ChickenPtr2->Update(dt);
            ChickenPtr2->UpdateSprite(dt);

            Player.UpdateSprite(dt);
            PController.Update(dt);
            ActionQueueUI.Update(dt);
            InventoryUI.Update(dt);

            // Draw
            window.clear(sf::Color::Blue);
            window.draw(backgroundSprite); 

            gameMap.DisplayObjects(window);
            ChickenPtr->Draw(window);
            CowPtr->Draw(window);
            ChickenPtr2->Draw(window);
            Player.Draw(window);

            ActionQueueUI.Draw(window);
            InventoryUI.Draw(window);
            ContextMenuUI.Draw(window);

            window.display();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
