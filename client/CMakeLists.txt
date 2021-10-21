
find_package(SFML 2 REQUIRED graphics network)

set(SOURCES
        src/Main.cpp
        src/Engine.cpp

        src/Entity/Entity.cpp

        src/Gamestates/Gamestate.cpp
        src/Gamestates/GamestateGameplay.cpp
        src/Gamestates/GamestateInitialise.cpp
        src/Gamestates/GamestateLogin.cpp
        src/Gamestates/GamestateMenu.cpp

        src/Managers/EntityManager.cpp
        src/Managers/NetworkManager.cpp
        src/Managers/ResourceManager.cpp
        src/Managers/StateManager.cpp
        src/Managers/UIManager.cpp
        src/Managers/WindowManager.cpp

        src/Map/Level.cpp
        src/Map/NavMesh.cpp

        src/UIElements/UIButton.cpp
        src/UIElements/UIElement.cpp
        src/UIElements/UIImage.cpp
        src/UIElements/UITextField.cpp

        src/Utilities/Crypto.cpp
        src/Utilities/Timing.cpp
        )

add_executable(mmorpg-client ${SOURCES})

target_link_libraries(mmorpg-client sfml-graphics sfml-network)

target_include_directories(mmorpg-client PRIVATE include)

add_custom_command(TARGET mmorpg-client POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/res" "${CMAKE_CURRENT_BINARY_DIR}/res")