#include "Position.h"


Position::Position(int a=0,int b=0) {
	x = a;
	y = b;
}

bool Position::operator==(const Position &position) const {
	return x == position.x && y == position.y;
}