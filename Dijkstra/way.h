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
#include "numbers.h"
using namespace std;

class Way {
public:
    string id() const;
    string name() const;
    bool oneway() const;
    string & to_xml(const Distance distance = 0, const string &xml_nodes = "") const;
    Way(const string & id, const string & name, bool oneway = false) : _id(id), _name(name), _oneway(oneway) {};

private:
    string _id, _name;
    bool _oneway;
};

bool operator==(Way & a, Way & b);

#endif