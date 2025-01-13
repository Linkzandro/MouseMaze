
#include <iostream>
using namespace std;

void printMaze(string* maze, int rows){
    for (int i = 0; i < rows; ++i) {
        for (char c : maze[i]) {
            if (c == '1') {
                cout << "*";
            }
            else if (c == '0') {
                cout << " ";
            }
            else {
                cout << c;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{

    cout << "Olá Mundo!!";
    return 0;
}