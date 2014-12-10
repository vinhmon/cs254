#include "ParseField.h"



ParseField::ParseField()
{
	count = 0;
	head = NULL;
	last = NULL;
	forward = true;
}

ParseField::~ParseField()
{
}

const void ParseField::printParse(ofstream & outFile, int order)
{
	Node1 *current;
	current = head;

	int currentWordNum, currentLineNum;
	string currentString;
	unsigned long int extractInt;
	
	if (order == 1)
	{
		if (forward == true)
		{

			while (current != NULL)
			{
				currentLineNum = current->data.getLineNum();
				currentWordNum = current->data.getWordNum();
				currentString = current->data.getWordBinary();
				if (currentWordNum == 41)
				{
					extractInt = std::bitset<7>(currentString.substr(1, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;
				}
				else if (currentWordNum == 40)
				{
					extractInt = std::bitset<1>(currentString[8]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 38)
				{
					extractInt = std::bitset<1>(currentString[1]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 37)
				{
					extractInt = std::bitset<1>(currentString[0]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 32)
				{
					extractInt = std::bitset<15>(currentString.substr(1, 15)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;
				}
				else if (currentWordNum == 22)
				{
					extractInt = std::bitset<1>(currentString[12]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 15)
				{
					extractInt = std::bitset<1>(currentString[11]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 10)
				{

					extractInt = std::bitset<5>(currentString.substr(0, 5)).to_ulong();
					//cout << currentString << " " << current->data.getWordHex();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;
				}
				else if (currentWordNum == 5)
				{
					extractInt = std::bitset<7>(currentString.substr(9, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;
				}
				else if (currentWordNum == 4)
				{
					extractInt = std::bitset<1>(currentString[15]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 1)
				{
					extractInt = std::bitset<3>(currentString.substr(0, 3)).to_ulong();
					if (extractInt == 4)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;
					}
					else if (extractInt == 6)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 0)
				{
					extractInt = std::bitset<2>(currentString.substr(1, 2)).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;
					}
					else if (extractInt == 2)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;
					}
					else if (extractInt == 3)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;
					}
				}
				current = current->next;
			}
		}
		else if (forward == false)
		{
			while (current != NULL)
			{

				currentLineNum = current->data.getLineNum();
				currentWordNum = current->data.getWordNum();
				currentString = current->data.getWordBinary();

				if (currentWordNum == 0)
				{
					extractInt = std::bitset<2>(currentString.substr(1, 2)).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;
					}
					else if (extractInt == 2)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;
					}
					else if (extractInt == 3)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 1)
				{
					extractInt = std::bitset<3>(currentString.substr(0, 3)).to_ulong();
					if (extractInt == 4)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;
					}
					else if (extractInt == 6)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 4)
				{
					extractInt = std::bitset<1>(currentString[15]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 5)
				{
					extractInt = std::bitset<7>(currentString.substr(9, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;
				}
				else if (currentWordNum == 10)
				{
					extractInt = std::bitset<5>(currentString.substr(0, 5)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;
				}
				else if (currentWordNum == 15)
				{
					extractInt = std::bitset<1>(currentString[11]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 22)
				{
					extractInt = std::bitset<1>(currentString[12]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 32)
				{
					extractInt = std::bitset<15>(currentString.substr(1, 15)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;
				}
				else if (currentWordNum == 37)
				{
					extractInt = std::bitset<1>(currentString[0]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 38)
				{
					extractInt = std::bitset<1>(currentString[1]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 40)
				{
					extractInt = std::bitset<1>(currentString[8]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 41)
				{
					extractInt = std::bitset<7>(currentString.substr(1, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;
				}
				/////endasdfaseraser
				
				current = current->next;
			}

		}
	}
	else
	{
		if (forward == true)
		{

			while (current != NULL)
			{
				currentLineNum = current->data.getLineNum();
				currentWordNum = current->data.getWordNum();
				currentString = current->data.getWordBinary();
				if (currentWordNum == 0)
				{
					extractInt = std::bitset<2>(currentString.substr(1, 2)).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;
					}
					else if (extractInt == 2)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;
					}
					else if (extractInt == 3)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 1)
				{
					extractInt = std::bitset<3>(currentString.substr(0, 3)).to_ulong();
					if (extractInt == 4)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;
					}
					else if (extractInt == 6)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 4)
				{
					extractInt = std::bitset<1>(currentString[15]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 5)
				{
					extractInt = std::bitset<7>(currentString.substr(9, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;
				}
				else if (currentWordNum == 10)
				{
					extractInt = std::bitset<5>(currentString.substr(0, 5)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;
				}
				else if (currentWordNum == 15)
				{
					extractInt = std::bitset<1>(currentString[11]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 22)
				{
					extractInt = std::bitset<1>(currentString[12]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 32)
				{
					extractInt = std::bitset<15>(currentString.substr(1, 15)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;
				}
				else if (currentWordNum == 37)
				{
					extractInt = std::bitset<1>(currentString[0]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 38)
				{
					extractInt = std::bitset<1>(currentString[1]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 40)
				{
					extractInt = std::bitset<1>(currentString[8]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 41)
				{
					extractInt = std::bitset<7>(currentString.substr(1, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;
				}
				current = current->next;
			}
		}
		else if (forward == false)
		{
			while (current != NULL)
			{

				currentLineNum = current->data.getLineNum();
				currentWordNum = current->data.getWordNum();
				currentString = current->data.getWordBinary();

				if (currentWordNum == 41)
				{
					extractInt = std::bitset<7>(currentString.substr(1, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Code = " << extractInt << endl;
				}
				else if (currentWordNum == 40)
				{
					extractInt = std::bitset<1>(currentString[8]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Crtl_Enable = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 38)
				{
					extractInt = std::bitset<1>(currentString[1]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Test = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 37)
				{
					extractInt = std::bitset<1>(currentString[0]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (even)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (odd)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Parity = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 32)
				{
					extractInt = std::bitset<15>(currentString.substr(1, 15)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Samples = " << extractInt << endl;
				}
				else if (currentWordNum == 22)
				{
					extractInt = std::bitset<1>(currentString[12]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Right)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (Left)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Direction = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 15)
				{
					extractInt = std::bitset<1>(currentString[11]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 1)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Reset_Enable = " << extractInt << " (unknown)" << endl;
					}

				}
				else if (currentWordNum == 10)
				{

					extractInt = std::bitset<5>(currentString.substr(0, 5)).to_ulong();
					//cout << currentString << " " << current->data.getWordHex();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Num_Responses = " << extractInt << endl;
				}
				else if (currentWordNum == 5)
				{
					extractInt = std::bitset<7>(currentString.substr(9, 7)).to_ulong();
					outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;

					//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_ID = " << extractInt << endl;
				}
				else if (currentWordNum == 4)
				{
					extractInt = std::bitset<1>(currentString[15]).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (disable)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (enable)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Raw = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 1)
				{
					extractInt = std::bitset<3>(currentString.substr(0, 3)).to_ulong();
					if (extractInt == 4)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type A)" << endl;
					}
					else if (extractInt == 5)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type B)" << endl;
					}
					else if (extractInt == 6)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (Type C)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Cmd_Type = " << extractInt << " (unknown)" << endl;
					}
				}
				else if (currentWordNum == 0)
				{
					extractInt = std::bitset<2>(currentString.substr(1, 2)).to_ulong();
					if (extractInt == 0)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no recording)" << endl;
					}
					else if (extractInt == 2)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (no processing)" << endl;
					}
					else if (extractInt == 3)
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (processing & recording)" << endl;
					}
					else
					{
						outFile << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;

						//cout << "Line " << currentLineNum << ": Word " << currentWordNum << ": Rec_Ctrl = " << extractInt << " (unknown)" << endl;
					}
				}
				current = current->next;
			}

		}
	}
	
	
}


void ParseField::insert(word data)
{
	Node1 *newNode;
	newNode = new Node1;
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

const void ParseField::print()
{
	if (head == NULL)
	{
		cerr << "Error";
	}
	else
	{
		Node1 *current;
		current = head;
		while (current != NULL)
		{
			cout << "Line " << current->data.getLineNum() << ": Word " << current->data.getWordNum() << " :" << current->data.getWordHex() << endl; //it->substr(0,4)
			current = current->next;
		}
	}
}




void ParseField::setForward(bool data)
{
	forward = data;
}

