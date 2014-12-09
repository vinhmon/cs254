using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ParseData.h"
#include "ParseList.h"



void inputData(ParseList & data, string);

int main(int argc, char *argv[])
{
	if(argc != 2)
		cout << "Usage: ./program_name <filename>" << endl;
	else
	{
		string fileName; 
		for (int i = 1; i < argc; i++)
		{		
			fileName += argv[i];
		}

		
		
		ParseList list;
		inputData(list, fileName);
		list.printParse();
	}



	return 0;
}


void inputData(ParseList & data, string fileName)
{
	int currentLineNum = 2;
	string line; //string where getline 
	ParseData temp;
	string address, dataType, size, cycle; 

	string dummyline;
		
	ifstream readFile(fileName.c_str()); //read test file

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
		cerr << "File Unable to Open. Are you sure the filename is correct?" << endl;
	}
}

