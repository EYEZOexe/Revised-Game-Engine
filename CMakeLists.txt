cmake_minimum_required(VERSION 3.27)

project(UdemyYears
        VERSION 1.0.0 # version of project 3rd number is patch/bugfix 2nd is minor but new features that wouldnt cause anything to break 1st is major changes that would break things
        LANGUAGES C CXX # Languages used in project
)

set(CMAKE_CXX_STANDARD          23) # Sets the C++ standard to C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Sets the C++ standard to required
set(CMAKE_CXX_EXTENSIONS       OFF) # Sets the C++ extensions to off

include(FetchContent) # Includes the FetchContent module
set(SFML_LIB_NAME SFML)

FetchContent_Declare( # Declares the SFML library
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG        2.6.0
        GIT_SHALLOW    FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME}) # Makes the SFML library available

set(UDEMY_YEARS_GAME_TARGET_NAME Game) # Sets the target name for the game

add_subdirectory(UdemyYears) # Adds the UdemyYears directory to the project

