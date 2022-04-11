
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

//This entire code is an expression validation

bool valObject(char c)
{
	if (c >= '0' && c <= '9') return true;
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}

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
	bool completeVal = false;
	bool validExpress = true;
	while (index < s.length())
	{
		if (validExpress == false)
		{
			break;
		}
		char position = s[index];
		if (valObject(position) == false && valOperator(position) == false && position != ' ')
		{
			cout << "Invalid expression due to use of illegal elements, please create a valid expression without spaces or characters." << endl;
			validExpress = false;
		}
		if (position == ' ')
		{
			index++;
			position = s[index];
		}
		if (valObject(position))
		{
			completeVal = false;
		}
		else if (valOperator(position))
		{
			if (completeVal == false)
			{
				valCount = valCount++;
				completeVal = true;
			}
			if (position == '-')
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
					val = 0;
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
					val = 0;
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
					val = 0;
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
					val = 0;
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
					val = 0;
				}
			}
			if (position == '(')
			{
				parCount = parCount++;
				val = 0;
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
					val = 0;
				}
			}
		}
		index++;
	}
	if (validExpress == false)
	{
		return false;
	}
	//unequal parantheses check after reading string
	if (parCount != 0)
	{
		cout << parCount << endl;
		cout << "Invalid expression due to excess use of parantheses, please create a valid expression" << endl;
		return false;
	}
}
