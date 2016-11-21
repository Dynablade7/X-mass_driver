#include "PlayerObject.h"
#include "SDL.h"

PlayerObject::PlayerObject(Sprite* sprite) : GameObject(sprite) {
}

PlayerObject::~PlayerObject() {
}

void PlayerObject::processInput() {
    // Use SDL's functions for input processing here to control the player
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        _yVel = -1;
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        _yVel = 1;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        _xVel = 1;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        _xVel = -1;
    }
}
