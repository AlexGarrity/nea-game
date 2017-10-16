#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "WindowManager.h"
#include "GameObject.h"

class ObjectManager
{
    public:
        /** Default constructor */
        ObjectManager();
        /** Default destructor */
        virtual ~ObjectManager();

        void UpdateObjects();

    protected:

    private:
        std::vector<GameObject*> objectList;
};

#endif // OBJECTMANAGER_H
