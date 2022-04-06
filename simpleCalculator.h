#pragma once
#include <iostream>
#include <cctype>
#include <cstdlib> 
#include <cstring>
#include <stack>
#include "input.h"

using namespace std;


void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
{
	double operand1, operand2;
	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();
	switch (operations.top())
	{
	case '+': numbers.push(operand1 + operand2);
		break;
	case '-': numbers.push(operand1 - operand2);
		break;
	case '*': numbers.push(operand1 * operand2);
		break;
	case '/': numbers.push(operand1 / operand2);
		break;
	}
	operations.pop();
}

double read_and_evaluate(istream& ins)
{
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';

	

	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n')
	{
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL))
		{
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL)
		{
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHT_PARENTHESIS)
		{
			ins.ignore();
			evaluate_stack_tops(numbers, operations);
		}
		else
			ins.ignore();
			
		
	}
	return numbers.top();
}



int main()
{
	double answer;
	cout << "Enter a expression: ";
	answer = read_and_evaluate(cin);
	cout << "Evaluates to: " << answer << endl;

}
