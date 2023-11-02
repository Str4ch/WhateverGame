cmake_minimum_required(VERSION 3.5)

project(WhateverGame LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(WG main.cpp Player.hpp Player.cpp Map.hpp Map.cpp Room.cpp Room.hpp globalvariables.hpp globalvariables.cpp Door.cpp Door.hpp Enemy.cpp Enemy.hpp Weapon.cpp Weapon.hpp Chest.cpp Chest.hpp)
target_link_libraries(WG PRIVATE sfml-graphics sfml-network sfml-audio)
target_compile_features(WG PRIVATE cxx_std_17)

install(TARGETS WG)