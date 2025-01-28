//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace atlas::game::nim::player  {

    class ComputerPlayer: public AbstractNimGamePlayer{
        static inline constexpr int turns[] = {3,1,1,2};
    public:
        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int doTurn(const int &stones) const override {
            const int turn = turns[stones%4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            return turn;
        }
    };

} // game
