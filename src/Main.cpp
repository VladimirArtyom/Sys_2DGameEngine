#include <iostream>
#include "Game.h"
int main(int argc, char* argv[]) {
    Game game = Game();
    game.Initialize();
    game.Run();
    game.Destroy();
    // TODO: Do shit   
    return 0;
}


