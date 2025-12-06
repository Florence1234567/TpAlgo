#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#include "Base/Character.h"
#include "Game/GameMap.h"
#include "Player/PlayerCharacter.h"
#include "Player/PlayerController.h"
#include "UI/PlayerUI/MovementQueueUI.h"
//#include "UI/InventoryUI.h"

int main() {
    sf::Vector2u windowSize(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Le meilleur jeu");
    window.setFramerateLimit(120);

    try
    {
        GameMap GameMap(windowSize.x, windowSize.y);

        sf::RenderTexture backgroundTexture(sf::Vector2u(windowSize.x, windowSize.y));
        backgroundTexture.clear(sf::Color::Transparent); 
        GameMap.Display(backgroundTexture);               
        backgroundTexture.display();
        sf::Sprite backgroundSprite(backgroundTexture.getTexture());

        sf::FloatRect grassBounds = GameMap.GetGrassBounds();

        //Create player
        PlayerCharacter Player(windowSize.x / 2, windowSize.y / 2, 2, 50.0f, 100.f);
        PlayerController PController(&Player);

        MovementQueueUI MovementQueueUI(PController, windowSize, 10, 5, "Player Movement Queue");

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

            MovementQueueUI.Update(dt);

            window.clear(sf::Color::Blue);
            window.draw(backgroundSprite); 

            //GameMap.DisplayObjects(window);
            MovementQueueUI.Draw(window);
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
