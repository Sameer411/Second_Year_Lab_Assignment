#include<iostream>  		
#include <string>
using namespace std;
template <class T>
class temp
{   public:
    T arr[20];
    int size;
    void get_data();
    void display();
    void sort();
    temp()
    {
        size=0;
        
    }
};
template <class T>
void temp<T>::get_data( )
{   cout<<"enter the size of array\n";
    cin>>size; 
    for(int i=0;i<size;i++) 
    {   cout<<"enter the value of"<<i+1<<"element\n";
        cin>>arr[i];
    
    }
}
template <class T>
void temp<T>::display()
{   cout<<"the list is \n";
    for(int i=0;i<size;i++) 
    {   cout<<"\nthe value of"<<i+1<<"element is"<<arr[i]<<"\n";
        
    
    }
}
int main()
{   temp <int> e1;  
    temp <float> e2;   
 
    e1.get_data();
    e1.display();
    return 0;
}
