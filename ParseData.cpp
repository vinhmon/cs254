#include "ParseData.h"
ParseData::ParseData()
{
	address = " ";
	data = " ";
	size = " ";
	cycle = " ";
}


ParseData::ParseData(string line)
{
	istringstream ss(line);
	ss.ignore(82);
	ss >> address >> data >> size >> cycle;
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


const void ParseData::print()
{
	cout << address << endl << cycle << endl << data << endl << size;
}

