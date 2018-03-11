#pragma once
#include"TU.h"
class NODE
{
private:
	TU data;
	NODE *next;
public:
	NODE();
	~NODE();
	NODE(TU);
	NODE* Next();
	void SetNext(NODE*);
	TU GetData();
};

