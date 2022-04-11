
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
	bool compeleteVal = false;
	bool validExpress = true;
	while (index < s.length())
	{
		if (validExpress == false)
		{
			break;
		}
		char position = s[index];
		if (valDigit(position) == false && valOperator(position) == false)
		{
			cout << "Invalid expression due to use of illegal elements, please create a valid expression without spaces or characters." << endl;
			validExpress = false;
		}
		if (valDigit(position))
		{
			compeleteVal = false;
			val = (val * 10) + (int)(position - '0');
		}
		else if (valOperator(position))
		{
			if (completeVal == false)
			{
				valCount = valCount++;
				compeleteVal = true;
				negCount = 0;
			}
			if (position == '-')
			{
				//checks for double negative
				if (negCount != 0)
				{
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
				}
				if (valCount == 0)
				{
					negCount = negCount++;
					val = 0;
				}
			}
			if (position == '+')
			{
				//checks for use without a value preceding operator
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
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
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
					break;
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
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
					break;
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
					break;
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
		break;
	}
	//unequal parantheses check after reading string
	if (parCount != 0)
	{
		cout << "Invalid expression due to excess use of parantheses, please create a valid expression" << endl;
		break;
	}
}