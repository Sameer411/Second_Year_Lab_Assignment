#include<iostream>
#define MAX 30
template<class T>
class stack
{
	public:
		T stk[MAX];
		int top;
		stack()
		{
			top=-1;
		}
		void push(T element);
		T pop();
		int isempty();
		int isfull();
};

template<class T>
void stack<T> :: push(T element)
{
	if(!isfull())
	{
		top++;
		stk[top]=element;
	}
}

template<class T>
T stack<T> :: pop()
{
	if(!isempty())
	{
		T p=stk[top];
		top--;
		return p;
	}
}

template<class T>
int stack<T> :: isempty()
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

template<class T>
int stack<T> :: isfull()
{
	if(top==MAX-1)
		return 1;
	else 
		return 0;
}
