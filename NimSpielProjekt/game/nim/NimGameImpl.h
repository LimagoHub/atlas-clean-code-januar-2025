//
// Created by JoachimWagner on 27.01.2025.
//

#pragma once
#include "../Game.h"
namespace atlas::game::nim {

    class NimGameImpl: public Game {

    public:
        NimGameImpl():stones{23} {}

        void play() override {
            while( ! isGameOver()) {
                playRound();
            }
        }

    private:
        void playRound() {
            humanturn();
            computerturn();
        }
        void humanturn() {
            int turn;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
                std::cin >> turn;
                if(turn >= 1 && turn <= 3) break;
                std::cout << "Ungueltiger Zug" << std::endl;
            }
            stones -= turn;
        }

        void computerturn() {

            constexpr int turns[] = {3,1,1,2};
            if(isGameOver()) {
                std::cout << "Du Loser" << std::endl;
                return;
            }

            if(stones == 1) {
                --stones;
                std::cout << "Du hast nur Glueck gehabt" << std::endl;
                return ;
            }

            const int turn = turns[stones%4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            stones -= turn;

        }

        bool isGameOver() {
            return stones < 1;
        }

        int stones;

    };



} // game
