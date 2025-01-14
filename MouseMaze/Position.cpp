#include "Position.h"

Position::Position() {
	x = 0;
	y = 0;
	next = nullptr;
}

Position::Position(int a,int b) {
	x = a;
	y = b;
	next = nullptr;

}

Position* Position::getNext() {
	return next;
}

Position::Position(Position* pos,int a = 0, int b = 0) {
	x = a;
	y = b;
	next = pos;

}

bool Position::operator==(const Position &position) const {
	return x == position.x && y == position.y;
}


void Position::setNext(Position* nextPos) {
	this->next = nextPos;
}


int Position::getX() {
	return x;
}
int Position::getY() {
	return y;
}