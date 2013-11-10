#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <string>

class SpriteComponent
{
    public:
        SpriteComponent(const int entity,const std::string& filePath);
        virtual ~SpriteComponent();

        void SetFilePath(const std::string & filePath);
        std::string GetFilePath() const;
        int GetEntity() const;
        void SetEntity(const int entity);
        bool GetRedraw() const;
        void SetRedraw(const bool redraw);
        bool GetIsLoaded() const;
        void SetIsLoaded(const bool isLoaded);

    protected:
    private:
        std::string m_FilePath;
        bool m_Redraw;
        bool m_IsLoaded;
        int m_Entity;
        //SDL_Rect m_Size;
};

#endif // SPRITECOMPONENT_H
