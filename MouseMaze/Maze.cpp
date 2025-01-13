#include "Maze.h"
#include <iostream>
#include <fstream>
#include "Stack.h"
#include <string>
#include "Position.h"

using namespace std;

int Maze::getRow() const{
    return rows;
}
int Maze::getCol() const{
    return cols;
}

bool Maze::isWalkable(int x, int y) {
    return maze[x][y] == '0' || maze[x][y] == 'e';
}

std::string* Maze::getMaze() const{
    return maze;
}




void Maze::pushCellToUnvisited(int row, int col) {
    if (isWalkable(row, col)) {
        mazeStack->Push(row, col);
    }
}


Maze::Maze(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    string line;
    rows = 0;
    cols = 0;

    // Contar linhas e colunas
    while (getline(file, line)) {
        if (rows > 0 && line.length() != cols) {
            cout << "Erro: Linhas do labirinto possuem tamanhos diferentes." << endl;
            file.close();
            exit(1);
        }
        cols = line.length();
        ++rows;
    }

    file.clear();
    file.seekg(0, ios::beg);

    maze = new string[rows];
    mazeStack = new Stack();
    for (int i = 0; i < rows; ++i) {
        getline(file, maze[i]);
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 'm') {
                firstPosition = Position(i, j);
            }
            else if (maze[i][j] == 'e') {
                exitPosition = Position(i, j);
            }
        }
    }

    file.close();
}



std::ostream& operator<< (std::ostream& out, const Maze& mazeobj) {
    for (int i = 0; i < mazeobj.getRow(); ++i) {
        for (int j = 0; j < mazeobj.getCol(); ++j) {
            if (mazeobj.getMaze()[i][j] == '1') {
                cout << "*";
            }
            else if (mazeobj.getMaze()[i][j] == '0') {
                cout << " ";
            }
            else {
                cout << mazeobj.getMaze()[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

    return out;
}