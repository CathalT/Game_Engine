#include "Component.h"

Component::Component(const int entity) : m_Entity(entity)
{
    //ctor
}

Component::~Component()
{
    //dtor
}

int Component::GetEntity() const
{
    return m_Entity;
}

void Component::SetEntity(const int entity)
{
    m_Entity = entity;
}
