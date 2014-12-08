#include "ParseList.h"

ParseList::ParseList()
{
	count = 0;
	head = NULL;
	last = NULL;
	
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
		cerr << "Cannot parse from any empty log!";
	}
	else
	{
		ofstream outFile("output.txt", ofstream::trunc);
		int count = 0;
		Node *current;
		current = head;
		while (current != NULL)
		{
			if (current->data.getAddress() == "40000810")
			{
				if (current->data.getCycle() == "Wr")
				{
					outFile << "Line " << current->data.getLineNum() << ": " << "Write S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;

					cout << "Line " << current->data.getLineNum() << ": " << "Write S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current, outFile);
					}
					else
					{
						outFile << endl;
						cout << endl;
					}
				}
				else
				{
					outFile << "Line " << current->data.getLineNum() << ": " << "Read S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;

					cout << "Line " << current->data.getLineNum() << ": " << "Read S-to-D command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current, outFile);
					}
					else
					{
						outFile << endl;
						cout << endl;
					}
				}
				count++;
			}
			else if (current->data.getAddress() == "40000C18")
			{
				if (current->data.getCycle() == "Wr")
				{
					outFile << "Line " << current->data.getLineNum() << ": " << "Write D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;

					cout << "Line " << current->data.getLineNum() << ": " << "Write D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current, outFile);
					}
					else
					{
						outFile << endl;
						cout << endl;
					}
				}
				else
				{
					outFile << "Line " << current->data.getLineNum() << ": " << "Read D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;

					cout << "Line " << current->data.getLineNum() << ": " << "Read D-to-S command: " << current->data.getDataInt() / 2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current, outFile);
					}
					else
					{
						outFile << endl;
						cout << endl;
					}
				}
				count++;
			}
			current = current->next;
		}
		outFile.close();
		cout << "Number of commands found: " << count << endl;
	}
}

const void ParseList::retrieveAddressFields(Node *current, ofstream & outFile)
{
	list<ParseData> temp;
	bool forward = false;
	
	int numWords = current->data.getDataInt() / 2;
	int numOfRows = current->data.getDataInt() / 4; //number of rows to parse data for fields
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
	ParseField  tempField;
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
		tempField.printParse(outFile);
		outFile << endl;
		cout << endl;
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
		tempField.printParse(outFile);
		outFile << endl;
		cout << endl;
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