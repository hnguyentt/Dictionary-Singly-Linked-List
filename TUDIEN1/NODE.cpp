#include "NODE.h"



NODE::NODE()
{
	TU tu;
	this->data = tu;
	this->next = NULL;
}

NODE::NODE(TU tu) {
	this->data = tu;
	this->next = NULL;
}

NODE::~NODE()
{
}

NODE* NODE::Next() {
	return next;
}

void NODE::SetNext(NODE* next) {
	this->next = next;
}

TU NODE::GetData() {
	return data;
}