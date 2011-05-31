//
//  location.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include <string>
#include "location.h"
using namespace std;

bool operator==(const Location &a, const Location &b) {
    return (a.latitude == b.latitude && a.longitude == b.longitude);
}