#ifndef PARSELIST_H
#define PARSELIST_H

#include <iostream>
#include "ParseData.h"
#include "word.h"
#include <list>

using namespace std;

struct Node
{
	ParseData data;
	Node * next;
	Node * previous;

};

class ParseList {

public:
	ParseList();

	void insertFront(ParseData data);
	void insertBack(ParseData data);

	ParseData getParseData();

	const void print();
	const void printReverse();
	const void printParse();
	
	const int getCount();

	const void retrieveAddressFields(Node *current);

	~ParseList();


private:
	int count;
	Node *head;
	Node *last;
	
};
#endif