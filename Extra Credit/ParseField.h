#ifndef PARSEFIELD_H
#define PARSEFIELD_H
 
#include "ParseList.h"
#include <bitset>

using namespace std;

struct Node1
{
	word data;
	Node1 * next;
	Node1 * previous;

};

class ParseField{

public:
	ParseField();
	~ParseField();

	void insert(word);
	void setForward(bool);

	const void print();
	const void printParse(ofstream & outFile, int);

private:
	int count;
	Node1 *head;
	Node1 *last;
	bool forward;

};
#endif