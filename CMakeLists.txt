cmake_minimum_required(VERSION 4.0)
project(TpAlgo LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(TPAlgo
        src/main.cpp
        src/Game/GameMap.cpp
        src/Objects/Object.cpp
        src/Objects/Object.h
        src/Objects/Character.cpp
        src/Objects/Character.h
        src/Objects/Controller.cpp
        src/Objects/Controller.h
        src/Objects/GameObjects/GameObject.cpp
        src/Objects/GameObjects/GameObject.h
        src/UI/PlayerUI/PlayerUIComponent.cpp
        src/UI/PlayerUI/PlayerUIComponent.h
        src/UI/PlayerUI/InventoryUI.cpp
        src/UI/PlayerUI/InventoryUI.h
        src/UI/PlayerUI/ActionQueueUI.cpp
        src/UI/PlayerUI/ActionQueueUI.h
        src/Objects/Player/PlayerCharacter.cpp
        src/Objects/Player/PlayerCharacter.h
        src/Objects/Player/PlayerController.cpp
        src/Objects/Player/PlayerController.h
        src/Actions/Action.cpp
        src/Actions/Action.h
        src/DataStructures/Queue/ActionQueue.cpp
        src/DataStructures/Queue/ActionQueue.h
        src/DataStructures/LinkedLists/DLinkedList.hpp
        src/DataStructures/LinkedLists/DNode.hpp
        src/Actions/MoveAction.cpp
        src/Actions/MoveAction.h
        src/Actions/WaitAction.cpp
        src/Actions/WaitAction.h
        src/UI/UIComponent.cpp
        src/UI/UIComponent.h
        src/Actions/AttackAction.cpp
        src/Actions/AttackAction.h
        src/UI/PlayerUI/ActionContextMenuUI.cpp
        src/UI/PlayerUI/ActionContextMenuUI.h
        src/Actions/LootAction.cpp
        src/Actions/LootAction.h
        src/Objects/Items/Item.cpp
        src/Objects/Items/Item.h
        src/Objects/Items/PotionItem.cpp
        src/Objects/Items/PotionItem.h
        src/Objects/Items/Potions/HealthPotion.h
        src/Objects/Items/Potions/DamagePotion.cpp
        src/Objects/Items/Potions/DamagePotion.h
        src/Objects/Items/Potions/SpeedPotion.cpp
        src/Objects/Items/Potions/SpeedPotion.h
        src/Objects/Items/Potions/HealthPotion.cpp
        src/Objects/Enemy/EnemyCharacter.cpp
        src/Objects/Enemy/EnemyCharacter.h
        src/Objects/NPC/NPCCharacter.cpp
        src/Objects/NPC/NPCCharacter.h
        src/UI/PlayerUI/HealthBar.cpp
        src/UI/PlayerUI/HealthBar.h
        src/Actions/InteractAction.cpp
        src/Actions/InteractAction.h
        src/UI/DialogUI.cpp
        src/UI/DialogUI.h
        )
target_compile_features(TPAlgo PRIVATE cxx_std_17)
target_link_libraries(TPAlgo PRIVATE SFML::Graphics)

# Copy Assets folder to output directory
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
