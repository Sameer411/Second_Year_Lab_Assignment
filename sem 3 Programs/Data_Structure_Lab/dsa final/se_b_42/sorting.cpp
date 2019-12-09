#include<iostream>
using namespace std;
int main()
{
	int n, i, arr[50], j, temp,ch;
	cout<<"Enter total number of elements :\n";
	cin>>n;
	cout<<"Enter "<<n<<" numbers :\n";
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}	
	cout<<"1:bubble sort\n2:insertion sort\n3:selection sort\n4:shelll sort\n5:exit\n";
	cout<<"enter your choice\n";
	cin>>ch;
		switch(ch)
		{
			case 1:								//BUBBLE SORT
			{
				for(i=0; i<(n-1); i++)
				{
					for(j=0; j<(n-i-1); j++)
					{
						if(arr[j]>arr[j+1])
						{
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				cout<<"Sorted list using bubble sort is :\n\n";
				for(i=0; i<n; i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<"\n";
			break;
			}
			case 2:								//INSETTION SORT
			{
				int ele;
				for(i=1;i<n;i++)
				{
					ele=arr[i];
					j=i-1;
					while(j>=0 && arr[j]>ele)
					{
						arr[j+1]=arr[j];
						--j;
					}
					arr[j+1]=ele;
				}
				cout<<"Sorted list using insertion sort is :\n\n";
				for(i=0; i<n; i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<"\n";
			break;
			}
			case 3:								//SELECTION SORT
			{
				int min_pos,temp;
				for(i=0;i<n;i++)
				{
					min_pos=i;
					for(j=i+1;j<n;j++)
					{
						if(arr[j]<arr[min_pos])
						min_pos=j;
					}
					if(min_pos!=i)
					{
						temp=arr[i];
						arr[i]=arr[min_pos];
						arr[min_pos]=temp;
					}
				}
				cout<<"Sorted list using selsction sort is :\n\n";
				for(i=0; i<n; i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<"\n";
			}
			case 4:						//SHELL SORT
			{
				int temp,gap;
				int swapped;
				do
				{
					gap=n/2;
					do
					{
						swapped=0;
						for(i=0;i<n-gap;i++)
						{
							if(arr[i]>arr[i+gap])
							{
								temp=arr[i];
								arr[i]=arr[i+gap];
								arr[i+gap]=temp;
								swapped=1;
							}
						}
					}while(swapped==1);
				}while(gap=(gap/2>=1));
				cout<<"Sorted list using selsction sort is :\n\n";
				for(i=0; i<n; i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<"\n";
			}
		}
return 0;
}
