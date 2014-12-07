#ifndef PARSELIST_H
#define PARSELIST_H

#include <iostream>
#include "ParseData.h"
#include "word.h"
#include <list>
#include "ParseField.h"

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

<<<<<<< HEAD
	const void retrieveAddressFields(Node *current, ofstream &);

=======
	const void retrieveAddressFields(Node *current);
	void findWordCommand(int wordPos, string& wordcommand);
>>>>>>> bbc6e24bf633f6aeffcea16eeee56106f7d09703
	~ParseList();


private:
	int count;
	Node *head;
	Node *last;
	
};
#endif