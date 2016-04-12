//
//  Position.hpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include "Vertex.hpp"
typedef std::pair<int, int> Coordinates;
class Position {
public:
    Position() : x(0), y(0) {};
    Position(int y, int x) : x(x), y(y) {};
    void moveNorth(){ --y; };
    void moveEast() { ++x; };
    void moveSouth(){ ++y; };
    void moveWest() { --x; };
    void moveNorthEast() { --y; ++x; };
    void moveNorthWest() { --y; --x; };
    void moveSouthEast() { ++y; ++x; };
    void moveSouthWest() { ++y; --x; };
    void setPosition(int y, int x) { this->x = x; this->y = y; };
    void setPosition(Coordinates coor) { this->x = coor.second; this->y = coor.first; };
    std::pair<int, int> getCoordinates() { return std::make_pair(this->y, this->x); };
    int xPos(){ return x; };
    int yPos(){ return y; };
    void movePosition(Direction);
private:
    int x;
    int y;
};
#endif /* Position_hpp */
