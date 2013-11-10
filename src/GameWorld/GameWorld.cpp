#include "GameWorld.h"
#include "Components/SpriteComponent.h"
#include "boost/shared_ptr.hpp"
#include <vector>

using namespace boost;

GameWorld::GameWorld(EntityManager & entityManager,ComponentManager & componentManager)
: m_EnityManager(entityManager)
, m_ComponentManager(componentManager)
{
    //ctor
}

GameWorld::~GameWorld()
{
    //dtor
}

void GameWorld::CreatePlayerEntity()
{
    int playerEntity = m_EnityManager.CreateNewEntity();
    std::string imageFilePath("../Images/lolSprite.jpg");
    shared_ptr<SpriteComponent> playerSprite = shared_ptr<SpriteComponent>(new SpriteComponent(playerEntity,imageFilePath));
    m_ComponentManager.AddSpriteComponent(playerSprite);
}
void GameWorld::UpdateGameWorldState()
{
    //UpdateShizzle

}
