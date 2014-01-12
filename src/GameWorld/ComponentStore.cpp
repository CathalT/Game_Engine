#include "ComponentStore.h"

#define MAX_ENTITYS 1000

ComponentStore::ComponentStore()
: m_AllSpriteComponents(new std::vector< shared_ptr< Sprite > >(MAX_ENTITYS) )
, m_AllPositionComponents(new std::vector< shared_ptr< Position > >(MAX_ENTITYS) )
{
    //ctor
}

ComponentStore::~ComponentStore()
{
    //dtor
}

void ComponentStore::AddSpriteComponent(const shared_ptr< Sprite > & spriteComponent)
{
    if(spriteComponent)
    {
        m_AllSpriteComponents->at(spriteComponent->entity) = spriteComponent;
    }
    else
    {
        std::cout << "Error, cannot add NULL sprite component" << std::endl;
    }
}

shared_ptr<Sprite> ComponentStore::GetSpriteByEntity(int entity) const
{
    return m_AllSpriteComponents->at(entity);
}

const shared_ptr < const std::vector< shared_ptr < Sprite > > > ComponentStore::GetAllSprites() const
{
    return m_AllSpriteComponents;
}

void ComponentStore::AddPositionComponent(const shared_ptr < Position > & positionComponent)
{
    if(positionComponent)
    {
        m_AllPositionComponents->at(positionComponent->entity) = positionComponent;
    }
    else
    {
        std::cout << "Error, cannot add NULL position component" << std::endl;
    }
}

shared_ptr < Position > ComponentStore::GetPositionByEntity(int entity) const
{
    return m_AllPositionComponents->at(entity);
}

const shared_ptr < std::vector< shared_ptr < Position > > > ComponentStore::GetAllPositions() const
{
    return m_AllPositionComponents;
}
