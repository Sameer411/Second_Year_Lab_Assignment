#include<iostream>
using namespace std;
class cpparray
{
	public:
		int cp1[20],size;
		void read();
		void display();
		int range();
		friend istream & operator>>(istream &ip,cpparray &aobj);
		friend ostream & operator<<(ostream &op,cpparray &aobj);
		void operator = (cpparray right);
		int & operator [] (int subscript);
		cpparray(int s,int)
		{
			int i;
			size=s;
			for(i=0;i<size;i++)
			{
				cp1[i]=0;
			}
		}
		~cpparray()
		{
		};
};
void cpparray :: read()
{
	cout<<"Enter elements of array:";
	int i;
	for(i=0;i<size;i++)
	{
		cin>>cp1[i];
	}
}
void cpparray :: display()
{
	cout<<" Array is:";
	int i;
	for(i=0;i<=size;i++)
	{
		cout<<cp1[i]<<"\t";
	}
	cout<<"\n";
}
int cpparray :: range()
{
	int n;
	cout<<"Enter the total no of elements in array:"<<endl;
	cin>>n;
	if(n>size)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
istream &operator>>(istream &ip,cpparray &aobj)
{
	cout<<"array is:\n";
	for(int i=0;i<aobj.size;i++)
	{
		ip>>aobj.cp1[i];
	}
	return ip;
}
ostream &operator<<(ostream &op,cpparray &aobj)
{
	cout<<"enter the elements of the array\n";
	for(int i=0;i<aobj.size;i++)
	{
		op<<aobj.cp1[i]<<"\t";
	}
	return op;
}
void cpparray::operator=(cpparray right)
{
	size=right.size;
	for(int i=0;i<size;i++)
	{
		cp1[i]=right.cp1[i];
	}
}
int &cpparray::operator[](int subscript)
{
	int ip;
	if(subscript<0)
	{
		cout<<"error: index of the array should be positive\n";
		return cp1[size-1];
	}
	if(subscript,ip>=size)
	{
		cout<<"error!!!\n out of range";
	}
	else
		return cp1[subscript];
}
int main()
{
	cpparray cp1(5,0),cp2(5,0);
	int a,n,subscript,ch,f;
	for(f=0;f<5;f++)
	{
		cout<<"	menu\n 1:enter an array\n 2:display an array\n 3:array copy\n 4:range checking\n 5:exit\n";
		cout<<"enter your choise\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cp1.read();
				break;
			}
			case 2:
			{
				cp1.display();
				break;
			}
			case 3:
			{
				cp2=cp1;
				cp2.display();
				break;
			}
			case 4:
			{
				a=cp1.range();
				cp1[3]=66;
				cp1.display();
				while(a==0)
				{
					cout<<"size is extending\n";
					cin>>n;
					a=cp1.range();
				}
				break;
			}
		}
	}
	return 0;
}

