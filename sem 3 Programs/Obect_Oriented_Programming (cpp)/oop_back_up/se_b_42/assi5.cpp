#include<iostream>
#include<string>
using namespace std;

class pro
{   public:
    char spec[20];
    int sal;
    void read();
    void display();
};
void pro::read()
{   cout<<"\nenter the job  specification\n";
    cin>>spec;
    cout<<"\nenter salary\n";
    cin>>sal;

}
void pro::display()
{   cout<<"\nspecification\tsalary\n";
    cout<<"\n"<<spec<<"\t\t"<<sal<<"\n";


}
class acaddemic
{   public:
    float hsc,ssc,be,me;
    void read2();
    void display2();
};
void acaddemic::read2()
{   cout<<"\nenter ssc %\n";
    cin>>ssc;
    cout<<"\nenter hsc %\n";
    cin>>hsc;
    cout<<"\nenter be score\n";
    cin>>be;
    cout<<"\nenter ME score\n";
    cin>>me;
}
void acaddemic::display2()
{   
    cout<<"\nssc\thsc\tbe\tme\n";
    cout<<ssc<<"\t"<<hsc<<"\t"<<be<<"\t"<<me<<"\n";
}
class personal
{   public:
    string name,address;
    char email[15];
    int number,id;
    void read3();
    void display3();
};
void personal ::read3()
{   cout<<"emter the information\n";
    cout<<"\nenter the name\n";
    cin>>name;
    cout<<"\nenter email id\n";
    cin>>email;
    cout<<"\nenter address\n";
    cin>>address;
    cout<<"\nenter contact number\n";
    cin>>number;
    cout<<"\nenter employee ID\n";
    cin>>id;
}    
void personal ::display3()
{
    cout<<"\nname\temail\tnumber\tID\taddress\n";
    cout<<name<<"\t"<<email<<"\t"<<number<<"\t"<<id<<"\t"<<address<<"\n";
}    
class employee:public pro,personal,acaddemic
{   public:   
    void read4()
    {   read();
        read2();
        read3();
    }
    void display4()
    {   display();
        display2();
        display3();
    }    
};
int main()
{   employee e;
    e.read4();
    e.display4();   
    return 0;
}
        
    
    
    
        
    




































   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    







