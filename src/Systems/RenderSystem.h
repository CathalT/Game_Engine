#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"

#include "SDL.h"

class RenderSystem
{
    public:
        RenderSystem(EntityManager& entityManager, ComponentManager& componentManager);
        virtual ~RenderSystem();
        void Render();
        void InitMainWindowAndRenderer();
    protected:
    private:

    SDL_Window * CreateMainWindow();
    SDL_Renderer * CreateRenderer(SDL_Window * window);
    SDL_Texture* LoadImage(SDL_Renderer* renderer , const std::string& file) const;
    void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *renderer) const;

    private:
    EntityManager m_EntityManager;
    ComponentManager m_ComponentManager;
    SDL_Window * m_MainWindow;
    SDL_Renderer * m_MainRenderer;
};

#endif // RENDERSYSTEM_H
