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
	void setAll(string, int, int);

	const string getWordHex();
	const string getWordBinary();
	const int getLineNum();
	const int getWordNum();

	const string convertToBinary(string);
	
private:
	string wordHex;
	int wordNum, lineNum;
	string wordBinary;

};
#endif