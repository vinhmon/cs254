#ifndef PARSELIST_H
#define PARSELIST_H

#include <iostream>
#include <list>
#include <iomanip>
#include "ParseData.h"
#include "word.h"
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

	const void retrieveAddressFields(Node *current, ofstream &, int numOfRows, int);
	const void retrieveTime(Node *current, int numOfRows, int i);

	~ParseList();


private:
	int count;
	Node *head;
	Node *last;

	//Write S-to-D
	double sizeOfCommands0;
	double totalTime0;
	//Write D-to-S
	double sizeOfCommands1;
	double totalTime1;

	//Read S-to-D
	double sizeOfCommands2;
	double totalTime2;
	//Read D-toS
	double sizeOfCommands3;
	double totalTime3;

};
#endif