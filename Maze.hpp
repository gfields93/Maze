//
//  Maze.hpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <map>
#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include "Vertex.hpp"
#include "Position.hpp"

typedef std::pair<Coordinates, int> Edge_t;
class Maze{
public:
    Maze(int row, int column) : matrix(row, std::vector<Vertex>(column)), row(row), col(column) {};
    Vertex& operator() (int row,int col){ return matrix.at(row).at(col); }
    Vertex& operator() (Position curPos){ return matrix.at(curPos.yPos()).at(curPos.xPos()); }
    Vertex& operator() (Coordinates coor){ return matrix.at(coor.first).at(coor.second); }
    void FindPath();
    void MakeGraph();
private:
    std::vector<std::vector<Vertex> > matrix;
    std::stack<std::pair<Direction, int> > path;
    std::multimap<Coordinates, Edge_t> graph;
    int row;
    int col;
    void DFS(Coordinates , bool * );
    std::vector<Edge_t> GetNeighbors(Coordinates);
};

#endif /* Maze_hpp */
