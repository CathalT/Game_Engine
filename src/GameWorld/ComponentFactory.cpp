#include "ComponentFactory.h"
#include <istream>
#include <fstream>

#include "json.h"

ComponentFactory::ComponentFactory(ComponentStore & componentStore,EntityManager & entityManager)
: m_ComponentStore(componentStore)
,m_EntityManager(entityManager)
{

}

ComponentFactory::~ComponentFactory()
{
    //dtor
}

bool ComponentFactory::CreateComponentsFromFile(const std::string & inputFile)
{
    bool bSuccess = false;
    Json::Value allEntitys;
    std::filebuf fb;

    if (fb.open (inputFile.c_str(),std::ios::in) != NULL)
    {
        std::istream is(&fb);
        Json::Reader reader;
        if(reader.parse( is, allEntitys ))
        {
            allEntitys = allEntitys["entities"];
            bSuccess = ParseEntitys(allEntitys);
        }
    }
    fb.close();

    return bSuccess;
}

bool ComponentFactory::ParseEntitys(const Json::Value & entities)
{
    bool bSuccess = false;
    if(entities == Json::nullValue)
    {
        return bSuccess;
    }

    for ( int i = 0; i < entities.size(); ++i )
    {
        int newEntityIndex = m_EntityManager.CreateNewEntity();
        Json::Value entity = entities[i];
        if(!ParseAllComponentsOfEntity(entity,newEntityIndex))
        {
            return bSuccess;
        }
    }
    return bSuccess = true;
 }

bool ComponentFactory::ParseAllComponentsOfEntity(const Json::Value & entity, const int & entityIndex)
{
    bool bSuccess = false;
    if(entity == Json::nullValue)
    {
        return bSuccess;
    }

    for(int i = 0; i < entity.size();++i)
    {
        Json::Value component = entity[i];
        if(!ParseComponent(component,entityIndex))
        {
            return bSuccess;
        }
    }
    return bSuccess = true;
}

bool ComponentFactory::ParseComponent(const Json::Value & component,const int & entityIndex)
{
    bool bSuccess = false;
    if(component == Json::nullValue)
    {
        return bSuccess;
    }

    Json::Value::Members componentMembers = component.getMemberNames();
    Json::Value::Members::iterator membItr = componentMembers.begin();

    Json::Value spriteComponent; //= component["Sprite"];
    Json::Value positionComponent; //= component["Position"];

    //Only one member in this vector, could just .back() / .front()
    for(; membItr != componentMembers.end(); ++membItr)
    {
        std::string memberName = (*membItr);
        if(memberName == "Sprite")
        {
            spriteComponent = component[memberName];
        }
        if(memberName == "Position")
        {
            positionComponent = component[memberName];
        }
    }

    //Json::Value spriteComponent = component["Sprite"];
    //Json::Value positionComponent = component["Position"];


    if(spriteComponent != Json::nullValue)
    {
        shared_ptr<Sprite> newSprite = shared_ptr<Sprite>(new Sprite);
        newSprite->entity = entityIndex;
        newSprite->texture = NULL;

        for(int x=0; x < spriteComponent.size();++x)
        {
            Json::Value spriteComponentItr = spriteComponent[x];
            Json::Value filePath = spriteComponentItr["FilePath"];
            Json::Value reDraw = spriteComponentItr["reDraw"];
            Json::Value isLoaded = spriteComponentItr["isLoaded"];
            if(filePath != Json::nullValue)
            {
                newSprite->filePath = filePath.asString();
            }
            if(reDraw != Json::nullValue)
            {
                newSprite->redraw = reDraw.asBool();
            }
            if(isLoaded != Json::nullValue)
            {
                newSprite->isLoaded = isLoaded.asBool();
            }
        }

        m_ComponentStore.AddSpriteComponent(newSprite);
    }
    if(positionComponent != Json::nullValue)
    {
        shared_ptr<Position> newPosition = shared_ptr<Position>(new Position);
        newPosition->entity = entityIndex;

        for(int x=0; x < positionComponent.size(); ++x)
        {
            Json::Value positionComponentItr = positionComponent[x];
            Json::Value xPos = positionComponentItr["x"];
            Json::Value yPos = positionComponentItr["y"];
            if(xPos != Json::nullValue)
            {
                newPosition->x = xPos.asInt();
            }
            if(yPos != Json::nullValue)
            {
                newPosition->y = yPos.asInt();
            }
        }
        m_ComponentStore.AddPositionComponent(newPosition);
    }
    return bSuccess = true;
}

