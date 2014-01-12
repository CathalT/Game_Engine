#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "GameWorld/ComponentStore.h"
#include "GameWorld/EntityManager.h"


class InputSystem
{
    public:
        InputSystem(EntityManager& entityManager,ComponentStore& componentStore);
        virtual ~InputSystem();

        bool ProcessAllUserInput();
        bool GetIsExitClicked();
        void SetIsExitClicked(bool update);
    protected:
    private:

    void ProcessKeyPresses();


    private:
    bool m_bExitGame;
    EntityManager m_EntityManager;
    ComponentStore m_ComponentStore;
};

#endif // INPUTSYSTEM_H
