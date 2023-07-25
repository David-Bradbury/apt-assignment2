#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

class Player
{
public:

    Player(int iD, std::string name);
    ~Player();


    void printDetails(int ID, std::string name);
    std::string getName();


    int getScore();
    void setScore(int points);
    LinkedList* getHand();

    void printHand();
    void printScore();

private:
    
    int iD;
    std::string name;
    int score;
    LinkedList* hand;

};

#endif //ASSIGN2_PLAYER_H