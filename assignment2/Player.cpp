#include "Player.h"
#include <iostream>


Player::Player() {
}

Player::Player(std::string name) {

    try {
        this->name = name;
        this->hand = new LinkedList();
        this->score = 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

Player::Player(std::string name, LinkedList* hand, int score) {

    try {
        this->name = name;
        this->hand = hand;
        this->score = score;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
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



void Player::printHand() {


    if (this->hand->size() > 0) {
        for (int i = 0; i < this->hand->size() - 1; i++) {

            std::cout << this->hand->get(i)->getColour() << this->hand->get(i)->getShape() << ",";
        }
        std::cout << this->hand->get(this->hand->size() - 1)->getColour() << this->hand->get(this->hand->size() - 1)->getShape() << std::endl;
    }
    else {
        std::cerr << "No tiles in players hand." << std::endl;
    }
}


void Player::printScore() {

    std::cout << this->name << "'s score: " << this->score << std::endl;
}


void Player::addToHand(Tile* tile) {

    if (this->hand->size() < FULL_HAND) {
        this->hand->addBack(tile);
    }
}