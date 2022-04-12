
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

//This entire code is an expression validation

bool valDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool valOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^');
}

int getPriority(char c)
{
	switch (c)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(': 
		case ')': return 4;
		default: return -1;
	}
}

bool evaluate(string s)
{
	int val = 0;
	int index = 0;
	int parCount = 0;
	int valCount = 0;
	int negCount = 0;
	bool completeVal = false;
	bool validExpress = true;
	while (index < s.length())
	{
		if (validExpress == false)
		{
			break;
		}
		char position = s[index];
		if (valDigit(position) == false && valOperator(position) == false && position != ' ')
		{
			cout << "Invalid expression due to use of illegal elements, please create a valid expression without characters." << endl;
			validExpress = false;
		}
		if (position == ' ')
		{
			index++;
			position = s[index];
		}
		if (valDigit(position))
		{
			if (completeVal == true)
			{
				completeVal = false;
			}
		}
		else if (valOperator(position))
		{
			if (position != '(' || position != ')')
			{
				if (completeVal == false)
				{
					valCount = valCount++;
					completeVal = true;
				}
			}
			if (position == '-')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					if (s[index - 1] != '*' || s[index - 1] != '/' || s[index - 1] != '^')
					{
						cout << "Invalid expression due to excess use of operators." << endl;
						validExpress = false;
					}
				}
				else
				{
					valCount = valCount--;
				}
			}
			if (position == '+')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators." << endl;
					validExpress = false;
				}
				else
				{
					valCount = valCount--;
				}
			}
			if (position == '*')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators." << endl;
					validExpress = false;
				}
				else
				{
					valCount = valCount--;
				}
			}
			if (position == '/')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators." << endl;
					validExpress = false;
				}
				else
				{
					valCount = valCount--;
				}
			}
			if (position == '^')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators." << endl;
					validExpress = false;
				}
				else
				{
					valCount = valCount--;
				}
			}
			if (position == '(')
			{
				parCount = parCount++;
			}
			else if (position == ')')
			{
				//checks for use without a '(' preceding operator
				if (parCount == 0)
				{
					cout << "Invalid expression due to ')', please ensure the use of parantheses is legal." << endl;
					validExpress = false;
				}
				if (parCount != 0)
				{
					parCount = parCount--;
				}
			}
		}
		index++;
	}
	//unequal parantheses check after reading string
	if (parCount != 0)
	{
		if (validExpress == true)
		{
			cout << "Invalid expression due to excess use of parantheses, please create a valid expression" << endl;
			validExpress = false;
		}
	}
	return validExpress;
}
