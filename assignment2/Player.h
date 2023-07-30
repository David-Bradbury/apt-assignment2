#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

#define FULL_HAND 6

class Player
{
public:

    Player(int iD, std::string name);
    Player();
    Player(std::string name);
    Player(std::string name, LinkedList* hand, int score);
    ~Player();


    void printDetails(int ID, std::string name);
    std::string getName();


    int getScore();
    void addToScore(int points);
    void printScore();

    LinkedList* getHand();
    void printHand();
    void addToHand(Tile* tile);

    void setName(std::string name);

private:

    int iD;
    std::string name;
    int score;
    LinkedList* hand;

};

#endif //ASSIGN2_PLAYER_H