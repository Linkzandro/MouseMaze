#pragma once
class Position
{
private:
	int x, y;
	Position* next;

public:
	Position(int a, int b);
	Position(int a,int b,Position* pos);
	bool operator==(const Position& position) const;
	Position* getNext();
	void setNext(Position* nextPos);

	int getX();
	int getY();
};

