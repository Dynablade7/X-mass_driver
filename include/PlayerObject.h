#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <GameObject.h>


class PlayerObject : public GameObject {
    public:
        PlayerObject(Sprite* sprite);
        ~PlayerObject();
        void processInput();
    private:


};
#endif // PLAYEROBJECT_H
