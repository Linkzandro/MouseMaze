
#include <iostream>
#include "Maze.h"

using namespace std;



int main(int argc, char* argv[])
{
    string arquivo = "lab.txt";
    Maze maze(arquivo);

    maze.solveMaze();

    return 0;
}