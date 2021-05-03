
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class FieldDoctor : public Player{
        public:
            FieldDoctor(Board& b, City c):Player(b,c){};
    };
}