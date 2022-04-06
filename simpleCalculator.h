
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

int main()
{
    string answer;
    char parentheses = '(';
    char parentheses2 = ')';
    cout << "Please enter an expression with balanced parentheses: ";
    cin >> answer;

    bool result = find(answer.begin(), answer.end(), parentheses2) != answer.end();
    bool result2 = find(answer.begin(), answer.end(), parentheses) != answer.end();
    if (result and result2)
    {
        cout << evaluate(answer) << "\n";
    }
    else
    {
        cout << "Not balanced parentheses.";
    }
   
    return 0;
}
