cmake_minimum_required(VERSION 3.27)

project(GameEngine
        VERSION 1.0.0 # version of project 3rd number is patch/bugfix 2nd is minor but new features that wouldnt cause anything to break 1st is major changes that would break things
        LANGUAGES C CXX # Languages used in project
)

set(CMAKE_CXX_STANDARD          23) # Sets the C++ standard to C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Sets the C++ standard to required
set(CMAKE_CXX_EXTENSIONS       OFF) # Sets the C++ extensions to off

set(GAME_ENGINE_TARGET_NAME GameEngine) # Sets the target name for the game
set(GAME_TARGET_NAME Game) # Sets the target name for the game

add_subdirectory(GameEngine) # Adds the GameEngine directory to the project
add_subdirectory(Game) # Adds the Game directory to the project

