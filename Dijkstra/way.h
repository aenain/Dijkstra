#ifndef WAY_H
#define WAY_H
//
//  way.h
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Way {
public:
    string id();
    string name();
    Way(const string & id, const string & name) : _id(id), _name(name) {};

private:
    string _id, _name;
};

bool operator==(Way & a, Way & b);

#endif