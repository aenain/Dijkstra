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

    Coordinate begin_latitude = Numbers::to_rad(begin.latitude);
    Coordinate begin_longitude = Numbers::to_rad(begin.longitude);
    Coordinate end_latitude = Numbers::to_rad(end.latitude);
    Coordinate end_longitude = Numbers::to_rad(end.longitude);

    Distance averaged_radius = average_radius_for_latitudes(begin_latitude, end_latitude);

    distance = 2 * averaged_radius * asin(sqrt(pow(sin((begin_latitude - end_latitude)/2), 2) + cos(begin_latitude) * cos(end_latitude) * pow(sin((begin_longitude - end_longitude)/2), 2)));

    return distance; // in meters
}

// http://fitt.tychy.pl/gps/PoradyJanusza.htm#Porada_17_Obliczanie_odleg_o_ci_
Distance GPS::average_radius_for_latitudes(const Coordinate &begin_latitude, const Coordinate &end_latitude) {
    Distance radius_difference = Earth::R_max - Earth::R_min;
    Coordinate average_of_latitudes = (begin_latitude + end_latitude)/2;

    return Earth::R_max - radius_difference * sin(average_of_latitudes);
}