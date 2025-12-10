#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#include "Base/Character.h"
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
        ActionContextMenuUI ActionContextMenuUI(&PController, contextMenuPosition);
        InventoryUI InventoryUI(PController, Player, windowSize, 50);

        //Enemies
        auto Chick = std::make_unique<EnemyCharacter>(windowSize.x / 3, windowSize.y / 3, 2, 50.0f, 100.f, EnemyType::Chick);
        EnemyCharacter* ChickPtr = Chick.get();
        gameMap.AddEnemy(std::move(Chick));

        auto Cow = std::make_unique<EnemyCharacter>(windowSize.x / 4, windowSize.y / 3, 2, 50.0f, 100.f, EnemyType::Cow);
        EnemyCharacter* CowPtr = Cow.get();
        gameMap.AddEnemy(std::move(Cow));

        sf::Clock dtClock;
        while (window.isOpen())
        {
            while (const std::optional<sf::Event>& event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (PController.IsContextMenuOpen())
                    ActionContextMenuUI.HandleEvent(*event, &window);

                PController.HandleEvent(*event, grassBounds, &window);
                InventoryUI.HandleEvent(*event, &window);
            }

            sf::Time dt = dtClock.restart();
            Player.Update(dt);
            ChickPtr->Update(dt);
            ChickPtr->UpdateSprite(dt);

            CowPtr->Update(dt);
            CowPtr->UpdateSprite(dt);

            Player.UpdateSprite(dt);
            PController.Update(dt);
            ActionQueueUI.Update(dt);
            InventoryUI.Update(dt);

            window.clear(sf::Color::Blue);
            window.draw(backgroundSprite); 

            gameMap.DisplayObjects(window);
            Player.Draw(window);
            ChickPtr->Draw(window);
            CowPtr->Draw(window);

            ActionQueueUI.Draw(window);
            ActionContextMenuUI.Draw(window);
            InventoryUI.Draw(window);

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
