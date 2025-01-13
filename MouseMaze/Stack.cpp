#include "Stack.h"


Stack::Stack() {
	head = nullptr;
}

bool Stack::IsEmpty() {
	return head == nullptr;
}

Position* Stack::Top() {
	if (!IsEmpty()) {
		return head;
	}

	return nullptr;
}

Position* Stack::Pop() {

	if (!IsEmpty()) {
		Position* temp = head;
		head = head->getNext();
		temp->setNext(nullptr);
		return temp;

	}
}

void Stack::DelTop() {
	if (!IsEmpty()) {
		Position* temp = head;
		head = head->getNext();
		delete temp;
	}
}

void Stack::Push(Position pos) {
	Position* newPos = new Position(pos.getX(), pos.getY());
	newPos->setNext(head);
	head = newPos;
}

void Stack::Push(int x,int y) {
	Position* newPos = new Position(x, y);
	newPos->setNext(head);
	head = newPos;

}