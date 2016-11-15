#ifndef UPDATELISTENER_H_INCLUDED
#define UPDATELISTENER_H_INCLUDED

/**
 * Let a class implement this interface if it needs to be updated
 * every tick. Remember to add the instance of the class to the list
 * of UpdateListeners in MainController!
 */
class UpdateListener {
    public:
        virtual void GameUpdated() = 0;
};

#endif // UPDATELISTENER_H_INCLUDED
