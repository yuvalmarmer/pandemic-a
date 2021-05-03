

#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#include "City.hpp"

using namespace std;

namespace pandemic{
    Player& Player::treat(const City& c){
        return *this;
    }
    Player& Player::discover_cure(const Color& color){
        return *this;

    }
    Player& Player::drive(const City& c){
        return *this;

    }
    Player& Player::fly_charter(const City& c){
        return *this;

    }
    Player& Player::fly_shuttle(const City& c){
        return *this;

    }
    Player& Player::fly_direct(const City& c){
        return *this;

    }
    Player& Player::build(){
        return *this;

    }

    Player& Player::take_card(const City& c){
        return *this;

    }

    Player::Player(Board &b, City c):board(b),city(c){

    }
}