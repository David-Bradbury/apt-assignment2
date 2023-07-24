#ifndef PLAYER
#define PLAYER 

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
    int setScore(int points);
    LinkedList* getHand();

    void printHand();
    void printScore();

private:
    
    int iD;
    std::string name;
    int score;
    LinkedList* hand;

};

#endif //PLAYER