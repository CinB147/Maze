//Benchawan Wijitchakhorn
//Date: 12 May 2022 
//Course: DT026G VT22
//Happy to have a BIG E

#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stack>



maze::maze(){ //Defualt Contruct
    this->width = 11;
    this->height = 11;
    themaze = makemaze(width, height);
}

maze::maze(size_t width, size_t height) { //User's input disire dimension maze
    this->width = width;
    this->height = height;
    themaze = makemaze(width, height);
}

std::vector<std::vector<maze::node>> maze::makemaze(size_t x, size_t y) {


    std::vector<std::vector<node>> temp;

    for (size_t i = 0; i < 2 * x + 1; i++) //increse size of maxtrix becuase of drawing grid (walls) in matrix, which later i and j value can be % 2 to get odd num and even num
    {
        std::vector<node> a_vec; //push nodes in x-axis vec(a_vec) in line 77 will nodes br push back over to y-axis in vec(temp)
        for (size_t j = 0; j < 2 * y + 1; j++)
        {  
            if (i == 1 && j == 0) { //startpoint //"S"
                node temp = node("S", i, j);
                temp.start = true;
                temp.visited = true;
                a_vec.push_back(temp);
            }
            else if (i % 2 == 1 && j % 2 == 1) //[even num][even num] ex[1][1], [3][3] // "   "
            {
                node temp = node("   ", i, j);
                temp.path = true;
                temp.wall = false;
                temp.visited = false;
               
                a_vec.push_back(temp);
            }
            else if (i % 2 == 1 && j % 2 == 0) { //[odd num][even num] ex[1][0], [3][2] //"|"
                node temp = node("|", i, j);
                temp.path = false;
                temp.wall = true;
                temp.visited = false;
                a_vec.push_back(temp);
            }
            else if (i % 2 == 0 && j % 2 == 1) { //[even num][odd num] ex[0][1], [2][3] //"---"
                node temp = node("---", i, j);
                temp.path = false;
                temp.visited = false;
                temp.wall = true;

                a_vec.push_back(temp);
            }
            else if (i % 2 == 0 && j % 2 == 0) { //[even num][even num] ex[0][0], [2][2] //"+"
                node temp = node("+", i, j);
                temp.path = false;
                temp.wall = false;
                temp.visited = false;
                a_vec.push_back(temp);
            }
            if (i == 2 * x - 1 && j == 2 * y - 1) { //endpoint "E"
                node temp = node("E", i, j);
                temp.end = true;
                temp.visited = true;
                a_vec.push_back(temp);
            }

        }
        temp.push_back(a_vec);
    }
    return temp;
}


maze::node::node(std::string val, size_t x, size_t y) {
    this->x = x;
    this->y = y;
    this->value = val;
    for (int i = 0; i < 4; i++) //push back neighbor size(4) for on nodes
    {
        neighbors.push_back(false);
    }
   
}

void maze::showMaze() { //display maze 
    std::cout << "mymaze : " <<std::endl;
    for (int h = 0; h < 2 * height + 1; h++) //decrease maze due to grid/walls from makemaze functions 
    {
        for (int w = 0; w < 2 * width + 1; w++)
        {
            std::cout << get_strval(h, w); 
        }
        std::cout << std::endl;
    }
}
std::string maze::get_strval(size_t width, size_t height) {

    return themaze[width][height].value; //return vector maze values
}

maze::node* maze::get_node(size_t width, size_t height) {
    return &themaze[width][height]; //return vector maze[x][y] cordinates
}

bool maze::is_visited_neig(size_t x, size_t y, size_t width, size_t height) {
    for (int i = 0; i < 4; i++)
    {
        themaze[x][y].neighbors.at(i) = false;  // nodes in maze[x][y] has 4 numbers of availiable, for loop will loop number and set as false
    }

    if (x > 1 && themaze[x - 2][y].visited == false) { //if there is unvisited nodes on next positionand x > 1( x is not out vector range from left side)
        themaze[x][y].neighbors.at(0) = true;          //neigbor number 0 is availiable
        return true; 
    }

    if (x < 2 * width - 2 && themaze[x + 2][y].visited == false) { //if there is unvisited nodes on next position and x < 2 *width - 2 ( x is not out vector range from right side)
        themaze[x][y].neighbors.at(1) = true;                      //neigbor number 1 is availiable
        return true; 
    }
    if (y > 1 && themaze[x][y - 2].visited == false) {       //if there is unvisited nodes on next position and y < 1 ( y is not out vector range from up side)
        themaze[x][y].neighbors.at(2) = true;                //neigbor number 2 is availiable
        return true; 
    }
    if (y < 2 * height - 2 && themaze[x][y + 2].visited == false) { //if there is unvisited nodes on next position and y < 2 * height - 2  ( y is not out vector range from down side)
        themaze[x][y].neighbors.at(3) = true;               //neigbor number 3 is availiable
        return true; 
    }
    else { 
        return false; 
    }
}


maze::node* maze::pickNeighbor(size_t x, size_t y) {
   
    node* temp = get_node(x, y); //poiter on maze[x][y]
    bool chosen = false;
    int num;
    while (!chosen) {
        num = rand() % 4; //random number from 0-3

        if (themaze[x][y].neighbors.at(num) = true) { 
            chosen = true;
            switch (num)
            {
            case 0:
                if (x > 1 && themaze[x - 2][y].visited == false) { //check if neighbor is visited and also x shouldnt be out of vector range
                    themaze[x - 2][y].visited == true; //set maze[x][y] as visited
                    temp = get_node(x - 2, y);         //return [x][y]

                }

                break;
            case 1:
                if (x < 2 * width - 2 && themaze[x + 2][y].visited == false) {  
                    themaze[x + 2][y].visited == true;
                    temp = get_node(x + 2, y);                                    
                }

                break;
            case 2: 
                if (y > 1 && themaze[x][y - 2].visited == false) {
                    themaze[x][y - 2].visited == true;
                    temp = get_node(x, y - 2); 
                }
       
                break;
            case 3:
                if (y < 2 * height - 2 && themaze[x][y + 2].visited == false) {
                   themaze[x][y + 2].visited == true;
                    temp = get_node(x, y + 2);
                }
                                 
                break;
            }

        }

    }
    return temp;
}


void maze::genMaze() {

    std::stack <node*> MyStack;
    node* curr = get_node(1, 1); //start node 
    curr->visited = true;
    //bool valid = false;

    MyStack.push(curr); //push in current poisition in Stack

    while (!MyStack.empty()) {
        curr = MyStack.top(); //determine first element in stack is current position
        MyStack.pop();
        if (is_visited_neig(curr->x, curr->y, width, height)) {
            MyStack.push(curr);
            node* next = pickNeighbor(curr->x, curr->y); //pointer at next node that are random unvisited neighbor
            node* temp = get_node((curr->x + next->x) / 2, (curr->y + next->y) / 2); //pointer at 'wall' which in between next node and current node.
                                                               //There is 2 types of wall that need to be taken care of "---" , "|". Which they also assinged in specific matrix[][]
            if ((temp->x) % 2 == 0 && (temp->y ) % 2 == 1) {   //for matrix [x][y], when x = even num and y = odd num. The values that contain in specific matrix is "---" 
                temp->value = "   ";
            }
            else if ((temp->x ) % 2 == 1 && (temp->y ) % 2 == 0) {  //for matrix [x][y], when x = odd num and y = even num. The values that contain in specific matrix is "|" 
                temp->value = " ";
            }
            temp->wall = false;
            temp->path = true;
            temp->visited = true;
            curr = next;
            curr->visited = true;
            MyStack.push(next); 
        }
    }

    
}


