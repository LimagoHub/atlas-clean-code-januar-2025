#include <iostream>
#include "client/GameClient.h"
#include "game/nim/NimGameImpl.h"
#include "game/nim/player/HumanPlayer.h"
#include "game/nim/player/ComputerPlayer.h"
#include "game/nim/player/OmaPlayer.h"
#include "io/ConsoleWriter.h"

using MyGame = atlas::game::nim::NimGameImpl;
using MyClient = client::GameClient;
using HumanPlayer = atlas::game::nim::player::HumanPlayer;
using ComputerPlayer = atlas::game::nim::player::ComputerPlayer;
using OmaPlayer = atlas::game::nim::player::OmaPlayer;
int main() {

    io::ConsoleWriter writer;
    HumanPlayer mensch{"Mensch"};
    ComputerPlayer computer{"Computer"};
    OmaPlayer oma{"Oma"};

    MyGame game{writer};
    game.addPlayer(&mensch);
    game.addPlayer(&oma);
    game.addPlayer(&computer);

    MyClient client{game};
    client.go();

    return 0;
}
