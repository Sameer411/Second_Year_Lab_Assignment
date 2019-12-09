#include<iostream>
#include<stack>
#include<string>

using namespace std;
string infix_postfix(string expression);

int precedence(char operator1, char operator2);

bool operator_check(char C);

bool operand_check(char C);

string infix_postfix(string expression)
{
	stack<char> S;
	string postfix = "";
	for(int i = 0;i< expression.length();i++) 
	{
		if(expression[i] == ' ' || expression[i] == ',') 
		continue;  
			else if(operator_check(expression[i])) 
			{
				while(!S.empty() && S.top() != '(' && precedence(S.top(),expression[i]))
				{
					postfix+= S.top();
					S.pop();
				}
				S.push(expression[i]);
			}
			else if(operand_check(expression[i]))
			{
				postfix +=expression[i];
			}
	
			else if (expression[i] == '(') 
			{
				S.push(expression[i]);
			}

			else if(expression[i] == ')') 
			{
				while(!S.empty() && S.top() !=  '(') 
				{
					postfix += S.top();
					S.pop();
				}
				S.pop();
			}
	}		

	while(!S.empty()) 
	{
		postfix += S.top();
		S.pop();
	}

	return postfix;
}
bool operand_check(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
bool operator_check(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
	{
		return true;
	}
	return false;
}
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
		case '+':
			break;
		case '-':
			weight = 2;
			break;
		case '*':
			weight = 3;
			break;
		case '/':
			weight = 1;
			break;
		
		case '^':
			weight = 4;
			break;
	}
	return weight;
}
int precedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
int main() 
{
	string expression; 
	cout<<"Enter Infix Expression \n";
	cin>>expression;
	string postfix = infix_postfix(expression);
	cout<<"\nOutput = "<<postfix<<"\n";
}
