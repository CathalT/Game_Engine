#include "GameWorld.h"

#include "boost/shared_ptr.hpp"
#include "json.h"
#include "Components.h"

#include <vector>
#include <istream>
#include <fstream>


using namespace boost;

GameWorld::GameWorld(EntityManager & entityManager,ComponentStore & componentStore)
: m_EnityManager(entityManager)
, m_ComponentStore(componentStore)
{
    //ctor
}

GameWorld::~GameWorld()
{
    //dtor
}

//TODO: Abstract create entity methods, take a list of images from a file + default values.
//      These files will have list of components and their default values.
//      E.g. [name:Tree],[SpriteComponent:filePath,redraw,isLoaded],etc. JSON would be handy for this.
void GameWorld::CreatePlayerEntity()
{
    //TODO: Entity must correspond with components place in component vector.
    //TODO: Let entitys be a pair, a bool determining existance and its id or index of the array for any component identified by the entity
    //      E.G. SpriteComponents[newEntity] = new Sprite;
    //      Need to work out how to do this. Probably have to revert to arrays and have a fixed pool of entitys.

    Json::Value root;
    Json::Value allEntities;
    Json::Value entity;
    Json::Value component;
    Json::Value spriteComponent;
    Json::Reader reader;
    Json::Value positionComponent;

    std::filebuf fb;
    if (fb.open ("C:/Devroot/Game_Engine/bin/Debug/world_entitys.txt",std::ios::in))
    {
        std::istream is(&fb);

        bool parsingSuccessful = reader.parse( is, root );
        if ( !parsingSuccessful )
        {
            // report to the user the failure and their locations in the document.
            std::cout << "Failed to parse configuration\n" << std::endl;
            std::cout << reader.getFormatedErrorMessages() << std::endl;
        }
    };
    fb.close();

    allEntities = root["entities"];

    for ( int i = 0; i < allEntities.size(); ++i )  // Iterates over the sequence elements.
    {
        int newEntity = m_EnityManager.CreateNewEntity();
        entity = allEntities[i];

        for(int j = 0; j < entity.size();++j)
        {
            component = entity[j];
            spriteComponent = component["Sprite"];
            positionComponent = component["Position"];

            if(spriteComponent != Json::nullValue)
            {
                shared_ptr<Sprite> newSprite = shared_ptr<Sprite>(new Sprite);
                newSprite->entity = newEntity;
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
                newPosition->entity = newEntity;

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
        }
    }
}

void GameWorld::CreateBallEntity()
{
    int ballEntity = m_EnityManager.CreateNewEntity();
    std::string imageFilePath("../Images/red_ball.png");
    shared_ptr< Sprite > ballSprite = shared_ptr<Sprite>(new Sprite);

    ballSprite->entity = ballEntity;
    ballSprite->filePath = imageFilePath;
    ballSprite->redraw = true;
    ballSprite->isLoaded = false;
    ballSprite->texture = NULL;

    m_ComponentStore.AddSpriteComponent(ballSprite);

    shared_ptr<Position> ballPosition = shared_ptr<Position>(new Position);
    ballPosition->entity = ballEntity;
    ballPosition->x = 5;
    ballPosition->y = 5;
    m_ComponentStore.AddPositionComponent(ballPosition);
}
void GameWorld::UpdateGameWorldState()
{
    //UpdateShizzle
    shared_ptr<Position> pos;
    pos = m_ComponentStore.GetPositionByEntity(2);
    if(pos)
    {
        pos->x++;
    }
}
