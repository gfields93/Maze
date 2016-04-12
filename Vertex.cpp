//
//  Vertex.cpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#include "Vertex.hpp"

void Vertex::InitializeVertex(std::string string, int y, int x){
    setXY(y, x);
    if (string == "O") {
        setStatus(EXIT);
        setColor(O);
        setDirections(NONE);
    }
    if(string == "R-N"){
        setColor(RED);
        setDirections(NORTH);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-E"){
        setColor(RED);
        setDirections(EAST);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-S"){
        setColor(RED);
        setDirections(SOUTH);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-W"){
        setColor(RED);
        setDirections(WEST);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-NE"){
        setColor(RED);
        setDirections(NORTHEAST);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-NW"){
        setColor(RED);
        setDirections(NORTHWEST);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-SE"){
        setColor(RED);
        setDirections(SOUTHEAST);
        setStatus(UNDISCOVERED);
    }
    else if (string == "R-SW"){
        setColor(RED);
        setDirections(SOUTHWEST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-N"){
        setColor(BLUE);
        setDirections(NORTH);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-E"){
        setColor(BLUE);
        setDirections(EAST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-S"){
        setColor(BLUE);
        setDirections(SOUTH);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-W"){
        setColor(BLUE);
        setDirections(WEST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-NE"){
        setColor(BLUE);
        setDirections(NORTHEAST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-NW"){
        setColor(BLUE);
        setDirections(NORTHWEST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-SE"){
        setColor(BLUE);
        setDirections(SOUTHEAST);
        setStatus(UNDISCOVERED);
    }
    else if(string == "B-SW"){
        setColor(BLUE);
        setDirections(SOUTHWEST);
        setStatus(UNDISCOVERED);
    }
}