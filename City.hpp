#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

namespace pandemic{
    enum class City{
        //Blue cities
        SanFrancisco,
        Chicago,
        Montreal,
        NewYork,
        Atlanta,
        Washington,
        Madrid,
        London,
        Essen,
        Milan,
        Paris,
        StPetersburg,

        //Yellow cities
        LosAngeles,
        MexicoCity,
        Miami,
        Bogota,
        Lima,
        Santirgo,
        BuenosAires,
        SaoPaulo,
        Lagos,
        Khartoum,
        Kinshasa,
        Johannesburg,

        //Black cities
        Moscow,
        Istanbull,
        Algiers,
        Cairo,
        Baghdad,
        Tehran,
        Delhi,
        Riyadh,
        Karachi,
        Kolkata,
        Mumbai,
        Chennai,

        //Red cities
        Beijing,
        Shanghai,
        Seoul,
        Tokyo,
        Osaka,
        Taipei,
        HongKong,
        Bangkok,
        Manila,
        Jakarta,
        HoChiMinhCity,
        Sydney
    };
}