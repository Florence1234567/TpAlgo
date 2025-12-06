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
        src/Base/Object.cpp
        src/Base/Object.h
        src/Base/Character.cpp
        src/Base/Character.h
        src/Base/Controller.cpp
        src/Base/Controller.h
        src/Game/GameManager.cpp
        src/Game/GameManager.h
        src/UI/PlayerUI/PlayerUIComponent.cpp
        src/UI/PlayerUI/PlayerUIComponent.h
        src/UI/PlayerUI/InventoryUI.cpp
        src/UI/PlayerUI/InventoryUI.h
        src/UI/PlayerUI/MovementQueueUI.cpp
        src/UI/PlayerUI/MovementQueueUI.h
        src/Player/PlayerCharacter.cpp
        src/Player/PlayerCharacter.h
        src/Player/PlayerController.cpp
        src/Player/PlayerController.h
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
)
target_compile_features(TPAlgo PRIVATE cxx_std_17)
target_link_libraries(TPAlgo PRIVATE SFML::Graphics)

# Copy Assets folder to output directory
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
