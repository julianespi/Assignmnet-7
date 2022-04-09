
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

bool valDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool valOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int getPriority(char c)
{
	switch (c)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '(': 
		case ')': return 3;
		default: return -1;
	}
}

int evaluate(string s)
{
	stack<int> values;
	stack<char> ops;

	int val = 0;
	int index = 0;
	int parCount = 0;
	int valCount = 0;
	bool compeleteVal = false;
	bool validExpress = true;

	if (validExpress == false)
	{
		break;
	}
	while (index < s.length())
	{
		char position = s[index];
		if (valDigit(position) == false && valOperator(position) == false)
		{
			cout << "Invalid expression due to use of illegal elements, please create a valid expression without spaces or characters." << endl;
			validExpress = false;
			break;
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
				values.push(val);
				compeleteVal = true;
			}
			if (position == '-')
			{
				ops.push(position);
				val = 0;
			}
			if (position == '+')
			{
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
					break;
				}
				ops.push(position);
				val = 0;
			}
			if (position == '*')
			{
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
					break;
				}
				ops.push(position);
				val = 0;
			}
			if (position == '/')
			{
				if (valCount == 0)
				{
					cout << "Invalid expression due to excess use of operators before translation to prefix." << endl;
					validExpress = false;
					break;
				}
				ops.push(position);
				val = 0;
			}
			if (position == '(')
			{
				parCount = parCount++;
				ops.push(position);
				val = 0;
			}
			else if (position == ')')
			{
				if (parCount == 0)
				{
					cout << "Invalid expression due to ')', please ensure the use of parantheses is legal." << endl;
					validExpress = false;
					break;
				}
				if (parCount != 0)
				{
					parCount = parCount--;
					ops.push(position);
					val = 0;
				}
			}
		}
		index++;
	}
}