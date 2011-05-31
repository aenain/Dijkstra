//
//  gps.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "math.h"
#include "gps.h"
using namespace std;

// http://fitt.tychy.pl/gps/PoradyJanusza.htm#Porada_17_Obliczanie_odleg_o_ci_
Distance GPS::distance(const Location & begin, const Location & end) {
    Distance distance;
    Distance averaged_radius = average_radius_for_latitudes(begin.latitude, end.latitude);

    distance = 2 * averaged_radius * asin(sqrt(pow(sin((begin.latitude - end.latitude)/2), 2) + cos(begin.latitude) * cos(end.latitude) * pow(sin((begin.longitude - end.longitude)/2), 2)));

    return distance;
}

// http://fitt.tychy.pl/gps/PoradyJanusza.htm#Porada_17_Obliczanie_odleg_o_ci_
Distance GPS::average_radius_for_latitudes(const Coordinate &begin_latitude, const Coordinate &end_latitude) {
    Distance radius_difference = Earth::R_max - Earth::R_min;
    Coordinate average_of_latitudes = (begin_latitude + end_latitude)/2;

    return Earth::R_max - radius_difference * sin(Numbers::to_rad(average_of_latitudes));
}