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

	ss.ignore(21);
	ss >> relTime;
	ss.ignore(54);
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
	ss.ignore(19);
	ss >> relTime;
	ss.ignore(54);
	ss >> address >> data >> size >> cycle;
	setTimeSec(relTime);
	return *this;

}

void ParseData::setTimeSec(string relTime)
{
	string::iterator it = relTime.end() - 2;
	char type = *it;

	double value = stod(relTime.substr(0, relTime.length() - 2), nullptr);
	if (type == 'n')
	{
		value *= 1e-9;
	}
	else if (type == 'm')
	{
		value *= 1e-3;
	}
	else if (type == 'u')
	{
		value *= 1e-6;
	}
	else
	{
		cerr << relTime << " is not in nano, micro, or milliseconds" << endl;
	}

	relTimeSec = value;

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

double ParseData::getTime()
{
	return relTimeSec;
}

void ParseData::setLineNum(int newLineNum)
{
	lineNum = newLineNum;
}


const void ParseData::print()
{
	cout << address << endl << cycle << endl << data << endl << size;
}

