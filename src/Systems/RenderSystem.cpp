#include "RenderSystem.h"

#include "GameWorld/ComponentStore.h"
#include "GameWorld/EntityManager.h"
#include "GameWorld/Components.h"

#include "boost/shared_ptr.hpp"

#include "SDL_image.h"

#include <iostream>
#include <vector>


using namespace boost;

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

RenderSystem::RenderSystem(EntityManager& entityManager, ComponentStore& componentStore)
: m_EntityManager(entityManager)
, m_ComponentStore(componentStore)
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
    //Get list of entitys,run through them, get position for each and display it
    shared_ptr < const std::vector < shared_ptr < Sprite > > > spriteComponents = m_ComponentStore.GetAllSprites();
    shared_ptr < std::vector < shared_ptr < Position > > > positionComponents = m_ComponentStore.GetAllPositions();
    std::vector< shared_ptr < Sprite > >::const_iterator spriteItr;

    SDL_RenderClear(m_MainRenderer);

    for(spriteItr = spriteComponents->begin();spriteItr!=spriteComponents->end();++spriteItr) // O(2^n) algorithm... eh yeah that wont work
    {
        shared_ptr<Sprite> spriteComp = (*spriteItr);
        if(spriteComp)
        {
            SDL_Texture * spriteTexture = spriteComp->texture;
            shared_ptr<Position> spritePosition = m_ComponentStore.GetPositionByEntity(spriteComp->entity);
            ApplySurface(spritePosition->x,spritePosition->y,spriteTexture,m_MainRenderer);
        }
        /*int iW, iH;
        SDL_QueryTexture(spriteTexture, NULL, NULL, &iW, &iH);
        int x = SCREEN_WIDTH / 2 - iW / 2;
        int y = SCREEN_HEIGHT / 2 - iH / 2;
        ApplySurface(x, y, spriteTexture, m_MainRenderer);*/

    }

    SDL_RenderPresent(m_MainRenderer);
}

void RenderSystem::LoadTextureBatch(shared_ptr < std::vector <Sprite > > vSprites)
{
    shared_ptr< const std::vector< shared_ptr< Sprite > > > spriteComponents = m_ComponentStore.GetAllSprites();
    std::vector< shared_ptr< Sprite > >::const_iterator spriteItr = spriteComponents->begin();

    for(spriteItr = spriteComponents->begin();spriteItr!=spriteComponents->end();++spriteItr)
    {
        shared_ptr<Sprite> spriteComp = (*spriteItr);
        if(spriteComp && !spriteComp->isLoaded) // Probably shouldn't be doing that in the game loop
        {
            spriteComp->texture = LoadImage(m_MainRenderer,spriteComp->filePath);
        }
    }
}

void RenderSystem::UnLoadTextureBatch(shared_ptr < std::vector <Sprite > > vSprites)
{
 /*   shared_ptr < std::vector< Sprite > > spriteComponents = m_ComponentStore.GetAllSprites();
    std::vector<Sprite>::iterator spriteItr = spriteComponents->begin();

    for(spriteItr = spriteComponents->begin();spriteItr!=spriteComponents->end();++spriteItr)
    {
        Sprite * spriteComp = &(*spriteItr);
        if(!spriteComp->isLoaded) // Probably shouldn't be doing that in the game loop
        {
            spriteComp->texture = LoadImage(m_MainRenderer,spriteComp->filePath);
        }
    }*/
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
