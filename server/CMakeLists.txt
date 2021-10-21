
find_package(SFML 2 REQUIRED network)
find_package(SQLite3 REQUIRED)

set(SOURCES
        src/Main.cpp
        src/Server.cpp

        src/AI/AI.cpp

        src/Entities/Entity.cpp

        src/Map/Map.cpp
        src/Map/MapManager.cpp

        src/Networking/NetworkManager.cpp

        src/Objects/ObjectManager.cpp

        src/Players/LoginServer.cpp
        src/Players/Player.cpp
        src/Players/PlayerManager.cpp

        src/Utilities/Database.cpp
        src/Utilities/Logging.cpp
        src/Utilities/Timing.cpp
        )

add_executable(mmorpg-server ${SOURCES})

target_link_libraries(mmorpg-server sfml-network sqlite3)

target_include_directories(mmorpg-server PRIVATE include)

add_custom_command(TARGET mmorpg-server POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/res" "${CMAKE_CURRENT_BINARY_DIR}/res")