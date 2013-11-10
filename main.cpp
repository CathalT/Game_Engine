#include "GameLoop/GameLoop.h"
#include "GameWorld/EntityManager.h"
#include "GameWorld/ComponentManager.h"
#include <iostream>
#include <vector>
#include "SDL.h"

int main( int argc, char* argv[] )
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    EntityManager entityManager;
    ComponentManager componentManager;
    GameLoop gameLoop = GameLoop(entityManager,componentManager);
    gameLoop.RunLoop();
}
