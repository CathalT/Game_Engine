#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
    public:
        Component(const int entity);
        virtual ~Component();
        int GetEntity() const;
        void SetEntity(const int entity);
    protected:
    private:
        int m_Entity;
};

#endif // COMPONENT_H
