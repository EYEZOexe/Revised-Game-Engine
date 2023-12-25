add_library(${GAME_ENGINE_TARGET_NAME} STATIC # Creates the game target
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/World.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/World.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/Actor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/Actor.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/Object.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/Object.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/AssetManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/AssetManager.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/MathUtility.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/MathUtility.h

        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/PhysicsSystem.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/PhysicsSystem.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/EventCallback.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/EventCallback.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthVFX/Particle.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthVFX/Particle.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/TimeManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/TimeManager.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthFramework/Core.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthFramework/Core.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Gameplay/GameStage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Gameplay/GameStage.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Gameplay/WaitStage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Gameplay/WaitStage.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/HUD.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/HUD.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Widget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/Widget.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/TextWidget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/TextWidget.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/StatusMeter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/StatusMeter.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/ImageWidget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/ImageWidget.h

        ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${GAME_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Adds the include directory to the engine target

include(FetchContent) # Includes the FetchContent module
set(SFML_LIB_NAME SFML)

FetchContent_Declare( # Declares the SFML library
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG        2.6.0
        GIT_SHALLOW    FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME}) # Makes the SFML library available

target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-graphics) # Links the SFML graphics library to the engine target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-window) # Links the SFML window library to the engine target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-system) # Links the SFML system library to the engine target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-audio) # Links the SFML audio library to the engine target

set(BOX2D_LIB_NAME Box2D) # Sets the Box2D library name
FetchContent_Declare(
        ${BOX2D_LIB_NAME}
        GIT_REPOSITORY https://github.com/erincatto/box2d
        GIT_TAG        v2.4.1
        GIT_SHALLOW    FALSE
)

FetchContent_MakeAvailable(${BOX2D_LIB_NAME}) # Makes the Box2D library available

target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC box2d) # Links the Box2D library to the engine target

function(CopyLibrariesToTarget LIB_NAME TARGET_NAME) # Copies the SFML libraries to the engine target
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibrariesToTarget(sfml-graphics ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML graphics library to the engine target
CopyLibrariesToTarget(sfml-window ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML window library to the engine target
CopyLibrariesToTarget(sfml-system ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML system library to the engine target
CopyLibrariesToTarget(sfml-audio ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML audio library to the engine target
CopyLibrariesToTarget(box2d ${GAME_ENGINE_TARGET_NAME}) # Copies the Box2D library to the engine target

