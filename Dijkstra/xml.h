#ifndef XML_H
#define XML_H
//
//  xml.h
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include "simplexml.h"
using namespace std;

typedef vector<simplexml *> XMLNodes;
typedef simplexml * const XMLNode;
typedef int XMLCounter;

class XML {
public:
    static XMLNodes ChildrenWithProperty(const XMLNode parent, const string &tag, const string &property_name, const string &property_value);
    static XMLNodes Children(const XMLNode parent, const string &tag);

    static XMLNode ChildWithProperty(const XMLNode parent, const string &tag, const string &property_name, const string &property_value);
    static XMLNode Child(const XMLNode parent, const string &tag);

    static XMLNode NthChild(const XMLNode parent, const XMLCounter & n);

    static XMLNode BuildTree(const string & source);
    static string Property(const XMLNode node, const string &property);
    static string Tag(const XMLNode node);
    static string Id(const XMLNode node, const string & id_name = "id");
};

#endif