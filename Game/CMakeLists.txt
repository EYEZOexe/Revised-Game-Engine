add_executable(${GAME_TARGET_NAME} # Adds the executable for the game
        ${CMAKE_CURRENT_SOURCE_DIR}/include/GameName/GameApplication.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameFramework/GameApplication.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Spaceship/Spaceship.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Spaceship/Spaceship.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Player/PlayerSpaceship.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Player/PlayerSpaceship.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Weapon/Launcher.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Weapon/Launcher.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Weapon/ProjectileLauncher.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Weapon/ProjectileLauncher.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Weapon/Projectile.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Weapon/Projectile.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Gameplay/HealthComponent.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Gameplay/HealthComponent.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/VFX/Explosion.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/VFX/Explosion.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/EnemySpaceship.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/EnemySpaceship.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/Vanguard.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/Vanguard.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/VanguardGameStage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/VanguardGameStage.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/TwinBlade.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/TwinBlade.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/TwinBladeGameStage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/TwinBladeGameStage.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/Hexagon.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/Hexagon.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Level/GameLevelOne.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Level/GameLevelOne.h

)

target_include_directories(${GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Adds the include directory to the game target

target_link_libraries(${GAME_TARGET_NAME} PUBLIC ${GAME_ENGINE_TARGET_NAME}) # Links the SFML graphics library to the game target

function(CopyLibrariesDirectoryToTarget LIB_NAME TARGET_NAME) # Copies the SFML libraries to the game target
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            $<TARGET_FILE_DIR:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibrariesDirectoryToTarget(${GAME_ENGINE_TARGET_NAME} ${GAME_TARGET_NAME}) # Copies the SFML graphics library to the game target

set(ASSET_FOLDER_NAME "assets") # Sets the name of the asset folder
set(ASSET_FOLDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${ASSET_FOLDER_NAME}") # Sets the path of the asset folder

add_custom_command(
        TARGET ${GAME_TARGET_NAME} POST_BUILD # Copies the asset folder to the game target
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ASSET_FOLDER_PATH}
        $<TARGET_FILE_DIR:${GAME_TARGET_NAME}>/${ASSET_FOLDER_NAME}
)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/config.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES # Configures the config.h file
)