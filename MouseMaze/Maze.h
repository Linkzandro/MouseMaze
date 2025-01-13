#pragma once
#include <iostream>
#include "Stack.h"
#include "Position.h"
#include <string>
#include <fstream>

class Maze
{
public:
	int getRow() const;
	int getCol() const;
	std::string* getMaze();
	~Maze();
	Maze(const string& arquivo);
	

private:
	friend ostream& operator<< (ostream&, const Maze&);
	bool isWalkable(int x, int y);
	Stack* mazeStack;
	Position currentPosition, exitPosition, firstPosition;
	void pushCellToUnvisited(int row, int col);
	

	string* maze;
	int rows, cols;
};

