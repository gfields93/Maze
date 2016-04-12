//
//  main.cpp
//  Maze_Proj
//
//  Created by Glen Fields on 11/5/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#include <iostream>
#include "Maze.hpp"

int main(int argc, const char * argv[]) {
    int rows, columns;
    std::string vertexProp;
    std::fstream fs;
    fs.open(argv[1]);
    if (!(fs.is_open())) {
        perror("Couldn't open file");
        return 1;
    }
    fs >> rows >> columns;
    Maze maze(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            fs >> vertexProp;
            maze(i,j).InitializeVertex(vertexProp, i, j);
        }
    }
    fs.close();
    maze.MakeGraph();
    maze.FindPath();
    return 0;
}