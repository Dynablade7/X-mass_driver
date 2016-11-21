#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "interface/UpdateListener.h"

// Forward declarations
class GameObject;
class Sprite;

class GraphicsManager : public UpdateListener {
    public:
        GraphicsManager(std::vector<GameObject*>* gameObjects);
        ~GraphicsManager();
        Sprite* _sprite = nullptr;
        void initGraphics();
        void GameUpdated();
        SDL_Texture* loadTexture(std::string path);
    private:
        SDL_Window* _gameWindow;
        SDL_Renderer* _renderer;
        std::vector<GameObject*>* _gameObjects;
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

};

#endif // GRAPHICSMANAGER_H
