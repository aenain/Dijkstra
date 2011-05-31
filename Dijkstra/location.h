#ifndef LOCATION_H
#define LOCATION_H
//
//  location.h
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include "numbers.h"

class Location {
public:
    Coordinate latitude, longitude;
    Location(const Coordinate & latitude, const Coordinate & longitude) : latitude(latitude), longitude(longitude) {};
};

bool operator==(const Location &a, const Location &b);

#endif