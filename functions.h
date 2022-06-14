//Benchawan Wijitchakhorn
//Date: 12 May 2022 
//Course: DT026G VT22
//Happy to have a BIG E

#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class maze {
private:
    struct node {
        size_t x, y;
        bool path = false;
        bool start = false;
        bool end = false;
        bool wall = false;
        bool visited = false;
        std::string value;
        std::vector<bool> neighbors; //vector that will contain size of neigbor that can be visited whichb will be use later on in pickNeighbor and is_visited_neig functions
        /// <summary>
        /// create a node which will puts in container(vector) 
        /// The node that been create will have inputs string value (illustrated on print function) 
        /// </summary>
        /// <param name="val"> string value </param>
        /// <param name="x"> maze index[x] </param>
        /// <param name="y"> maze index[y] </param>
        node(std::string val, size_t x, size_t y); 
    };

public:
    size_t width, height;
    std::vector<std::vector<node>> themaze; //2D container
    /// <summary>
    /// Defualt Construct which will gives defualt maze size[11][11]
    /// </summary>
    maze();
    /// <summary>
    /// Create maze base in user disired
    /// </summary>
    /// <param name="width"> input of width </param>
    /// <param name="height"> input of height </param>
    maze(size_t width, size_t height);
    /// <summary>
    /// create maze function in vector as container
    /// </summary>
    /// <param name="x"> size of maze as width </param>
    /// <param name="y"> size of maze as height </param>
    /// <returns> temp vector </returns>
    std::vector<std::vector<node>> makemaze(size_t x, size_t y);
    /// <summary>
    /// Get size of maze and return themaze array's index[x][y] values 
    /// </summary>
    /// <param name="width"> maze index x or width </param>
    /// <param name="height"> maze index y or height </param>
    /// <returns> themaze index[x][y] values </returns>
    std::string get_strval(size_t width, size_t height);
    /// <summary>
    /// pointer which points at nodes in the maze.
    /// Get width and height index and return themaze array's index[x][y] 
    /// </summary>
    /// <param name="width"> maze index x/width </param>
    /// <param name="height"> maze index y/height </param>
    /// <returns> themaze array's index[x][y] </returns>
    node* get_node(size_t width, size_t height);
    /// <summary>
    /// poiter which will  point at nodes,
    /// and also will determined if both nodes visited and availiable neighbor as false or true.
    /// Set themaze[x][y] where poiter are at(pick) as visited
    /// </summary>
    /// <param name="x">maze index x </param>
    /// <param name="y">maze index y</param>
    /// <returns></returns>
    node* pickNeighbor(size_t x, size_t y);
    /// <summary>
    /// Check if there is any unvisited neighbor
    /// </summary>
    /// <param name="x"> maze index [x] </param>
    /// <param name="y"> maze index [y] </param>
    /// <param name="width"> maze size width </param>
    /// <param name="height"> maze size height </param>
    /// <returns> true or false depends on if statsments </returns>
    bool is_visited_neig(size_t x, size_t y, size_t width, size_t height);
    /// <summary>
    /// Print function 
    /// </summary>
    void showMaze();
    /// <summary>
    /// Generate the maze with DFS algorithm
    /// </summary>
    void genMaze();
    

};


#endif