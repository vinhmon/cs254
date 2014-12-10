#include "ParseList.h"

ParseList::ParseList()
{
	count = 0;
	head = NULL;
	last = NULL;

	sizeOfCommands0 = 0;
	totalTime0 = 0;

	sizeOfCommands1 = 0;
	totalTime1 = 0;

	sizeOfCommands2 = 0;
	totalTime2 = 0;

	sizeOfCommands3 = 0;
	totalTime3 = 0;
	
}

void ParseList::insertFront(ParseData data)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (head == NULL)
	{
		head = newNode;
		last = newNode;
	}
	else
	{
		head->previous = newNode;
		newNode->next = head;
		head = newNode;
	}
		count++;
}

void ParseList::insertBack(ParseData data)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (head == NULL)
	{
		head = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->previous = last;
		last = newNode;
	}
	count++;
}

ParseData ParseList::getParseData()  // testing purposes
{
	return head->data;
}

const void ParseList::print()
{
	if (head == NULL)
	{
		cerr << "Cannot parse from an empty document";
	}
	else
	{
		cout << "Number of objects: " << count << endl;
		Node *current;
		current = head;
		while (current != NULL)
		{
			cout << "Line Number: " << current->data.getLineNum() << " Address: " << current->data.getAddress() << " Data: " << current->data.getData() << " Cycle: " << current->data.getCycle() << endl;
			current = current->next;
		}
	}
}

const void ParseList::printReverse()
{
	if (head == NULL)
	{
		cerr << "Cannot parse from an empty log!";
	}
	else
	{
		cout << "Number of objects: " << count << endl;
		Node *current;
		current = last;
		while (current != NULL)
		{
			cout << "Line Number: " << current->data.getLineNum() << " Address: " << current->data.getAddress() << " Data: " << current->data.getData() << " Cycle: " << current->data.getCycle() << endl;
			current = current->previous;
		}

	}
}

const void ParseList::printParse()
{
	if (head == NULL)
	{
		cerr << "Cannot parse from any empty log!" << endl;
	}
	else
	{
		ofstream outFile("output.txt", ofstream::trunc);
		int count = 0;
		Node *current;
		current = head;
		int numOfRows;

		while (current != NULL)
		{
			numOfRows = current->data.getDataInt() / 4;
			if (current->data.getAddress() == "40000810")
			{
				if (current->data.getCycle() == "Wr")
				{
					retrieveTime(current, numOfRows, 0);
					outFile << "Line " << current->data.getLineNum() << ": " << "Write S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;

					//cout << "Line " << current->data.getLineNum() << ": " << "Write S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						
						retrieveAddressFields(current, outFile, numOfRows, 0);
						
					}
					else
					{
						outFile << endl;
						//cout << endl;
					}
				}
				else
				{
					retrieveTime(current, numOfRows, 2);
					outFile << "Line " << current->data.getLineNum() << ": " << "Read S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;

					//cout << "Line " << current->data.getLineNum() << ": " << "Read S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current, outFile, numOfRows, 0);
					}
					else
					{
						outFile << endl;
						//cout << endl;
					}
				}
				count++;
			}
			else if (current->data.getAddress() == "40000C18")
			{
				if (current->data.getCycle() == "Wr")
				{
					retrieveTime(current, numOfRows, 1);
					outFile << "Line " << current->data.getLineNum() << ": " << "Write D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;
					//cout << "Line " << current->data.getLineNum() << ": " << "Write D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
												
						retrieveAddressFields(current, outFile, numOfRows, 1);
					}
					else
					{
						outFile << endl;
						//cout << endl;
					}
				}
				else
				{
					retrieveTime(current, numOfRows, 3);
					outFile << "Line " << current->data.getLineNum() << ": " << "Read D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;

					//cout << "Line " << current->data.getLineNum() << ": " << "Read D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						
						retrieveAddressFields(current, outFile, numOfRows, 1);
					}
					else
					{
						outFile << endl;
						//cout << endl;
					}
				}
				count++;
			}
			current = current->next;
		}
		
		outFile << std::setprecision(2) << fixed;
		outFile << endl;
		outFile << "Read S-to-D: " << (sizeOfCommands2 * 32 * 1e-6) / totalTime2 << " Megabits/sec" << endl;
		outFile << "Read D-to-S: " << (sizeOfCommands3 * 32 * 1e-6) / totalTime3 << " Megabits/sec" << endl;
		outFile << "Write S-to-D: " << (sizeOfCommands0 * 32 * 1e-6) / totalTime0 << " Megabits/sec" << endl;
		outFile << "Write D-to-S: " << (sizeOfCommands1 * 32 * 1e-6) / totalTime1 << " Megabits/sec" << endl;
		
		outFile.close();
		
	}
}


