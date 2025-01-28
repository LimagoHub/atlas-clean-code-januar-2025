//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <vector>
#include <stdexcept>
#include "Game.h"
#include "player/Player.h"
#include "../io/Writer.h"

namespace atlas::game {

    template<class BOARD, class TURN>
    class AbstractGame: public Game {
        using Player = atlas::game::player::Player<BOARD, TURN>*;
        using Players = std::vector<Player>;
    public:

        explicit AbstractGame(io::Writer &writer) : writer(writer) {}

        void addPlayer(Player player) {
            players.push_back(player);
        }
        void removePlayer(Player player) {
            throw std::logic_error("Not implemented yet");
        }
        void play() override {
            while( ! isGameOver()) {

                playRound();
            }
        }


    private:
        void playRound() {
            for (auto player : players) {
                setCurrentPlayer(player);
                playSingleTurn();
            }
        }

        void playSingleTurn() {
            if(isGameOver()) return;
            executePlayersTurn();
            terminateTurn( );
        }

        void executePlayersTurn()  {

            do {
                turn =getCurrentPlayer()->doTurn(board);
            } while(turnIsNotValid());
        }


        void terminateTurn( ) {// Integration
            updateBoard();
            printMessageIfGameIsOver();
        }

        bool turnIsNotValid() {
            if(isTurnValid()) return false;
            write("Ungueltiger Zug");
            return true;
        }

        void printMessageIfGameIsOver()  { // Operation
            if(isGameOver()) {
                write(getCurrentPlayer()->getName() + " hat verloren");

            }
        }

        void setCurrentPlayer(Player currentPlayer) {
            AbstractGame::currentPlayer = currentPlayer;
        }

        io::Writer &writer;

        Players players;
        Player currentPlayer;
        BOARD board;
        TURN turn;




    protected:


        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            AbstractGame::board = board;
        }

        TURN getTurn() const {
            return turn;
        }

        void setTurn(TURN turn) {
            AbstractGame::turn = turn;
        }


        const Players &getPlayers() const {
            return players;
        }




        void write(std::string message) {
            writer.write(message);
        }
        [[nodiscard]]
        Player getCurrentPlayer() const {
            return currentPlayer;
        }
        [[nodiscard]]
        virtual bool isGameOver() const = 0;
        virtual void updateBoard() = 0;
        [[nodiscard]]
        virtual bool isTurnValid() const = 0;
    };

} // game
