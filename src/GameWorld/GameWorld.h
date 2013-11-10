#ifndef GAMEWORLD_H
#define GAMEWORLD_H


#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"

class GameWorld
{
    public:
        GameWorld(EntityManager & entityManager,ComponentManager & componentManager);
        virtual ~GameWorld();
        void UpdateGameWorldState();
        void CreatePlayerEntity();

    protected:
    private:
        EntityManager m_EnityManager;
        ComponentManager m_ComponentManager;
};

#endif // GAMEWORLD_H
