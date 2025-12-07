#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#include "Base/Character.h"
#include "Game/GameMap.h"
#include "Player/PlayerCharacter.h"
#include "Player/PlayerController.h"
#include "UI/PlayerUI/MovementQueueUI.h"
#include "UI/PlayerUI/InventoryUI.h"
#include "UI/PlayerUI/HealthBar.h"

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

        //Create UI
        sf::Vector2f healthPos(1, 1);
        sf::Vector2f healthSize(1, 1);
        /*HealthBar HealthBar(healthPos, healthSize, windowSize, Player);

        MovementQueueUI MovementQueueUI(PController, windowSize, 5, 7, "Movement Queue");
        InventoryUI InventoryUI(PController, windowSize, 5, 7, MovementQueueUI.GetPanelSize().y, "Inventory");*/

        sf::Clock dtClock;
        while (window.isOpen())
        {
            while (const std::optional<sf::Event>& event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                PController.HandleEvent(*event, grassBounds, &window);
            }

            sf::Time dt = dtClock.restart();
            Player.Update(dt);
            Player.UpdateSprite(dt);

            PController.Update(dt);

            /*MovementQueueUI.Update(dt);
            InventoryUI.Update(dt);*/

            window.clear(sf::Color::Blue);
            window.draw(backgroundSprite); 

            gameMap.DisplayObjects(window);
            /*MovementQueueUI.Draw(window);
            InventoryUI.Draw(window);
            HealthBar.Draw(window);*/
            Player.Draw(window);

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
