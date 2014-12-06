#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class word{

public:
	word();
	word(string);
	~word();

	void setWordHex(string);
	//void setWordNum();
	void setWordBinary(string);
	void setAll(string, int);

	const string getWordHex();
	const string getWordBinary();

	const string convertToBinary(string);
	
private:
	string wordHex;
	int wordNum;
	string wordBinary;

};
#endif