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
#include "lexical_cast.h"

typedef double Distance;

namespace Numbers {
    const Distance MAXIMUM = 4294967295;
    const int PRECISION = 7;
    const Distance EPSILON = pow(0.1, PRECISION);
    
    inline bool are_equal(const Distance & a, const Distance & b) {
        Distance difference = a - b;
        return (-Numbers::EPSILON < difference && difference <= 0) || (0 <= difference && difference < Numbers::EPSILON);
    }

    inline Distance to_f(const std::string & literal) {
        return boost::lexical_cast<Distance>(literal);
    }

    inline Distance to_f(const char * literal) {
        return boost::lexical_cast<Distance>(literal);
    }
}

#endif