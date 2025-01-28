#include <iostream>
#include "client/GameClient.h"
#include "game/nim/NimGameImpl.h"
#include "game/nim/player/HumanPlayer.h"
#include "game/nim/player/ComputerPlayer.h"
#include "io/ConsoleWriter.h"

using MyGame = atlas::game::nim::NimGameImpl;
using MyClient = client::GameClient;
using HumanPlayer = atlas::game::nim::player::HumanPlayer;
using ComputerPlayer = atlas::game::nim::player::ComputerPlayer;
int main() {

    io::ConsoleWriter writer;
    HumanPlayer mensch{"Mensch"};
    ComputerPlayer computer{"Computer"};

    MyGame game{writer};
    game.addPlayer(&mensch);
    game.addPlayer(&computer);

    MyClient client{game};
    client.go();

    return 0;
}
