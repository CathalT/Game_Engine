#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "SDL.h"

struct Position{
    int entity;
    int x;
    int y;
};

struct Velocity{
    int entity;
    int x;
    int y;
};

struct Acceleration{
    int entity;
    int x;
    int y;
};

struct Sprite{
    int entity;
    std::string filePath;
    bool redraw;
    bool isLoaded;
    SDL_Texture * texture;
};


#endif // COMPONENT_H
