add_library(${GAME_ENGINE_TARGET_NAME} STATIC # Creates the game target
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/World.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/World.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/Actor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/Actor.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/Object.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/Object.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/AssetManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/AssetManager.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/MathUtility.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/MathUtility.h

        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/PhysicsSystem.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/PhysicsSystem.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/EventCallback.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/EventCallback.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/LabyrinthEngine/Core.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LabyrinthEngine/Core.h

        ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp


)

target_include_directories(${GAME_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Adds the include directory to the game target

include(FetchContent) # Includes the FetchContent module
set(SFML_LIB_NAME SFML)

FetchContent_Declare( # Declares the SFML library
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG        2.6.0
        GIT_SHALLOW    FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME}) # Makes the SFML library available

target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-graphics) # Links the SFML graphics library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-window) # Links the SFML window library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-system) # Links the SFML system library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-audio) # Links the SFML audio library to the game target

set(BOX2D_LIB_NAME Box2D) # Sets the Box2D library name
FetchContent_Declare(
        ${BOX2D_LIB_NAME}
        GIT_REPOSITORY https://github.com/erincatto/box2d
        GIT_TAG        v2.4.1
        GIT_SHALLOW    FALSE
)

FetchContent_MakeAvailable(${BOX2D_LIB_NAME}) # Makes the Box2D library available

target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC box2d) # Links the Box2D library to the game target

function(CopyLibrariesToTarget LIB_NAME TARGET_NAME) # Copies the SFML libraries to the game target
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibrariesToTarget(sfml-graphics ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML graphics library to the game target
CopyLibrariesToTarget(sfml-window ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML window library to the game target
CopyLibrariesToTarget(sfml-system ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML system library to the game target
CopyLibrariesToTarget(sfml-audio ${GAME_ENGINE_TARGET_NAME}) # Copies the SFML audio library to the game target
CopyLibrariesToTarget(box2d ${GAME_ENGINE_TARGET_NAME}) # Copies the Box2D library to the game target

