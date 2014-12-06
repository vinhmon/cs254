using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ParseData.h"
#include "ParseList.h"

struct Parse
{
	string address, data, size, cycle;

};

void inputData(ParseList & data);
//ParseData inputDataParse();

int main()
{
	ParseList list;
	inputData(list);
	list.printParse();
	//list.getParseData().print();

	string line = "-330002 3---        2.655us             -11.749s    Start       A32nMBLT         4062E690 FFFCFFF3FFF70007    D64    Wr       Data ----- ----   1111111";
	ParseData dataTest;
	
	dataTest.setAll(line);



	cout << endl;
	system("Pause");
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

