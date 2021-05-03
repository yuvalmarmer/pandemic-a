
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class OperationsExpert : public Player {
        public:
            OperationsExpert(Board& b, City c):Player(b,c){};
    };
}