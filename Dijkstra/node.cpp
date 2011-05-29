//
//  node.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "node.h"

bool Node::operator==(const Node & other) {
    bool same_coordinates = (longitude == other.longitude && latitude == other.latitude);
    bool same_id = (id == other.id);

    return same_coordinates || same_id;
}