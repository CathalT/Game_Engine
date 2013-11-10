#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"


class InputSystem
{
    public:
        InputSystem(EntityManager& entityManager,ComponentManager& componentManager);
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
    ComponentManager m_ComponentManager;
};

#endif // INPUTSYSTEM_H
