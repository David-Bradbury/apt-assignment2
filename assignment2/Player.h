#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

#define FULL_HAND 6

class Player
{
public:

// Constructor/deconstructor for player variables.
    Player();
    Player(std::string name);
    Player(std::string name, LinkedList* hand, int score);
    ~Player();

// Prints player name.
    void printDetails(int ID, std::string name);
    std::string getName();

// Score variables.
    int getScore();
    void addToScore(int points);
    void printScore();

// Hand variables.
    LinkedList* getHand();
    void printHand();
    void addToHand(Tile* tile);

    void setName(std::string name);

private:

    std::string name;
    int score;
    LinkedList* hand;

};

#endif //ASSIGN2_PLAYER_H
