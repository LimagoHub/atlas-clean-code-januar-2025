cmake_minimum_required(VERSION 3.17)
project(NimSpielProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimSpielProjekt main.cpp
        game/Game.h
        client/GameClient.h
        game/nim/NimGameImpl.h
        game/nim/player/AbstractNimGamePlayer.h
        game/nim/player/HumanPlayer.h
        io/Writer.h
        io/ConsoleWriter.h
        game/player/Player.h
        game/AbstractGame.h
)
