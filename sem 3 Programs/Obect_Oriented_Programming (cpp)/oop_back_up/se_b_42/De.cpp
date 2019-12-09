#include<iostream>
#include<deque>
using namespace std;

int main()
{
	char ch='Y';
	int c,m;
	deque<int> d;
	deque<int>:: iterator it;
	do
	{
		cout<<"1.Push_front 2.Push_back 3.Pop_front 4.Pop_back 5.get front 6.get back 7.Display 8.Size\nEnter the choice\n";
		cin>>c;
		
		switch(c)
		{
			case 1: cout<<"Enter the number to add elemenet from front\n";
				cin>>m;
				d.push_front(m);
				break;
				
			case 2: cout<<"Enter the number to add element from back\n";
				cin>>m;
				d.push_back(m);
				break;
				
			case 3: d.pop_front();
				break;
			
			case 4: d.pop_back();
				break;
			
			case 5: cout<<"First element at front is: "<<d.front();
				break;
				
			case 6: cout<<"Last element in deque is: "<<d.back();
				break;
				
			case 7:	cout<<"\n";
				for(it=d.begin();it!=d.end();it++)
				{
					cout<<"\t"<<*it<<"\t";
				}	
				break;
			
			case 8: cout<<"Size of deque: "<<d.size();
				break; 			
		}
		cout<<"\nWant to perform more? Then press y\n";
		cin>>ch;
	}while(ch=='Y' || ch=='y');
}
