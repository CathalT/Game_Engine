#include "ComponentManager.h"
#include "boost/shared_ptr.hpp"
#include "Components/SpriteComponent.h"
#include <vector>

ComponentManager::ComponentManager() : m_AllSpriteComponents(new std::vector< shared_ptr<SpriteComponent> >())
{
    //ctor
}

ComponentManager::~ComponentManager()
{
    //dtor
}

void ComponentManager::AddSpriteComponent(shared_ptr<SpriteComponent> spriteComponent)
{
    m_AllSpriteComponents->push_back(spriteComponent);
}

shared_ptr<SpriteComponent> ComponentManager::GetSpriteByEntity(int entity) const
{
    shared_ptr<SpriteComponent> spriteComp = shared_ptr<SpriteComponent>();
    std::vector< shared_ptr<SpriteComponent> >::const_iterator itr;
    for(itr = m_AllSpriteComponents->begin(); itr != m_AllSpriteComponents->end(); ++itr)
    {
        if((*itr)->GetEntity() == entity)
        {
            spriteComp = (*itr);
            break;
        }
    }
    return spriteComp;
}

shared_ptr < std::vector< shared_ptr<SpriteComponent> > > ComponentManager::GetAllSprites() const
{
    return m_AllSpriteComponents;
}
