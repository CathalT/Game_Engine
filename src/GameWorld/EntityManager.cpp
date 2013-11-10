#include "EntityManager.h"
#include <iostream>
#include <vector>

int EntityManager::m_NextID = 0 ;

EntityManager::EntityManager() : m_EntityVector()
{
    //ctor
}

EntityManager::~EntityManager()
{
    m_EntityVector.clear();
}


int EntityManager::CreateNewEntity()
{
    ++m_NextID;
    m_EntityVector.push_back(m_NextID);
    return m_NextID;
}

bool EntityManager::DeleteEntity(int entityID)
{
    bool isDeleted = false;
    std::vector<int>::iterator itr;
    for(itr = m_EntityVector.begin(); itr < m_EntityVector.end(); itr++)
    {
        if(entityID == (*itr))
        {
            m_EntityVector.erase(itr);
            isDeleted = true;
            break;
        }
    }
    return isDeleted;
}

bool EntityManager::DoesEntityExist(int entityID)
{
    bool doesExist = false;
    std::vector<int>::iterator itr;
    for(itr = m_EntityVector.begin(); itr < m_EntityVector.end(); itr++)
    {
        if(entityID == (*itr))
        {
            doesExist = true;
            break;
        }
    }
    return doesExist;
}


void EntityManager::PrintEntityVector() const
{
    std::vector<int>::const_iterator itr;
    for(itr = m_EntityVector.begin(); itr < m_EntityVector.end(); itr++)
    {
        std::cout << "ID: " << (*itr) << std::endl;
    }
}
