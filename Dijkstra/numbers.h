#ifndef NUMBERS_H
#define NUMBERS_H
//
//  numbers.h
//  Dijkstra
//
//  Created by Artur Hebda on 30/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <sstream>
//#include <boost/lexical_cast.hpp>
using namespace std;

typedef double Distance;
typedef Distance Coordinate;

namespace Numbers {
    //const Distance MAXIMUM = 4294967295;
    const Distance MAXIMUM = 2000000000;
    const int PRECISION = 7;
    const int PRINT_PRECISION = 2;
    const Distance EPSILON = pow(0.1, PRECISION);
    const Coordinate PI = 3.141592653589793;

    inline bool are_equal(const Distance & a, const Distance & b) {
        Distance difference = a - b;
        return (-Numbers::EPSILON < difference && difference <= 0) || (0 <= difference && difference < Numbers::EPSILON);
    }

    inline Distance to_f(const std::string & literal) {
        return atof(literal.c_str());
        //return boost::lexical_cast<Distance>(literal);
    }

    inline Distance to_f(const char * literal) {
        return atof(literal);
        //return boost::lexical_cast<Distance>(literal);
    }

    inline Coordinate in_range(const Coordinate &value, const Coordinate &minimum, const Coordinate &maximum) {
        return (minimum <= value) && (value <= maximum);
    }

    inline Coordinate to_rad(const Coordinate &in_degrees) {
        return in_degrees * 2 * PI / 360;
    }

    inline Coordinate to_degrees(const Coordinate &in_rad) {
        return in_rad * 360 / (2 * PI);
    }

    inline Distance with_precision(Distance distance, const int precision = PRECISION) {
        Distance precision_factor = pow(10, precision);
        Distance precised = round(distance * precision_factor) / precision_factor;
        return precised;
    }

    inline string to_s(Distance distance, const int precision = PRINT_PRECISION) {
        ostringstream stream;
        stream << with_precision(distance, precision);
        return stream.str();
    }
}

#endif