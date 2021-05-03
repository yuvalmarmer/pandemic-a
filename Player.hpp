#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
    class Player{
        public:
            //Simple Player functions
            virtual Player& drive(const City&);
            virtual Player& fly_direct(const City&);
            virtual Player& fly_charter(const City&);
            virtual Player& fly_shuttle(const City&);
            virtual Player& build();
            virtual Player& discover_cure(const Color&);
            virtual Player& treat(const City&);
            virtual string role(){
                return "";
            };
            Player& take_card(const City&);
            Player(Board &b , City c);
            
        private:
            Board& board;
            City city;    
    };
}