//
// Created by JoachimWagner on 27.01.2025.
//

#pragma once
#include "../game/Game.h"

namespace client {

    using MyGame = atlas::game::Game;

    class GameClient {
        MyGame &_game;

    public:
        explicit GameClient(MyGame &game) : _game(game) {}
        void go() {
            _game.play();
        }
    };

} // client
