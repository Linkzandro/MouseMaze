#pragma once
class Position
{
private:
	int x, y;
	Position* next;

public:
	Position(int a, int b);
	Position(Position* pos,int a,int b);
	bool operator==(const Position& position) const;
	Position* getNext();
	void setNext(Position* nextPos);

	int getX();
	int getY();
};

