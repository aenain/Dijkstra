//
//  xml.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "xml.h"
using namespace std;

XMLNodes XML::ChildrenWithProperty(const XMLNode parent, const string &tag, const string &property_name, const string &property_value) {
    XMLNodes children;
    XMLCounter i = 0;

    while (XMLNode child = NthChild(parent, i++)) {
        if (Tag(child) == tag && Property(child, property_name) == property_value)
            children.push_back(child);
    }

    return children;
}

XMLNodes XML::Children(const XMLNode parent, const string &tag) {
    XMLNodes children;
    XMLCounter i = 0;

    while (XMLNode child = NthChild(parent, i++)) {
        if (Tag(child) == tag)
            children.push_back(child);
    }

    return children;
}

XMLNode XML::ChildWithProperty(const XMLNode parent, const string &tag, const string &property_name, const string &property_value) {
    XMLCounter i = 0;

    while (XMLNode child = NthChild(parent, i++)) {
        if (Tag(child) == tag && Property(child, property_name) == property_value)
            return child;
    }

    return NULL;
}

XMLNode XML::Child(const XMLNode parent, const string &tag) {
    XMLCounter i = 0;

    while (XMLNode child = NthChild(parent, i++)) {
        if (Tag(child) == tag)
            return child;
    }

    return NULL;
}

// METHODS WHICH INVOKES XML LIBRARY EXPLICITELY.

XMLNode XML::BuildTree(const string & source) {
    XMLNode root = new simplexml(source.c_str());
    return root;
}

XMLNode XML::NthChild(const XMLNode parent, const XMLCounter &n) {
    return parent -> child(n);
}

string XML::Property(const XMLNode node, const string &property) {
    string value = node -> property(property.c_str());
    return value;
}

string XML::Tag(const XMLNode node) {
    string tag_name = node -> key();
    return tag_name;
}

string XML::Id(const XMLNode node, const string & id_name) {
    return Property(node, id_name);
}