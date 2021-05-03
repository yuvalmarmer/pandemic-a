
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Virologist : public Player{
        public:
            Virologist(Board& b, City c):Player(b,c){};
    };
}