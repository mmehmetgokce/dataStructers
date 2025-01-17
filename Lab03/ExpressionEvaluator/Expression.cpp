#include <string>
#include <sstream>
#include <iostream>
#include <stack>

using namespace std;

// Function to determine the precedence of operators
int precedence(char ch) {
    if (ch == '*' || ch == '/') return 2; // Higher precedence for multiplication and division
    if (ch == '+' || ch == '-') return 1; // Lower precedence for addition and subtraction
    return 0;
}

///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string& s) {
    stack<char> op;  // Stack to hold operators
    stringstream ss(s);
    string result;
    char token;

    // Loop through each character in the input string
    for (size_t i = 0; i < s.size(); ++i) {
        token = s[i];

        // If the token is a digit, add it to the result
        if (isdigit(token)) {
            result += token;
            // Add space after a number if the next character is not a digit
            if (i == s.size() - 1 || !isdigit(s[i + 1])) {
                result += ' ';
            }
        }
        // If the token is an opening parenthesis, push it onto the stack
        else if (token == '(') {
            op.push(token);
        }
        // If the token is a closing parenthesis, pop from stack until '(' is found
        else if (token == ')') {
            while (!op.empty() && op.top() != '(') {
                result += op.top();
                result += ' ';
                op.pop();
            }
            if (!op.empty()) op.pop(); // Remove the '(' from the stack
        }
        else if (token == ' ') {
            continue; // Ignore spaces
        }
        else {
            // Pop operators from the stack while they have higher or equal precedence
            while (!op.empty() && precedence(op.top()) >= precedence(token)) {
                result += op.top();
                result += ' ';
                op.pop();
            }
            op.push(token); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!op.empty()) {
        result += op.top();
        result += ' ';
        op.pop();
    }
    return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {
    stack<int> operands;  // Stack to hold operands
    stringstream ss(s);
    string str;
    int num1, num2;

    // Process each token in the postfix expression
    while (ss >> str) {
        if (isdigit(str[0])) {
            operands.push(stoi(str)); // Push the operand onto the stack
        }
        else {
            num2 = operands.top(); operands.pop(); // Pop the second operand
            num1 = operands.top(); operands.pop(); // Pop the first operand
            // Perform the operation based on the operator and push the result
            if (str[0] == '+') {
                operands.push(num1 + num2);
            }
            else if (str[0] == '-') {
                operands.push(num1 - num2);
            }
            else if (str[0] == '*') {
                operands.push(num1 * num2);
            }
            else if (str[0] == '/') {
                operands.push(num1 / num2);
            }
            else {
                cout << "ERROR!" << endl;
            }
        }
    }
    return operands.top(); // The final result is on top of the stack
} // end-EvaluatePostfixExpression