const void ParseList::retrieveTime(Node *current, int numOfRows, int type)
{
	double *total;
	double *totalTime;

	if (type == 0)
	{
		//cout << "test1" << endl;
		total = &sizeOfCommands0;
		totalTime = &totalTime0;
	}
	else if (type == 1)
	{
		//cout << "test" << endl;
		total = &sizeOfCommands1;
		totalTime = &totalTime1;
	}
	else if (type == 2)
	{
		total = &sizeOfCommands2;
		totalTime = &totalTime2;
	}
	else if (type == 3)
	{
		total = &sizeOfCommands3;
		totalTime = &totalTime3;
	}
	else
	{
		total = nullptr;
		totalTime = nullptr;
	}


	//cout << numOfRows << endl;
	Node *currentTime = current->next;
	for (int i = 0; i < numOfRows + 1; i++)
	{
		//cout << currentTime->data.getTime() << endl;
		*totalTime += currentTime->data.getTime();
		currentTime = currentTime->next;
		//cout << *totalTime << endl << *total << endl;
	}
	*total += numOfRows + 1;

	

	
}


const void ParseList::retrieveAddressFields(Node *current, ofstream & outFile, int numOfRows, int wordOrdering)
{
	list<ParseData> temp;
	bool forward = false;
	int numWords = current->data.getDataInt() / 2;
	//int numOfRows = current->data.getDataInt() / 4; //number of rows to parse data for fields
	current = current->next; //increment to row below command to parse

	if (current->data.getAddress() == "40000818" || current->data.getAddress() == "40000C20")
	{
		forward = true;
	}

	for (int i = 0; i < numOfRows; i++)
	{
		temp.push_back(current->data);


		current = current->next;

	}


	int wordPos = 0;
	word tempWord;
	ParseField tempField;
	if (wordOrdering == 1)
	{
		if (!forward)// reverse 5-4-3-2-1
		{
			tempField.setForward(true);
			wordPos = 0;
			for (list<ParseData>::iterator it = temp.begin(); it != temp.end(); it++)
			{

				tempWord.setAll(it->getData().substr(0, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				wordPos++;

				tempWord.setAll(it->getData().substr(4, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				wordPos++;

			}
			//tempField.print();
			tempField.printParse(outFile, 1); //1 means high to low
			outFile << endl;
			//cout << endl;
		}
		else //forward 0-1-2-3-4-5 memory address
		{
			tempField.setForward(false);
			wordPos = numWords - 1;
			for (list<ParseData>::iterator it = temp.begin(); it != temp.end(); it++)
			{
				tempWord.setAll(it->getData().substr(4, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				//cout << "Line " << it->getLineNum() << ": Word " << wordPos << " :" << it->getData().substr(0, 4) << endl; //it->substr(0,4)
				wordPos--;

				tempWord.setAll(it->getData().substr(0, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				//cout << "Line " << it->getLineNum() << ": Word " << wordPos << " :" << it->getData().substr(4, 7) << endl;
				wordPos--;

			}
			//tempField.print();
			tempField.printParse(outFile, 1);
			outFile << endl;
			//cout << endl;
		}
			
	}
	else
	{
		if (!forward)// reverse 5-4-3-2-1
		{
			tempField.setForward(false);
			wordPos = numWords - 1;
			for (list<ParseData>::iterator it = temp.begin(); it != temp.end(); it++)
			{
				tempWord.setAll(it->getData().substr(4, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				//cout << "Line " << it->getLineNum() << ": Word " << wordPos << " :" << it->getData().substr(0, 4) << endl; //it->substr(0,4)
				wordPos--;

				tempWord.setAll(it->getData().substr(0, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				//cout << "Line " << it->getLineNum() << ": Word " << wordPos << " :" << it->getData().substr(4, 7) << endl;
				wordPos--;

			}
			//tempField.print();
			tempField.printParse(outFile, 0); //0 means low-to-high
			outFile << endl;
			//cout << endl;
		}
		else //forward 0-1-2-3-4-5 memory address
		{
			tempField.setForward(true);
			wordPos = 0;
			for (list<ParseData>::iterator it = temp.begin(); it != temp.end(); it++)
			{

				tempWord.setAll(it->getData().substr(0, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				wordPos++;

				tempWord.setAll(it->getData().substr(4, 4), wordPos, it->getLineNum());
				tempField.insert(tempWord);
				wordPos++;

			}
			//tempField.print();
			tempField.printParse(outFile, 0);
			outFile << endl;
			//cout << endl;
		}
	}
	//testing purposes
	
}

const int ParseList::getCount()
{
	return count;
}

ParseList::~ParseList()
{

}