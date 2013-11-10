#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H
#include <boost/shared_ptr.hpp>
#include <vector>
using namespace boost;
class SpriteComponent;
class ComponentManager
{
    public:
        ComponentManager();
        virtual ~ComponentManager();

        //Going to be a large class when all the components are added.
        //Deal with it
        void AddSpriteComponent(shared_ptr<SpriteComponent> spriteComponent);
        shared_ptr<SpriteComponent> GetSpriteByEntity(int entity) const;
        shared_ptr < std::vector< shared_ptr<SpriteComponent> > > GetAllSprites() const;

    protected:
    private:
        shared_ptr < std::vector< shared_ptr<SpriteComponent> > > m_AllSpriteComponents;
};

#endif // COMPONENTMANAGER_H
