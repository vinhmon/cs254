#include "ParseList.h"

ParseList::ParseList()
{
	count = 0;
	head = NULL;
	
}

void ParseList::insertFront(ParseData data)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
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
		Node *current;
		current = head;

		for (int i = 1; i <= count; i++)
		{
			if (current->data.getAddress() == "40000810")
			{
				if (current->data.getCycle() == "Wr")
				{
					cout << "Line " << current->data.getLineNum() << ":" << "Write S-to-D command: " << current->data.getDataInt() << endl << endl;
				}
				else
				{
					cout << "Line " << current->data.getLineNum() << ":" << "Read S-to-D command: " << current->data.getDataInt() << endl << endl;
				}
			}
			current = current->next;
		}
	}
}

ParseList::~ParseList()
{

}