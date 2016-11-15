#include <stdio.h>
#include "GraphicsManager.h"

GraphicsManager::GraphicsManager() {
}

GraphicsManager::~GraphicsManager() {
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
            SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
        }
    }
}

void GraphicsManager::GameUpdated() {
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}
