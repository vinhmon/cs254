#include "word.h"

word::word()
{
	
}

word::word(string data)
{
	wordHex = data;
	wordBinary = convertToBinary(data);

}

word::~word()
{

}

void word::setWordBinary(string newWord)
{
	wordBinary = newWord;
}

void word::setWordHex(string newWord)
{
	wordHex = newWord;
}

void word::setAll(string newWord, int num)
{
	wordHex = newWord;
	wordBinary = convertToBinary(newWord);
	wordNum = num;
}

const string word::getWordBinary()
{
	return wordBinary;
}

const string word::getWordHex()
{
	return wordHex;
}


const string word::convertToBinary(string data)
{
	stringstream ss;
	ss << hex << data;
	int n;
	ss >> n;
	bitset<16> b(n);
	return b.to_string();

}



