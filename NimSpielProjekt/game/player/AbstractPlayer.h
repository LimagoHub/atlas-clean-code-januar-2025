//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once
#include "Player.h"
namespace atlas::game::player {

    template<class BOARD, class TURN>
    class AbstractPlayer: public Player<BOARD, TURN> {

    private:
        std::string name;

    public:
        explicit AbstractPlayer(const std::string &name) : name(name) {}

        std::string getName()   override {
            return name;
        }
    };

} // game
