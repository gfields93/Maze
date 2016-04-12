//
//  Vertex.hpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp
#include <string>

enum Color{RED, BLUE, O};
enum Direction {NORTH, EAST, SOUTH, WEST, NORTHEAST, NORTHWEST, SOUTHWEST, SOUTHEAST, NONE};
enum Status {UNDISCOVERED, DISCOVERED, EXIT};

class Vertex{
public:
    /* property functions */
    void setColor(Color color){ _color = color; };
    Color getColor(){return _color;};
    void setDirections(Direction direc){_direction = direc;};
    Direction getDirections(){return _direction;};
    void setStatus(Status status){_status = status;};
    Status getStatus(){return _status;};
    void setXY(int y, int x){ this->x = x; this->y = y;};
    void InitializeVertex(std::string, int, int);
private:
    Color _color;
    Direction _direction;
    Status _status;
    int x;
    int y;
};

#endif /* Vertex_hpp */
