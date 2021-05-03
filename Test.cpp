#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "OperationsExpert.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"


using namespace std;
using namespace pandemic;

TEST_CASE("Simple init"){
    Board b;
    Player p {b,City::Bangkok};
    CHECK(p.role() == string("Player"));
}


TEST_CASE("Check all kinds of players"){
    Board b;
    //Player
    Player p {b,City::Bangkok};
    CHECK(p.role() == string("Player"));

    //Dispatcher
    Dispatcher dispatcher{b,City::Bogota};
    CHECK(dispatcher.role() == string("Dispatcher"));

    //FieldDoctor
    FieldDoctor fieldDoctor{b, City::Essen};
    CHECK(fieldDoctor.role() == string("FieldDoctor"));

    //GeneSplicer
    GeneSplicer geneSplicer{b, City::Montreal};
    CHECK(geneSplicer.role() == string("GeneSplicer"));

    //Medic
    Medic medic{b, City::Sydney};
    CHECK(medic.role() == string("Medic"));

    //OperationsExpert
    OperationsExpert operationsExpert{b,City::Tokyo};
    CHECK(operationsExpert.role() == string("OperationsExpert"));

    //Researcher
    Researcher researcher{b, City::Bangkok};
    CHECK(researcher.role() == string("Researcher"));

    //Scientist
    Scientist scientist{b,City::Bogota};
    CHECK(scientist.role() == string("Scientist"));

}



