#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <vector>

// Forward declarations
class GameObject;
class GraphicsManager;
class PlayerObject;
class UpdateListener;

class MainController {
    public:
        MainController();
        ~MainController();

        /**
         * Initializes systems and starts the game loop.
         */
        void run();
    private:

        /**
         * The main game loop.
         */
        void gameLoop();
        void processInput();
        void notifyUpdateListeners();

        /**
         * A vector of all the game's GameObjects.
         * When creating a new one, it must be added to this vector.
         */
        std::vector<GameObject*> _gameObjects;
        PlayerObject* _player = nullptr;
        std::vector<UpdateListener*> _updateListeners;

        /**
         * Does the user want to quit the game?
         */
        bool _isQuit = false;

        GraphicsManager* _gManager;
};

#endif // MAINCONTROLLER_H
