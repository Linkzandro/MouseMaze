#pragma once
#include "Position.h"

class Stack
{
private:
	Position* head;

public:
	Stack();

	bool IsEmpty();

	Position* Top();

	Position Pop();

	void DelTop();

	void Push(Position pos);
	void Push(int x,int y);
};

