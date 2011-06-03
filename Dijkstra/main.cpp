//
//  main.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 28/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include "program_params.h"
#include "open_street_map.h"
#include "shortest_path_finder.h"
using namespace std;

//  ~/Desktop/Dijkstra.debug 50.0681312 19.8282072 50.0679427 19.8280681 ~/Downloads/olszanica.osm

int main (int argc, const char * argv[]) {
    ProgramParams params(argc, argv); // najpierw latitude (szerokość), potem longitude (długość)

    if (params.valid()) {
        OpenStreetMap open_street_map;
        open_street_map.parse_file(params.open_street_map_source_file());

        if (open_street_map.include(params.begin_node()) && open_street_map.include(params.end_node())) {
            Node begin = params.begin_node();
            Node end = params.end_node();

            open_street_map.fill_up_information_about_node(begin);
            open_street_map.fill_up_information_about_node(end);

            ShortestPathFinder shortest_path_finder(open_street_map.nodes());
            cout << "prepare for dijkstra" << endl;
            Path path = shortest_path_finder.between(begin, end);
            cout << "shortest path found!" << endl;
            path.print();
        }
        else {} // TODO!
    }
    else {} // TODO!
    return 0;
}
