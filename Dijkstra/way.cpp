//
//  way.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "way.h"
#include <string>
using namespace std;

string Way::id() {
    return _id;
}

string Way::name() {
    return _name;
}

bool operator==(Way & a, Way & b) {
    return a.id() == b.id();
}