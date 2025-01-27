//
// Created by JoachimWagner on 27.01.2025.
//

#pragma once

namespace atlas::game {

    class Game {

    public:
        virtual ~Game() = default;
        virtual void play() = 0;
    };

} // game
