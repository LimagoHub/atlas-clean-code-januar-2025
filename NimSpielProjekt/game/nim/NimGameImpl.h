//
// Created by JoachimWagner on 27.01.2025.
//

#pragma once
#include <stdexcept>
#include <vector>
#include "../Game.h"
#include "../player/Player.h"
#include "../../io/Writer.h"
#include "../AbstractGame.h"

namespace atlas::game::nim {



    class NimGameImpl: public AbstractGame<int, int> {


    public:
        explicit NimGameImpl(io::Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }




        // Implementierungssumpf ---------------------------------------------------------
    protected:
        void updateBoard() override { setBoard(getBoard() - getTurn());  }

        bool isGameOver() const override{
            return getBoard() < 1 || getPlayers().empty();
        }
        bool isTurnValid() const override{ return getTurn() >= 1 && getTurn() <= 3; }


    };



} // game
