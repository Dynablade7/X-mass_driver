#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "SDL/SDL.h"
#include "interface/UpdateListener.h"

class GraphicsManager : public UpdateListener {
    public:
        GraphicsManager();
        ~GraphicsManager();
        void initGraphics();
        void GameUpdated();
    private:
        SDL_Window* _gameWindow;
        SDL_Renderer* _renderer;
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

};

#endif // GRAPHICSMANAGER_H
