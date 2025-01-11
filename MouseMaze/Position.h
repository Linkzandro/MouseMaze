#pragma once
class Position
{
private:
	int x, y;

public:
	Position(int a,int b);
	bool operator==(const Position& position) const;
};

