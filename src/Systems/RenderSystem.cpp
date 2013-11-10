#include "RenderSystem.h"

#include "Components/SpriteComponent.h"

#include "GameWorld/ComponentManager.h"
#include "GameWorld/EntityManager.h"

#include "boost/shared_ptr.hpp"

#include "SDL_image.h"
#include "SDL.h"

#include <iostream>
#include <vector>




using namespace boost;

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

RenderSystem::RenderSystem(EntityManager& entityManager, ComponentManager& componentManager)
: m_EntityManager(entityManager)
, m_ComponentManager(componentManager)
, m_MainWindow()
, m_MainRenderer()
{
    //ctor
}

RenderSystem::~RenderSystem()
{
    //dtor
}

void RenderSystem::InitMainWindowAndRenderer()
{
    m_MainWindow = CreateMainWindow();
    m_MainRenderer = CreateRenderer(m_MainWindow);
}

SDL_Window * RenderSystem::CreateMainWindow()
{
    SDL_Window *window = NULL;
    window = SDL_CreateWindow
    (
    "Player Sprite Test",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
    }
    return window;
}

SDL_Renderer * RenderSystem::CreateRenderer(SDL_Window * window)
{
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
    }
}

void RenderSystem::Render()
{
    shared_ptr < std::vector< shared_ptr<SpriteComponent> > > spriteComponents = m_ComponentManager.GetAllSprites();

    SDL_Texture *playerSprite = NULL;

    shared_ptr<SpriteComponent> spritePtr = spriteComponents->back();
    std::string spriteFilePath = spritePtr->GetFilePath();
    if(!spritePtr->GetIsLoaded())
    {
        playerSprite = LoadImage(m_MainRenderer,spriteFilePath);
    }

    SDL_RenderClear(m_MainRenderer);

    int iW, iH;
    SDL_QueryTexture(playerSprite, NULL, NULL, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;
    ApplySurface(x, y, playerSprite, m_MainRenderer);

    SDL_RenderPresent(m_MainRenderer);
}


SDL_Texture* RenderSystem::LoadImage(SDL_Renderer* renderer, const std::string& file) const
{
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(renderer, file.c_str());
    if (tex == NULL)
        std::cout << "Failed to load image: " << file << IMG_GetError << std::endl;
    return tex;
}

void RenderSystem::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *renderer) const
{
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);

    SDL_RenderCopy(renderer, tex, NULL, &pos);
}
