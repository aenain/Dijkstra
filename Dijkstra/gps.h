#ifndef GPS_H
#define GPS_H
//
//  gps.h
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "location.h"

namespace Earth {
    const Distance R_max = 6378137; // in meters
    const Distance R_min = 6356752;
}

class GPS {
public:
    static Distance distance(const Location &begin, const Location &end);

private:
    // latitudes in rad
    static Distance average_radius_for_latitudes(const Coordinate &begin_latitude, const Coordinate &end_latitude);
};

#endif