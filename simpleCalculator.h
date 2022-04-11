
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
}


int evaluate(string tokens) {
    int i;


    stack <int> values;
    stack <char> ops;

    for (i = 0; i < tokens.length(); i++) {


        if (tokens[i] == ' ')         
            continue;           


        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }


        else if (isdigit(tokens[i])) {
            int val = 0;

            while (i < tokens.length() &&
                isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);

            i--;
        }


        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            
            if (!ops.empty())
                ops.pop();
        }

       
        else
        {
        
            while (!ops.empty() && precedence(ops.top())
                >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

           
            ops.push(tokens[i]);
        }

        
        

    }

 
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    
    return values.top();
}

bool IsThereContents(string input)
{

    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            return true;
    }

    return false;
}

bool valid(string input)
{
    stack<char> openParenthesis;
    stack<char> closedParenthesis;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
            openParenthesis.push(input[i]);
        else if (input[i] == ')')
            closedParenthesis.push(input[i]);
    }
    if (openParenthesis.size() == closedParenthesis.size() && IsThereContents(input)== true)
        return true;
    else
        return false;

}

void simpleCalculator()
{
    char parentheses = '(';
    char parentheses2 = ')';
    string answer = inputString("Please enter an expression with proper parenthesis: ",true);

    bool result = find(answer.begin(), answer.end(), parentheses2) != answer.end();
    bool result2 = find(answer.begin(), answer.end(), parentheses) != answer.end();
    for (int  i = 0; i < answer.size(); i++)
    {
        if (isalpha(answer[i]))
        {
            cout << "ERROR: Invalid arithmetic expression." << endl;
            return;
        }
    }
    if (!valid(answer))
    {
        cout << "ERROR: Invalid arithmetic expression." << endl;
        return;
    }
    else if (result and result2)
    {
        cout << evaluate(answer) << "\n";
    }
    else
    {
        cout << "Not balanced parentheses.";
    }
}
