//
//  Maze.cpp
//  Maze
//
//  Created by Glen Fields on 11/16/15.
//  Copyright © 2015 gfields. All rights reserved.
//

#include "Maze.hpp"
#include <iostream>

void Maze::FindPath(){
    std::ofstream os;
    os.open("output.txt",std::ios::out);
    bool  exitFound = false;
    Direction direc;
    int distance;
    Coordinates start = std::make_pair(0, 0);
    DFS(start, &exitFound);
    if (path.size() == 0) {
        os << "No path was found." << std::endl;
    }
    else{
        while (path.size() != 0) {
            direc = path.top().first;
            distance = path.top().second;
            switch (direc) {
                case NORTH:
                    os << distance << "N ";
                    break;
                case EAST:
                    os << distance << "E ";
                    break;
                case SOUTH:
                    os << distance << "S ";
                    break;
                case WEST:
                    os << distance << "W ";
                    break;
                case NORTHWEST:
                    os << distance << "NW ";
                    break;
                case NORTHEAST:
                    os << distance << "NE ";
                    break;
                case SOUTHEAST:
                    os << distance << "SE ";
                    break;
                case SOUTHWEST:
                    os << distance << "SW ";
                    break;
                default:
                    break;
            }
            path.pop();
        }
    }
    os.close();
}

void Maze::DFS(Coordinates coor, bool * found){
    Direction direc = this->operator()(coor).getDirections();
    std::vector<Edge_t> neighbors = GetNeighbors(coor);
    if (this->operator()(coor).getStatus() != EXIT) {
        this->operator()(coor).setStatus(DISCOVERED);
    }
    else if (this->operator()(coor).getStatus() == EXIT){
        *found = true;
        return;
    }
    for (int i = 0; i < neighbors.size(); ++i) {
        if (this->operator()(neighbors.at(i).first).getStatus() == DISCOVERED) {
            continue;
        }
        else{
            Coordinates newCoor = neighbors.at(i).first;
            DFS(newCoor, found);
            if (*found == true) {
                path.push(std::make_pair(direc, neighbors.at(i).second));
                return;
            }
        }
    }
}

void Maze::MakeGraph(){
    for (int y = 0; y < row; ++y) {
        for (int x = 0 ; x < col; ++x) {
            if (y == row - 1 && x == col - 1) {
                break;
            }
            int distance = 0;
            Position curPos;
            curPos.setPosition(y, x);
            Position scanPos = curPos;
            Color color = this->operator()(curPos).getColor();
            Direction direc = this->operator()(curPos).getDirections();
            while (1) {
                scanPos.movePosition(direc);
                ++distance;
                if ((scanPos.xPos() < 0 || scanPos.xPos() >= col) || (scanPos.yPos() < 0 || scanPos.yPos() >= row)) {
                    break;
                }
                else if(this->operator()(scanPos).getColor() == color){
                    continue;
                }
                else{
                    Edge_t value =std::make_pair(scanPos.getCoordinates(), distance);
                    graph.insert(std::pair<Coordinates, Edge_t>(curPos.getCoordinates(),value));
                }
            }
        }
    }
}
std::vector<Edge_t> Maze::GetNeighbors(Coordinates coor){
    std::vector<Edge_t> neighbors;
    std::multimap<Coordinates, Edge_t>::iterator i = graph.lower_bound(coor);
    std::multimap<Coordinates, Edge_t>::iterator j = graph.upper_bound(coor);
    for (; i != j; ++i) {
        neighbors.push_back(i->second);
    }
    return neighbors;
}

