#include "SpriteComponent.h"
#include <string>

SpriteComponent::SpriteComponent(const int entity,const std::string& filePath)
: m_FilePath(filePath)
, m_Redraw(true)
, m_IsLoaded(false)
, m_Entity(entity)
{
    //ctor
}

SpriteComponent::~SpriteComponent()
{
    //dtor
}

int SpriteComponent::GetEntity() const
{
    return m_Entity;
}

void SpriteComponent::SetEntity(const int entity)
{
    m_Entity = entity;
}

void SpriteComponent::SetFilePath(const std::string & filePath)
{
    m_FilePath = filePath;
}

std::string SpriteComponent::GetFilePath() const
{
    return m_FilePath;
}

bool SpriteComponent::GetRedraw() const
{
    return m_Redraw;
}

void SpriteComponent::SetRedraw(const bool redraw)
{
    m_Redraw = redraw;
}

bool SpriteComponent::GetIsLoaded() const
{
    return m_IsLoaded;
}

void SpriteComponent::SetIsLoaded(const bool isLoaded)
{
    m_IsLoaded = isLoaded;
}
