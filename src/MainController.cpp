#include <iostream>

#include "GraphicsManager.h"
#include "MainController.h"
#include "SDL/SDL.h"
#include "interface/UpdateListener.h"

MainController::MainController() {
    _gManager = new GraphicsManager();
}

MainController::~MainController() {
    SDL_Quit();
    // Deallocate everything on the heap
    delete _gManager;
}

void MainController::run() {
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initialize graphics
    _gManager->initGraphics();
    // Make sure graphics are updated every tick
    _updateListeners.push_back(_gManager);
    gameLoop();
}

void MainController::gameLoop() {
    while (!_isQuit) {
        processInput();
        // Notify all that needs to know that the game is updated
        notifyUpdateListeners();

        // Do all the fun stuff from here :D :D :D
    }
}

void MainController::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        // If user requests to quit the game
        if (event.type == SDL_QUIT) {
            _isQuit = true;
            return;
        }
        // Process more input here - player controls?
    }
}

void MainController::notifyUpdateListeners() {
    for (UpdateListener* listener : _updateListeners) {
        listener->GameUpdated();
    }
}
