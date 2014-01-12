#include "EntityManager.h"
#include <iostream>

//Put this somewhere properly noob
#define MAX_ENTITYS 1000

unsigned int EntityManager::m_NextID = 0 ;

EntityManager::EntityManager() : m_EntityPairVector(MAX_ENTITYS)
{
    //ctor
}

EntityManager::~EntityManager()
{
    m_EntityPairVector.clear();
}

int EntityManager::CreateNewEntity()
{
    if(m_NextID < MAX_ENTITYS)
    {
        bool isAlive = true;
        ++m_NextID;
        m_EntityPairVector.at(m_NextID) = EntityPair(m_NextID,isAlive);
        PrintEntityVector();
        return m_NextID;
    }
    std::cout << "Error, MAX Entitys reached. Call upon divine goat lord Asgeroth to spawn more minions.";
    return 0;
}

bool EntityManager::MarkEntityForDelete(const int entityID)
{
    bool deleteSuccessful = false;
    EntityPair entityPair = m_EntityPairVector.at(entityID);

    if(entityPair.first > 0 && entityPair.second)
    {
        bool isAlive = false;
        entityPair.second = isAlive;
        deleteSuccessful = true;
    }

    return deleteSuccessful;
}

bool EntityManager::DoesEntityExist(const int entityID)
{
    bool doesExist = false;
    EntityPair entityPair = m_EntityPairVector.at(entityID);
    if(entityPair.first > 0 && entityPair.second)
    {
        doesExist = true;
    }
    return doesExist;
}


//TODO: Debug method, candidate for removal.
void EntityManager::PrintEntityVector() const
{
    EntityPairVector::const_iterator itr;
    for(itr = m_EntityPairVector.begin(); itr < m_EntityPairVector.end(); itr++)
    {
        if((*itr).first > 0)
        {
            std::cout << "ID: " << (*itr).first << " Does exist?: " << std::boolalpha << (*itr).second << std::noboolalpha << std::endl;
        }
    }
}
