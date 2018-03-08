#include "GameLoop.h"

#include "Systems/RenderSystem.h"
#include "Systems/InputSystem.h"

#include "GameWorld/ComponentFactory.h"
#include "GameWorld/ComponentStore.h"
#include "GameWorld/EntityManager.h"
#include "GameWorld/GameWorld.h"

#include <boost/chrono.hpp>
#include <iostream>

const double FPS = 60.0;
const double ONE_THOUSAND_MILLISECS = 1000.0;

GameLoop::GameLoop(EntityManager& entityManager, ComponentStore& componentStore)
: m_bExit(false)
, m_InputSystem(entityManager,componentStore)
, m_GameWorld(entityManager,componentStore)
, m_RenderSystem(entityManager,componentStore)
, m_EntityManager(entityManager)
, m_ComponentStore(componentStore)
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
    ComponentFactory compFact(m_ComponentStore,m_EntityManager);
    compFact.CreateComponentsFromFile("C:/Devroot/Game_Engine/bin/Debug/world_entitys.txt");
    //m_GameWorld.CreatePlayerEntity();
    //m_GameWorld.CreateBallEntity();
    m_RenderSystem.LoadTextureBatch(shared_ptr< std::vector<Sprite> >());

    //TODO: Update game loop to account for lag.
    //Get the delta time, pass it into Update function.
    //Need to use RK4 integrator to determine updates for Game State?
    //Or set render and update FPS to static 60~?
    //Interpolate? Pass into renderer?
    while(!m_bExit)
    {
      boost::chrono::high_resolution_clock::time_point current = boost::chrono::high_resolution_clock::now();
      boost::chrono::milliseconds elapsed = boost::chrono::duration_cast<boost::chrono::milliseconds> (current - previous);
      previous = current;
      lag += elapsed.count();
      std::cout << "Lag before: " << lag << std::endl;

      m_bExit = m_InputSystem.ProcessAllUserInput();
      int count1 = 0;
      while (lag >= MS_PER_UPDATE)
      {
        ++count1;
        m_GameWorld.UpdateGameWorldState();
        lag -= MS_PER_UPDATE;
      }

      m_RenderSystem.Render(/*lag / MS_PER_UPDATE*/);
      std::cout << "Update Count: " << count1 <<  std::endl;
      std::cout << "Lag after: " << lag << std::endl;
    }
}
