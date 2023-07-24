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


    void Player::setScore(int points) {
        this->score = this->score + points;

    }

    LinkedList* Player::getHand() { 
        return this->hand;

    }

    void Player::printHand() {

    }

    void Player::printScore() {

        std::cout << this->name << "'s score: " << this->score << std::endl;
    }



