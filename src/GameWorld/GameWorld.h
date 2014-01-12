#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GameWorld/ComponentStore.h"
#include "GameWorld/EntityManager.h"

class GameWorld
{
    public:
        GameWorld(EntityManager & entityManager,ComponentStore & componentStore);
        virtual ~GameWorld();
        void UpdateGameWorldState();
        void CreatePlayerEntity();
        void CreateBallEntity();

    protected:
    private:
        EntityManager m_EnityManager;
        ComponentStore m_ComponentStore;
};

#endif // GAMEWORLD_H
