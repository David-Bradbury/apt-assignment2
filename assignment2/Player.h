#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

#define FULL_HAND 6

class Player
{
public:

    // Constructors/Destructors
    Player();
    Player(std::string name);
    Player(std::string name, LinkedList* hand, int score);
    ~Player();

    // Getters/Setters
    std::string getName();
    int getScore();
    LinkedList* getHand();
    void setName(std::string name);

    // Adds to players score
    void addToScore(int points);
    // Adds tile to players hand
    void addToHand(Tile* tile);

    // Prints players score
    void printScore();
    // Prints players hand separated by comma's
    void printHand();




private:

    std::string name;
    int score;
    LinkedList* hand;

};

#endif //ASSIGN2_PLAYER_H