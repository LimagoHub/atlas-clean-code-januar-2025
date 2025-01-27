cmake_minimum_required(VERSION 3.17)
project(NimSpielProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimSpielProjekt main.cpp
        game/Game.h
        client/GameClient.h
        game/nim/NimGameImpl.h
)
