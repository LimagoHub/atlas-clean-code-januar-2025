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
            playSingleTurn();
            computerturn();
        }

        void playSingleTurn() {
            if(isGameOver()) return;
            executePlayersTurn();
            terminateTurn( "Mensch");
        }



        void executePlayersTurn()  {

            do {
                humanturnToDelete();
            } while(turnIsNotValid());
        }

        bool turnIsNotValid() {
            if(isTurnValid()) return false;
            std::cout << "Ungueltiger Zug" << std::endl;
            return true;
        }


        void humanturnToDelete()  {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
            std::cin >> turn;
        }


        void computerturn() {

            if(isGameOver()) return;

            constexpr int turns[] = {3,1,1,2};

            turn = turns[stones%4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            terminateTurn( "Computer");

        }

        void terminateTurn( std::string player) {// Integration
            updateBoard();
            printMessageIfGameIsOver(player);
        }

        void printMessageIfGameIsOver(const std::string &player) { // Operation
            if(isGameOver()) {
                std::cout << player << " hat verloren" << std::endl;
            }
        }


        // Implementierungssumpf ---------------------------------------------------------

        void updateBoard() { stones -= turn; }

        bool isGameOver() {
            return stones < 1;
        }
        bool isTurnValid() const { return turn >= 1 && turn <= 3; }

        int stones;
        int turn;
    };



} // game
