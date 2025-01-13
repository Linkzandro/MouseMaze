#include "Maze.h"
#include <iostream>
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

std::string* Maze::getMaze() {
    return maze;
}


ostream& operator<< (ostream& out, const Maze& mazeobj) {
    for (int i = 0; i < mazeobj.getRow(); ++i) {
        for (int j = 0; j < mazeobj.getCol(); ++j) {
            if (mazeobj.maze[i][j] == '1') {
                cout << "*";
            }
            else if (mazeobj.maze[i][j] == '0') {
                cout << " ";
            }
            else {
                cout << mazeobj.maze[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

Maze::Maze(const string& arquivo) {
    ifstream file(arquivo);

    if (!file) {
        throw exception();
    }

    string line;
    rows = 0;
    cols = 0;

    // Contar o número de linhas e colunas no arquivo
    while (getline(file, line)) {
        if (rows > 0 && line.length() > cols) {
            cerr << "Erro: Linha " << rows + 1 << " excede o tamanho permitido." << endl;
            file.close();
            throw exception();
        }
        if (line.length() > cols) {
            cols = line.length();
        }
        ++rows;
    }

    file.clear();
    file.seekg(0, ios::beg); // Retornar ao início do arquivo

    maze = new string[rows + 2]; // Adiciona duas linhas para as paredes

    // Preencher a primeira linha com paredes
    maze[0] = string(cols + 2, '1');

    for (int i = 1; i <= rows; ++i) {
        getline(file, line);
        if (line.length() < cols) {
            line += string(cols - line.length(), '0'); // Preencher com zeros se necessário
        }
        line = "1" + line + "1"; // Adicionar paredes nas laterais
        maze[i] = line;
        for (int j = 0; j < line.length(); ++j) {
            if (line[j] == 'm') {
                firstPosition = Position(i, j);
            }
            else if (line[j] == 'e') {
                exitPosition = Position(i, j);
            }
        }
    }

    // Preencher a última linha com paredes
    maze[rows + 1] = string(cols + 2, '1');

    rows += 2;
    cols += 2;

    file.close();
}

Maze::~Maze() {
    delete[] maze;
}


void Maze::pushCellToUnvisited(int row,int col) {
    if (isWalkable(row, col)){
        mazeStack->Push(row,col);
    }
}