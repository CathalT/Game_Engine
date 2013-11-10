#include "GameLoop.h"


#include "Systems/RenderSystem.h"
#include "Systems/InputSystem.h"

#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"
#include "GameWorld/GameWorld.h"

#include <boost/chrono.hpp>
#include <iostream>

const double FPS = 60.0;
const double ONE_THOUSAND_MILLISECS = 1000.0;

GameLoop::GameLoop(EntityManager& entityManager, ComponentManager& componentManager)
: m_bExit(false)
, m_InputSystem(entityManager,componentManager)
, m_GameWorld(entityManager,componentManager)
, m_RenderSystem(entityManager,componentManager)
{
    //ctor
}

GameLoop::~GameLoop()
{
    //dtor
}

void GameLoop::RunLoop()
{
    boost::chrono::high_resolution_clock::time_point previous = boost::chrono::high_resolution_clock::now();
    double MS_PER_UPDATE = (ONE_THOUSAND_MILLISECS/FPS);
    double lag = 0.0;

    m_RenderSystem.InitMainWindowAndRenderer();
    m_GameWorld.CreatePlayerEntity();

    //TODO: Update shitty game loop to account for lag.
    //Get the delta time, pass it into Update function.
    //Need to use RK4 integrator to determine updates for Game State?
    //Interpolate? Pass into renderer?
    //Shieeeet.
    while(!m_bExit)
    {
      boost::chrono::high_resolution_clock::time_point current = boost::chrono::high_resolution_clock::now();
      boost::chrono::milliseconds elapsed = boost::chrono::duration_cast<boost::chrono::milliseconds> (current - previous);
      previous = current;
      lag += elapsed.count();

      m_bExit = m_InputSystem.ProcessAllUserInput();

      while (lag >= MS_PER_UPDATE)
      {
        m_GameWorld.UpdateGameWorldState();
        lag -= MS_PER_UPDATE;
      }

      m_RenderSystem.Render(/*lag.count() / MS_PER_UPDATE.count()*/);
      std::cout << lag << std::endl;
    }
}
