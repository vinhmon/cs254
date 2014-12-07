#include "ParseData.h"
ParseData::ParseData()
{
	address = " ";
	data = " ";
	size = " ";
	cycle = " ";
	lineNum = 0;
}


ParseData::ParseData(string line)
{
	istringstream ss(line);
	ss.ignore(82);
	ss >> address >> data >> size >> cycle;
	lineNum++;
}

ParseData::~ParseData()
{

}

ParseData & ParseData::setAddress(string newAddress)
{
	address = newAddress;
	return *this;
}

ParseData & ParseData::setCycle(string newCycle)
{
	cycle = newCycle;
	return *this;
}

ParseData & ParseData::setdata(string newData)
{
	data = newData;
	return *this;
}

ParseData & ParseData::setsize(string newSize)
{
	size = newSize;
	return *this;
}

ParseData & ParseData::setAll(string line)
{
	istringstream ss(line);
	ss.ignore(82);
	ss >> address >> data >> size >> cycle;
	return *this;

}

string ParseData::getAddress()
{
	return address;
}

string ParseData::getCycle()
{
	return cycle;
}

string ParseData::getData()
{
	return data;
}

string ParseData::getSize()
{
	return size;
}

int ParseData::getDataInt()
{
	stringstream sstr;
	sstr << data;
	sstr << hex;

	int intData;
	sstr >> intData;
	return intData;
}

int ParseData::getLineNum()
{
	return lineNum;
}

void ParseData::setLineNum(int newLineNum)
{
	lineNum = newLineNum;
}


const void ParseData::print()
{
	cout << address << endl << cycle << endl << data << endl << size;
}

