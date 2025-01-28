//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"
#include "time.h"
#include <cstdlib>

namespace atlas::game::nim::player  {

    class OmaPlayer: public AbstractNimGamePlayer{

    public:
        explicit OmaPlayer(const std::string &name) : AbstractNimGamePlayer(name) {
            std::srand(time(nullptr));
        }




        [[nodiscard]]
        int doTurn(const int &stones) const override {
            const int result = std::rand() % 6;
            std::cout << "Oma nimmt " << result << " Steine." << std::endl;

            return result;
        }
    };

} // game
