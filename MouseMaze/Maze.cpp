#include "Maze.h"
#include <iostream>
#include <fstream>
#include "Stack.h"
#include <string>
#include "Position.h"
#include <chrono>
#include <thread>
#include <Windows.h>


using namespace std;
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
using namespace std::this_thread;


int Maze::getRow() const{
    return rows;
}
int Maze::getCol() const{
    return cols;
}


void Maze::clrScreen() const
{
    COORD cursorPosition = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

bool Maze::isWalkable(int x, int y) {
    return maze[x][y] == '0' || maze[x][y] == 'e';
}

void Maze::markAsVisited(int x, int y) {
    maze[x][y] = '.';
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
    mazeStack=new Stack();
    if (!file) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    string line;
    rows = 0;
    cols = 0;

    // Contar o número de linhas e colunas no arquivo
    while (getline(file, line)) {
        if (rows > 0 && line.length() > cols) {
            cerr << "Erro: Linha " << rows + 1 << " excede o tamanho permitido." << endl;
            file.close();
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

std::ostream& operator<< (std::ostream& out, const Maze& mazeobj) {
    for (int i = 0; i < mazeobj.getRow(); ++i) {
        for (int j = 0; j < mazeobj.getCol(); ++j) {
            
            if (mazeobj.getMaze()[i][j] == '0') {
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

void Maze::solveMaze() {
    int row, col;
    currentPosition = firstPosition;

    while (!(currentPosition == exitPosition)) {
        row = currentPosition.getX();
        col = currentPosition.getY();
        cout << *this;

        if (!(currentPosition == firstPosition) && !(currentPosition==exitPosition)) {
            markAsVisited(currentPosition.getX(), currentPosition.getY());
        }

        pushCellToUnvisited(currentPosition.getX() + 1, currentPosition.getY());//direita
        pushCellToUnvisited(currentPosition.getX() - 1, currentPosition.getY());//esquerda
        pushCellToUnvisited(currentPosition.getX(), currentPosition.getY()-1);//baixo
        pushCellToUnvisited(currentPosition.getX(), currentPosition.getY()+1);//cima

        if (mazeStack->IsEmpty()) {
            cerr << "Falha ao encontrar a saída" << endl;
            return;
        }
        else {
            currentPosition = mazeStack->Pop();
        }
        sleep_for(700ms);
        clrScreen();
    }
    cout << *this;
    cout << "Saida encontrada em: [" << currentPosition.getX() << "," << currentPosition.getY() << "]" << endl;
}