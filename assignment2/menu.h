#ifndef MENU
#define MENU 

enum selection {
    START = 1,
    LOAD = 2,
    CREDITS = 3,
    EXIT = 4
};

class Menu
{
public:

    // Constructor/Destructor
    Menu();
    ~Menu();

    // print the menu.
    void printMenu();

    // Starts a new game.
    void startNewGame();

    // Loads game from file.
    void loadGame();

    // print student credits.
    void printCredits();

    // end game.
    void quitGame();

private:

};

#endif //MENU