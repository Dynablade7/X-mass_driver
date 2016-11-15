#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <vector>

class GraphicsManager;
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

        std::vector<UpdateListener*> _updateListeners;

        /**
         * Does the user want to quit the game?
         */
        bool _isQuit = false;

        GraphicsManager* _gManager;


};

#endif // MAINCONTROLLER_H
