
#include <iostream>
#include "Maze.h"
using namespace std;



int main(int argc, char* argv[])
{
    string arquivo = "lab.txt";
    Maze maze(arquivo);

    cout << maze;

    cout << "Olá Mundo!!";
    return 0;
}