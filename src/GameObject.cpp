#include "GameObject.h"

#include "Sprite.h"

GameObject::GameObject(Sprite* sprite) : _sprite(sprite) {
}

GameObject::~GameObject() {
}

void GameObject::draw(SDL_Renderer* renderer, int x, int y) {
    _sprite->draw(renderer, x, y);
}

void GameObject::moveObject() {
    _x += _xVel;
    _y += _yVel;
}

//----- Getters -----

double GameObject::getX() {
    return _x;
}

double GameObject::getY() {
    return _y;
}

double GameObject::getXVel() {
    return _xVel;
}

double GameObject::getYVel() {
    return _yVel;
}
