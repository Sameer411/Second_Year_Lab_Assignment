#include<iostream>
#include<string.h>
using namespace std;
#define MAX 50
class Stack  
{
	private:
		char data[MAX],str[MAX];
		int top,length,count;
		void push_data(char);
		char pop_data();
	public:
		Stack()
		{
			top=-1;
			length=0;
			count=0;
		}
		void create();
		void check();
		void display();
};

void Stack::create() 
{
	cout<<"\nEnter a String: ";
	cin.getline(str,MAX);
	length=strlen(str);
	cout<<"\nlength of the string is: "<<length;
}
void Stack::check() 
{
	for(int i=0; i<length; i++)
		push_data(str[i]);
		
		for(int i=0; i<length; i++) 
		{
			if(str[i]==pop_data())
			count++;
  		}

	if(count==length) 
	{
		cout<<"\n\nEntered string is a Palindrome. \n";
	}
	else  cout<<"\n\nEntered string is not a Palindrome. \n";
}
void Stack::display()  
	{
		for(int i=length-1; i>=0; i--)
		cout<<str[j];
	}
void Stack::push_data(char temp) 
{
	if(top==MAX-1)  
	{
		cout<<"\n Stack Overflow!!!";
    		return;
  	}
	top++;
	data[top]=temp;
}
char Stack::pop_data() 
{
	if(top==-1)  
	{
		cout<<"\n Stack Underflow!!!";
		char ch='\n';
		return ch;
  	}
	char temp=data[top];
	top--;
	return temp;
	cout<<top;           
}
/*int main()  
{
	Stack obj;
	obj.create();
	cout<<"\n\nReverse of entered string: ";
	obj.display();
	obj.check();
	return 0;
}*/
