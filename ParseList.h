#ifndef PARSELIST_H
#define PARSELIST_H

#include <iostream>
#include "ParseData.h"

using namespace std;

struct Node
{

	ParseData data;
	Node * next;

};

class ParseList {

public:
	ParseList();

	void insertFront(ParseData data);

	ParseData getParseData();

	const void print();

	~ParseList();


private:
	int count;
	Node* head;

};
#endif