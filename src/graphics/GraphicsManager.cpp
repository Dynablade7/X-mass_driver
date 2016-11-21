#include <stdio.h>
#include "GameObject.h"
#include "GraphicsManager.h"
#include "SDL_image.h"
#include "Sprite.h"

GraphicsManager::GraphicsManager(std::vector<GameObject*>* gameObjects) :
    _gameObjects(gameObjects) {
}

GraphicsManager::~GraphicsManager() {
    delete _sprite;
}

void GraphicsManager::initGraphics() {
    // Create window
    _gameWindow = SDL_CreateWindow("X-massDriver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(_gameWindow == nullptr)  {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
        // Create renderer for window
        _renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == nullptr) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        } else {
            // Initialize renderer color
            SDL_SetRenderDrawColor(_renderer, 0xAA, 0xAA, 0xAA, 0xFF);
            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }
        }
    }
    _sprite = new Sprite(8, "res/sprites/empty-circle.png", this);

}

SDL_Texture* GraphicsManager::loadTexture(std::string path) {
    // The final texture
    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create texture from surface
        newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void GraphicsManager::GameUpdated() {
    SDL_RenderClear(_renderer);
    // --- Perform all rendering here ---

    for (GameObject* obj : *_gameObjects) {
        obj->draw(_renderer, obj->getX(), obj->getY());
    }

    // -----------------------------------
    SDL_RenderPresent(_renderer);
}
