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
	std::string* getMaze() const;
	Maze(const std::string& filename);

private:
	std::string* maze;
	int rows, cols;
	friend std::ostream& operator<< (std::ostream&, const Maze&);
	bool isWalkable(int x, int y);
	Stack* mazeStack;
	Position currentPosition, exitPosition, firstPosition;
	void pushCellToUnvisited(int row, int col);
};

