#include "Sprite.h"

#include "GraphicsManager.h"

Sprite::Sprite(int radius, std::string path, GraphicsManager* gm) :
    _radius(radius) {
    _texture = gm->loadTexture(path);
}

Sprite::~Sprite() {
    delete _texture;
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y) {
    SDL_Rect dest = {x, y, _radius * 2, _radius * 2};
    SDL_RenderCopy(renderer, _texture, nullptr, &dest);
}
