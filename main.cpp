//Benchawan Wijitchakhorn
//Date: 12 May 2022 
//Course: DT026G VT22
//Happy to have a BIG E

#include "functions.h"
#include <iostream>
#include <ctime>

int main() {
    int N;
    int HEIGHT;
    int num;

    while (true) {
        srand(time(NULL));

        std::cout << "Hi! Welcome to My Maze Generator! :D " << "\n";
        std::cout << "Enter [1] : Create Maze [11 X 11]  " << "\n";
        std::cout << "Enter [2] : Create Maze [n X n]  " << "\n";
        std::cout << "Enter [0] : Exit " << "\n";
        std::cin >> num;
        if (num == 1) {
            maze Maze = maze();

            Maze.genMaze();
            Maze.showMaze();
        }
        else if (num == 2) {
              
                std::cout << "                                    **NOTE**                                " << "\n";
                std::cout << "             - Dimension N can only be entered with integer                 " << "\n";
                std::cout << "             - Dimension N *MUST* be more then 11                           " << "\n";
                std::cout << "             - if invalid input, defualt maze will be drawn                 " << "\n";
                std::cout << "                                    -ENJOY!!-                     :D        " << "\n";
                std::cout << "\n";
                std::cout << "Enter disired dimension N x N : " << "\n";
                std::cin >> N;
                if (N >= 11 ) {
                    maze Maze = maze(N,N);
                    Maze.genMaze();
                    Maze.showMaze();

                }
                else {
                    std::cout << "Invalid Input!!!" << "\n";
                    std::cout << "_______________________________" << "\n";
                    std::cout << "Generating... Defualt maze size (11 x 11)" << "\n";
                    maze Maze = maze();

                    Maze.genMaze();
                    Maze.showMaze();

                }
     
        }
        else if (num == 0) {
            std::cout << "Have a nice day! :D" << "\n";
            exit(0);
        }
        else {
            std::cout << "Invalid Input! Please Try Agian!!" << "\n";
        }
    }
  

   
    
	return 0;
}