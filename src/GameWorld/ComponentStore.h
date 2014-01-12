#ifndef COMPONENTSTORE_H
#define COMPONENTSTORE_H

#include "boost/shared_ptr.hpp"
#include "Components.h"

#include <vector>
using namespace boost;
//class SpriteComponent;
class ComponentStore
{
    public:
        ComponentStore();
        virtual ~ComponentStore();

        //Going to be a large class when all the components are added.
        //Deal with it

        //Return const vectors, only this class can add/remove items from vectors.
        //Components themselves are non-const
        void AddSpriteComponent(const shared_ptr< Sprite > & spriteComponent);
        shared_ptr < Sprite > GetSpriteByEntity(int entity) const;
        const shared_ptr < const std::vector < shared_ptr< Sprite > > > GetAllSprites() const;

        void AddPositionComponent(const shared_ptr < Position > & positionComponent);
        shared_ptr < Position > GetPositionByEntity(int entity) const;
        const shared_ptr < std::vector< shared_ptr < Position > > > GetAllPositions() const;

    protected:
    private:
        shared_ptr < std::vector < shared_ptr < Sprite > > > m_AllSpriteComponents;
        shared_ptr < std::vector < shared_ptr < Position > > > m_AllPositionComponents;
};

#endif // COMPONENTSTORE_H
