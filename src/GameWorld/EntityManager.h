#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>


class EntityManager
{
    public:
        EntityManager();
        ~EntityManager();
        int CreateNewEntity();
        bool MarkEntityForDelete(const int entityID);
        bool DoesEntityExist(const int entityID);
    private:
        void PrintEntityVector() const;
    private:
        typedef std::vector< std::pair < int , bool > > EntityPairVector;
        typedef std::pair< int , bool > EntityPair;

        static unsigned int m_NextID;

        EntityPairVector m_EntityPairVector;
};

#endif // ENTITYMANAGER_H
