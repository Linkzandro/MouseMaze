#pragma once
#include "Position.h"
class Stack
{
private:
	Position* head;

public:
	Stack();
	~Stack();

	bool IsEmpty();

	Position* Top();

	void Pop();

	void Push(Position pos);
	void Push(int x,int y);
};

