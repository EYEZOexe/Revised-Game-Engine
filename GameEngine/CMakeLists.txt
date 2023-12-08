add_library(${GAME_ENGINE_TARGET_NAME} STATIC # Creates the game target
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/World.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/World.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Actor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/Actor.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Object.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/Object.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/AssetManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/AssetManager.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/MathUtility.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/MathUtility.h

        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Core.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/Core.h

        ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp

)

target_include_directories(${GAME_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Adds the include directory to the game target

target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-graphics) # Links the SFML graphics library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-window) # Links the SFML window library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-system) # Links the SFML system library to the game target
target_link_libraries(${GAME_ENGINE_TARGET_NAME} PUBLIC sfml-audio) # Links the SFML audio library to the game target

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