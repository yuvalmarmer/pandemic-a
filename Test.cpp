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


TEST_CASE("Check all speical ability for players"){
    Board b;
    //Player
    Player p {b,City::Bangkok};
    CHECK(p.role() == string("Player"));

    //Dispatcher Fly to anywhere
    Dispatcher dispatcher{b,City::Bogota};
    dispatcher.take_card(City::Bogota).build();
    CHECK_NOTHROW(dispatcher.fly_direct(City::HongKong));
    
    //FieldDoctor
    FieldDoctor fieldDoctor{b, City::Essen};
    CHECK_NOTHROW(fieldDoctor.treat(City::London).treat(City::Paris));

    //GeneSplicer
    GeneSplicer geneSplicer{b, City::Montreal};
    geneSplicer.take_card(City::Paris).take_card(City::Riyadh).take_card(City::SaoPaulo).take_card(City::Sydney).take_card(City::Washington);
    CHECK_NOTHROW(geneSplicer.discover_cure(Color::Blue));
    //Medic
    Medic medic{b, City::Sydney};
    CHECK_NOTHROW(medic.discover_cure(Color::Blue));

    //OperationsExpert
    OperationsExpert operationsExpert{b,City::Tokyo};
    operationsExpert.take_card(City::Seoul);
    CHECK_NOTHROW(operationsExpert.build());
    //Researcher
    Researcher researcher{b, City::Bangkok};
    researcher.take_card(City::Paris).take_card(City::Riyadh).take_card(City::SaoPaulo).take_card(City::Sydney).take_card(City::Washington);
    CHECK_NOTHROW(researcher.discover_cure(Color::Red));

    //Scientist
    Scientist scientist{b,City::Bogota, 3};
    scientist.take_card(City::Paris).take_card(City::Riyadh).take_card(City::SaoPaulo);
    CHECK_NOTHROW(scientist.discover_cure(Color::Red));
}


TEST_CASE("Check normal routin of game"){
    Board b;
    //Adding player to board
    Player p1 {b,City::Bangkok};
    Player p2 {b, City::SanFrancisco};

    //Setting for random cards
    int divisor  = static_cast<int>(City::Tokyo);
    srand(time(NULL));

    //Take 10 random cards
    for(int i=0;i<10;++i){
        auto city = static_cast<City>(rand() % divisor);
        p1.take_card(static_cast<City>(city));
        city = static_cast<City>(rand() % divisor);
        p1.take_card(static_cast<City>(city));
    }

    //Checking good flyghits
    CHECK_NOTHROW(p1.fly_direct(City::Sydney));
    CHECK_NOTHROW(p1.fly_direct(City::Tokyo));
    CHECK_NOTHROW(p1.fly_direct(City::Atlanta));
    CHECK_NOTHROW(p1.fly_direct(City::Cairo));

    //Checking good flyghits
    CHECK_NOTHROW(p2.fly_direct(City::Delhi));
    CHECK_NOTHROW(p2.fly_direct(City::Khartoum));
    CHECK_NOTHROW(p2.fly_direct(City::Milan));
    CHECK_NOTHROW(p2.fly_direct(City::Osaka));

    //Bad Filghts
    CHECK_THROWS(p2.drive(City::Riyadh));
    CHECK_THROWS(p1.drive(City::Taipei));


}