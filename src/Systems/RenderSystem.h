#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "GameWorld/ComponentStore.h"
#include "GameWorld/EntityManager.h"

#include "SDL.h"

class RenderSystem
{
    public:
        RenderSystem(EntityManager& entityManager, ComponentStore& componentStore);
        virtual ~RenderSystem();
        void Render();
        void InitMainWindowAndRenderer();
        void LoadTextureBatch(shared_ptr < std::vector <Sprite > > vSprites);
        void UnLoadTextureBatch(shared_ptr < std::vector <Sprite > > vSprites);

    protected:
    private:

    SDL_Window * CreateMainWindow();
    SDL_Renderer * CreateRenderer(SDL_Window * window);
    SDL_Texture* LoadImage(SDL_Renderer* renderer , const std::string& file) const;
    void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *renderer) const;

    private:
    EntityManager m_EntityManager;
    ComponentStore m_ComponentStore;
    SDL_Window * m_MainWindow;
    SDL_Renderer * m_MainRenderer;
};

#endif // RENDERSYSTEM_H
