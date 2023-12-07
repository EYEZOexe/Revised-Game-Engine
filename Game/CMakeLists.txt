add_executable(${GAME_TARGET_NAME} # Adds the executable for the game
        ${CMAKE_CURRENT_SOURCE_DIR}/include/GameFramework/GameApplication.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameFramework/GameApplication.cpp
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