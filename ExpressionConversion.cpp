// ExpressionConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Node {
public:
	char data;
	Node* next;

};



class stack
{
private:
	Node* head;
public:
	stack() {
		head = NULL;
	}
	void push(char val) {
		Node* ptr = new Node();
		ptr->data = val;
		ptr->next = head;
		head = ptr;
	}
	char pop() {
		if (isEmpty())
		{
			cout << "Error: Stack is empty. can't pop element." << endl;
		}
		else
		{
			char val = head->data;
			head = head->next;
			return val;
		}
	}
	char top() {
		return head->data;

	}
	char isEmpty() {
		return head == NULL;
	}
};




bool IsOperator(char C)
{

	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$' || C == '^' || C == '%')
		return true;

	return false;
}

void printList(Node* n)
{
	while (n != NULL) {
		{
			cout << n->data;
			break;

		}
	}
}
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	case '^':
		weight = 5;
	case '%':
		weight = 4;
	}

	return weight;
}
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;

		else if (op1 == '-') {
			return false;
		}
		else {
			return true;
		}
	}
	return op1Weight > op2Weight ? true : false;
}
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

string InfixToPostfix(string expression)
{

	stack S;
	string postfix = "";
	for (int i = 0; i < expression.length(); i++) {


		if (expression[i] == ' ' || expression[i] == ',') continue;

		else if (IsOperator(expression[i]))
		{
			while (!S.isEmpty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.isEmpty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.isEmpty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}


int main()
{
	stack in;
	Node* head = NULL;
	string s;
	string temp = "";
	cout << "enter infix expression :";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			in.push('(');
		}
		else if (s[i] == '(') {
			in.push(')');
		}
		else {
			in.push(s[i]);
		}
	}
	while (!in.isEmpty()) {
		temp += in.pop();
	}
	s = temp;
	temp = "";
	string postfix = InfixToPostfix(s);
	cout << "Postfix is :" << postfix << endl;
	for (int i = postfix.length(); i >= 0; i--) {
		temp += postfix[i];
	}
	postfix = temp;
	cout << "Prefix is  :" << postfix << "\n";

	return 0;
}







//        ===================
//#include <iostream>

//int main()
//{
///    std::cout << "Hello World!\n";
//}

// ===========================
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
