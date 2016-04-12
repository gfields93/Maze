//
//  Position.cpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#include "Position.hpp"

void Position::movePosition(Direction direc){
    switch (direc) {
        case NORTH:
            this->moveNorth();
            break;
        case EAST:
            this->moveEast();
            break;
        case SOUTH:
            this->moveSouth();
            break;
        case WEST:
            this->moveWest();
            break;
        case NORTHEAST:
            this->moveNorthEast();
            break;
        case NORTHWEST:
            this->moveNorthWest();
            break;
        case SOUTHEAST:
            this->moveSouthEast();
            break;
        case SOUTHWEST:
            this->moveSouthWest();
            break;
        default:
            break;
    }
}
