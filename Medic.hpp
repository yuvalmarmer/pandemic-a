
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Medic : public Player{
        public:
            Medic(Board& b, City c):Player(b,c){};

    };
}