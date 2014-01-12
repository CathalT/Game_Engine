#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Systems/InputSystem.h"
#include "Systems/RenderSystem.h"
#include "GameWorld/GameWorld.h"

class GameLoop
{
    public:
        GameLoop(EntityManager& entityManager, ComponentStore& componentStore);
        virtual ~GameLoop();
        void RunLoop();
    private:
        bool m_bExit;
        InputSystem m_InputSystem;
        GameWorld m_GameWorld;
        RenderSystem m_RenderSystem;
        EntityManager m_EntityManager;
        ComponentStore m_ComponentStore;
};

#endif // GAMELOOP_H
