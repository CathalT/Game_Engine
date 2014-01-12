#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "ComponentStore.h"
#include "EntityManager.h"
#include <string>
#include "json.h"

class ComponentFactory
{
    public:
        ComponentFactory(ComponentStore & componentStore, EntityManager & entityManager);
        ~ComponentFactory();
        bool CreateComponentsFromFile(const std::string & inputFile);
    protected:
    private:
        bool ParseEntitys(const Json::Value & entities);
        bool ParseAllComponentsOfEntity(const Json::Value & entity, const int & entityIndex);
        bool ParseComponent(const Json::Value & component,const int & entityIndex);
    private:
        ComponentStore m_ComponentStore;
        EntityManager m_EntityManager;
};

#endif // COMPONENTFACTORY_H
