#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include "SDL.h"

// Forward declarations
class GraphicsManager;

/**
 * A simple sprite class that is really only meant for circles/squares at the moment.
 * Could easily be extended to rectangles if needed, by adding width and height instead of radius.
 *
 * To create a sprite, specify radius, path to resource file and a reference of a GraphicsManager
 * to load with.
 * To draw a sprite, call the draw() function from the GraphicsManager's rendering loop.
 */
class Sprite {
    public:
        /**
         * Constructor.
         * radius - Half the width/height of the sprite. This is the size of the sprite that
         * will be drawn to the screen, NOT the size of the source file.
         * path - The path to the source file
         * gm - A pointer the game's GraphicsManager, used to load the texture.
         */
        Sprite(int radius, std::string path, GraphicsManager* gm);

        /**
         * Destructor.
         */
        ~Sprite();

        /**
         * Draws the sprite to the screen.
         * renderer - The renderer used to draw stuff to the game window
         * x, y - The position on the screen to which the sprite will be drawn (upper left corner)
         */
        void draw(SDL_Renderer* renderer, int x, int y);
    private:
        int _radius;
        SDL_Texture* _texture = nullptr;

};

#endif // SPRITE_H
