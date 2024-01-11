#include <iostream>

#include "game.h"

int main()
{
    game* pGame = new game();

    pGame->gameloop();

    delete pGame;

    return 0;
}
