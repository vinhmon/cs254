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

ParseData ParseList::getParseData()
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
		int count = 0;
		Node *current;
		current = head;
		int numofwords;
		while (current != NULL)
		{
			if (current->data.getAddress() == "40000810")
			{
				if (current->data.getCycle() == "Wr")
				{
					cout << "Line " << current->data.getLineNum() << ":" << "Write S-to-D command: " << current->data.getDataInt() 
						<< " commands, " << (current->data.getDataInt())/2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current);
					}
				}
				else
				{
					cout << "Line " << current->data.getLineNum() << ":" << "Read S-to-D command: " << current->data.getDataInt() 
						<< " commands, " << (current->data.getDataInt())/2 << " words" << endl;
					if (current->data.getDataInt() > 0)
					{
						retrieveAddressFields(current);
					}
					cout << endl;
				}
				count++;
			}
			current = current->next;
		}
		cout << "Number of commands found: " << count;
	}
}

const void ParseList::retrieveAddressFields(Node *current)
{
	list<string> temp;
	int numWords = current->data.getDataInt() / 2;
	int numOfRows = current->data.getDataInt() / 4; //number of rows to parse data for fields
	current = current->next; //increment to row below command to parse

	if (current->data.getAddress() == "40000818")
	{
		for (int i = 0; i < numOfRows; i++)
		{
			temp.push_back(current->data.getData());
			//parse data into field list, need to implement
			//cout << current->data.getData() << endl;

			current = current->next;
			//increment below 
		}
	}
	else
	{
		for (int i = 0; i < numOfRows; i++)
		{
			temp.push_front(current->data.getData());
			//parse data into field list, need to implement
			//cout << current->data.getData() << endl;

			current = current->next;
			//increment below 
		}
	}

	//testing purposes
	int wordPos = 0;
	word tempWord;
	for (list<string>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		string word, word1;
		//tempWord.setAll(*it.substr(0-6))
		word =it->substr(0,4);
		word1=it->substr(4,7);
		string wordcommand;

		findWordCommand(wordPos, wordcommand);
		
		if(wordcommand != "none")
		{
		cout << "Line " << current->data.getLineNum() << ": " << "word " << wordPos << ": " << wordcommand << " = " << word  << endl;
		}
		wordPos++;
		
		
		findWordCommand(wordPos, wordcommand);
		
		if(wordcommand != "none")
		{
		cout << "Line " << current->data.getLineNum() << ": " << "word " << wordPos << ": " << wordcommand << " = " << word1 << endl;
		}
		wordPos++;
		current = current -> next;
	}
	cout << endl;

}

void ParseList::findWordCommand(int wordPos, string &wordcommand)
{
			if (wordPos == 0)
		{
			wordcommand = "Rec_Ctrl";
		}
		else if (wordPos == 1)
		{
			wordcommand = "Cmd_Type";
		}
		else if (wordPos == 4)
		{
			wordcommand = "Rec__Raw";
		}
		else if (wordPos == 5)
		{
			wordcommand = "Cmd_ID";
		}
		else if (wordPos == 10)
		{
			wordcommand = "Num_Responses";
		}
		else if (wordPos == 15)
		{
			wordcommand = "Reset_Enable";
		}
		else if (wordPos == 22)
		{
			wordcommand = "Direction";
		}
		else if (wordPos == 32)
		{
			wordcommand = "Num_Samples";
		}
		else if (wordPos == 37)
		{
			wordcommand = "Parity";
		}
		else if (wordPos == 38)
		{
			wordcommand = "Test";
		}
		else if (wordPos == 40)
		{
			wordcommand = "Ctrl_Enable";
		}
		else if (wordPos == 41)
		{
			wordcommand = "Code";
		}
		else
		{
			wordcommand = "none";
		}

}

const int ParseList::getCount()
{
	return count;
}

ParseList::~ParseList()
{

}