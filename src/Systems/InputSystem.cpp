#include "InputSystem.h"

#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"
#include "SDL.h"

InputSystem::InputSystem(EntityManager& entityManager,ComponentManager& componentManager)
: m_EntityManager(entityManager)
, m_ComponentManager(componentManager)
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


