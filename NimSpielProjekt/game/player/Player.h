//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <string>

namespace atlas::game::player {

    template<class BOARD, class TURN>
    class Player {
    public:
        virtual ~Player() = default;

        virtual std::string getName()  = 0;


        virtual TURN doTurn(const BOARD &board) const= 0;
    };

} // game
