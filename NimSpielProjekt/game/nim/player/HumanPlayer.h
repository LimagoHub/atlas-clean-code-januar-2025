//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace atlas::game::nim::player  {

    class HumanPlayer: public AbstractNimGamePlayer{

    public:
        explicit HumanPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}




        int doTurn(const int &stones) const override {
            int result;
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
            std::cin >> result;
            return result;
        }
    };

} // game
