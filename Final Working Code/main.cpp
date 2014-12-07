using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ParseData.h"
#include "ParseList.h"



void inputData(ParseList & data);

int main()
{
	ParseList list;
	inputData(list);
	list.printParse();




	cout << endl;
}


void inputData(ParseList & data)
{
	int currentLineNum = 2;
	string line; //string where getline 
	ParseData temp;
	string address, dataType, size, cycle; 

	string dummyline;
		
	ifstream readFile("test_data.log"); //read test file

	getline(readFile, dummyline); //read the first line into dummyline to skip first line

	if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
			temp.setAll(line);
			temp.setLineNum(currentLineNum);
			data.insertBack(temp);
			
			currentLineNum++;		
	
		}
		readFile.close();

	}
	else
	{
		cerr << "No File Found!";
	}
}

