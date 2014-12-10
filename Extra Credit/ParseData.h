#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ParseData {

public:
	ParseData();
	ParseData(string line);

	ParseData & setAll(string line);
	ParseData & setAddress(string);
	ParseData & setdata(string);
	ParseData & setsize(string);
	ParseData & setCycle(string);

	string getAddress();
	string getData();
	string getSize();
	string getCycle();
	double getTime();

	int getDataInt();
	int getLineNum();

	void setLineNum(int);
	void setTimeSec(string);

	const void print();

	~ParseData();

private:
	string address, data, size, cycle, relTime;
	double relTimeSec;
	int lineNum;
};
#endif