#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#include "Objects/Character.h"
#include "Game/GameMap.h"
#include "Objects/Player/PlayerCharacter.h"
#include "Objects/Player/PlayerController.h"
#include "UI/PlayerUI/ActionQueueUI.h"
#include "UI/PlayerUI/ActionContextMenuUI.h"
#include "UI/PlayerUI/InventoryUI.h"
#include "UI/PlayerUI/HealthBar.h"
#include "Objects/Enemy/EnemyCharacter.h"

struct GameSession
{
    GameMap gameMap;

    sf::RenderTexture backgroundTexture;
    sf::FloatRect grassBounds;

    DialogUI dialogUI;

    PlayerCharacter player;
    PlayerController playerController;

    ActionQueueUI actionQueueUI;
    ActionContextMenuUI contextMenuUI;
    InventoryUI inventoryUI;
    HealthBar healthBar;

    std::unique_ptr<NPCCharacter> foxNPC;
    NPCCharacter* foxNPCPtr;

    std::vector<EnemyCharacter*> enemies;

    GameSession(sf::Vector2u windowSize, sf::RenderWindow& window)
        : gameMap(windowSize.x, windowSize.y),
          backgroundTexture(sf::Vector2u(windowSize.x, windowSize.y)),
          dialogUI(sf::Vector2f(200.f, 20.f)),
          player(windowSize.x / 2, windowSize.y / 2, 2, &dialogUI),
          playerController(&player, &gameMap),
          actionQueueUI(playerController, windowSize, 50),
          contextMenuUI(&playerController, sf::Vector2f(
              actionQueueUI.getPosition().x,
              actionQueueUI.getPosition().y + actionQueueUI.getPanelSize().y)),
          inventoryUI(playerController, player, windowSize, 50),
          healthBar({ 70.f, 30.f }, { 200.f, 20.f }, windowSize, player)
    {
        // Background
        backgroundTexture.clear(sf::Color::Transparent);
        gameMap.Display(backgroundTexture);
        backgroundTexture.display();

        grassBounds = gameMap.GetFenceBounds();

        // NPCs
        foxNPC = std::make_unique<NPCCharacter>(
            windowSize.x / 3, windowSize.y / 2, 2,
            NPCTypes::Fox, "Fox", &dialogUI);
        foxNPCPtr = foxNPC.get();
        gameMap.AddNPC(std::move(foxNPC));

        // Enemies
        enemies = gameMap.GetEnemies();
    }
};

int main() {
    sf::Vector2u windowSize(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Bunny adventure");
    window.setFramerateLimit(120);

    try
    {
        GameSession* session = new GameSession(windowSize, window);
        sf::Sprite backgroundSprite = sf::Sprite(session->backgroundTexture.getTexture());

        sf::Clock dtClock;
        while (window.isOpen())
        {
            bool resetRequested = false;

            while (const std::optional<sf::Event>& event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                    if (key->scancode == sf::Keyboard::Scan::R) {
                        resetRequested = true;
                        break;
                    }
                }

                if (session->playerController.IsContextMenuOpen())
                    session->contextMenuUI.HandleEvent(*event, &window);

                session->playerController.HandleEvent(*event, session->grassBounds, &window);
                session->inventoryUI.HandleEvent(*event, &window);
            }

            if (!window.isOpen())
                break;

            if (!session->player.isAlive())
                resetRequested = true;

            if (resetRequested) {
                delete session;
                session = new GameSession(windowSize, window);
                backgroundSprite = sf::Sprite(session->backgroundTexture.getTexture());
                dtClock.restart();
                continue;
            }

            // Update
            sf::Time dt = dtClock.restart();
            session->player.Update(dt);

            // NPCs
            session->foxNPCPtr->Update(dt);
            session->foxNPCPtr->UpdateSprite(dt);

            // Enemy
            for (auto* enemy : session->enemies) {
                enemy->Update(dt);
                enemy->UpdateSprite(dt);
            }

            session->player.UpdateSprite(dt);
            session->playerController.Update(dt);
            session->actionQueueUI.Update(dt);
            session->inventoryUI.Update(dt);
            session->healthBar.Update(dt);
            session->dialogUI.Update(dt);
            
            // Draw
            window.clear(sf::Color::Blue);
            window.draw(backgroundSprite);

            session->gameMap.DisplayObjects(window);
            session->foxNPCPtr->Draw(window);

            for (auto* enemy : session->enemies)
                enemy->Draw(window);

            session->player.Draw(window);

            session->actionQueueUI.Draw(window);
            session->inventoryUI.Draw(window);
            session->contextMenuUI.Draw(window);
            session->healthBar.Draw(window);
            session->dialogUI.Draw(window);

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
