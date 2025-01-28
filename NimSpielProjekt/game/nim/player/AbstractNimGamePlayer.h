//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once
#include "../../player/AbstractPlayer.h"
namespace atlas::game::nim::player {

    class AbstractNimGamePlayer: public  atlas::game::player::AbstractPlayer<int, int>{
    public:
        explicit AbstractNimGamePlayer(const std::string &name) : AbstractPlayer(name){}






    };

} // game
