#include "InputSystem.h"
#include "SDL.h"

InputSystem::InputSystem(EntityManager& entityManager,ComponentStore& componentStore)
: m_EntityManager(entityManager)
, m_ComponentStore(componentStore)
{
    //ctor
}

InputSystem::~InputSystem()
{
    //dtor
}

bool InputSystem::ProcessAllUserInput()
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )
        {
            SetIsExitClicked(true);
        }
    }
    ProcessKeyPresses();
    //ProcessMouseClicks();
    //ProcessMouseMotion();
    return GetIsExitClicked();
}

void InputSystem::ProcessKeyPresses()
{

}

bool InputSystem::GetIsExitClicked()
{
    return m_bExitGame;
}

void InputSystem::SetIsExitClicked(bool update)
{
    m_bExitGame = update;
}


