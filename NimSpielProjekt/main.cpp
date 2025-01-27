#include <iostream>
#include "client/GameClient.h"
#include "game/nim/NimGameImpl.h"

using MyGame = atlas::game::nim::NimGameImpl;
using MyClient = client::GameClient;

int main() {

    MyGame game;
    MyClient client{game};
    client.go();

    return 0;
}
