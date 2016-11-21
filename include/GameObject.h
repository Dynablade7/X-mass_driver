#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"

// Forward declarations
class Sprite;

/**
 * The base class for moveable objects in the game.
 */
class GameObject {
    public:
        GameObject(Sprite* sprite);
        virtual ~GameObject();
        void draw(SDL_Renderer* renderer, int x, int y);

        void moveObject();

        /**
         * Apply force to the object! Should accelerate it according to actual
         * Newtonian physics. NOT IMPLEMENTED
         */
        void applyForce(double force, double direction);

        double getX(), getY();
        double getXVel(), getYVel();

    protected:
        Sprite* _sprite;
        double _x, _y;
        double _xVel, _yVel;
        double mass;

};

#endif // GAMEOBJECT_H
