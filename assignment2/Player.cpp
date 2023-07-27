#include "Player.h"
#include <iostream>

Player::Player(int iD, std::string name) {

    this->iD = iD;
    this->name = name;
    this->hand = nullptr;
    this->score = 0;


}

Player::~Player() {

}


void Player::printDetails(int ID, std::string name) {

}

std::string Player::getName() {
    return this->name;

}

int Player::getScore() {
    return this->score;
}


void Player::addToScore(int points) {
    this->score = this->score + points;

}

LinkedList* Player::getHand() {
    return this->hand;

}

//Need to check that hand is full before printing!
void Player::printHand() {

    if (this->hand->size() == FULL_HAND) {

        for (int i = 0; i < FULL_HAND; i++) {

            std::cout << this->hand->get(i) << ", ";
        }
        std::cout << std::endl;
    }
    else {
        std::cerr << "Hand can not be printed as hand is not complete." << std::endl;
    }
}

void Player::printScore() {

    std::cout << this->name << "'s score: " << this->score << std::endl;
}

void Player::addToHand(Tile* tile) {
    std::cout << "****In Add To Hand****" << std::endl;
    // if (this->hand->size() < FULL_HAND) {
    std::cout << "****@nd In Add To Hand****" << std::endl;
    this->hand->addBack(tile);
    std::cout << "****3Rd in After Add To Hand****" << std::endl;
    //  }

}



