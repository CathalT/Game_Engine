#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>


class EntityManager
{
    public:
        EntityManager();
        virtual ~EntityManager();
        int CreateNewEntity();
        bool DeleteEntity(const int entityID);
        bool DoesEntityExist(int entityID);
    protected:
    private:
        void PrintEntityVector() const;
        static int m_NextID;
        std::vector<int> m_EntityVector;
};

#endif // ENTITYMANAGER_H
