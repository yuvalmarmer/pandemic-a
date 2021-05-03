#pragma once
#include <stdexcept>
#include "City.hpp"

using namespace std;

namespace pandemic{
    class Board{
        public:
            bool is_clean(){
                return true;
                };
            void remove_cures(){};
            int array[];
            //Return the number of pandemic in giveen city
            int& operator[] (City city){
                return array[0];
            }

            int operator[] (City city) const {
                return -1;
            }
            Board(){};
            friend std::ostream& operator<< (std::ostream& os, const Board& n);


    };
}