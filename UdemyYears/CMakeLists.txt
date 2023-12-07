add_executable(${UDEMY_YEARS_GAME_TARGET_NAME} # Adds the executable for the game
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Framework/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Application.cpp
)

target_include_directories(${UDEMY_YEARS_GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Adds the include directory to the game target

target_link_libraries(${UDEMY_YEARS_GAME_TARGET_NAME} PUBLIC sfml-graphics) # Links the SFML graphics library to the game target
target_link_libraries(${UDEMY_YEARS_GAME_TARGET_NAME} PUBLIC sfml-window) # Links the SFML window library to the game target
target_link_libraries(${UDEMY_YEARS_GAME_TARGET_NAME} PUBLIC sfml-system) # Links the SFML system library to the game target
target_link_libraries(${UDEMY_YEARS_GAME_TARGET_NAME} PUBLIC sfml-audio) # Links the SFML audio library to the game target

function(CopyLibrariesToTarget LIB_NAME TARGET_NAME) # Copies the SFML libraries to the game target
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibrariesToTarget(sfml-graphics ${UDEMY_YEARS_GAME_TARGET_NAME}) # Copies the SFML graphics library to the game target
CopyLibrariesToTarget(sfml-window ${UDEMY_YEARS_GAME_TARGET_NAME}) # Copies the SFML window library to the game target
CopyLibrariesToTarget(sfml-system ${UDEMY_YEARS_GAME_TARGET_NAME}) # Copies the SFML system library to the game target
CopyLibrariesToTarget(sfml-audio ${UDEMY_YEARS_GAME_TARGET_NAME}) # Copies the SFML audio library to the game target