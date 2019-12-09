#include<stdio.h>
#include<string.h>
void length(char str1[100],int len,int i);
void reverse(char str1[100],char str2[100],int i,int j,char temp);
void copy();
void upper(int i,char str5[100],char ch);
void lower(char str6[100],char ch,int i);
void concatinate(char str7[100],char str8[100],int i,int j);
void frequency(char str9[100],char ele,int cnt,int i);
void main()
{
	int i=0,len=0,cnt,ch,z,c;
	char str1[100],str2[100],str3[100],str4[100],j,temp,str5[100],str6[100],str7[100],str8[100],str9[100],ele;
		for(z=0;z<8;z++)
	{
		printf("1:string length\n2:reverse of string\n3:copy string\n4:lower to upper\n5:upper to lower\n6:string concatination\n7:check frequency of the element in string\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
//string length
			case 1:
			{
				length(str1,len,i);
			}	
			break;
//string reverse

			case 2:
			{
				reverse(str1,str2,i,j,temp);
			}
			break;
//string copy

			case 3:
			{
				copy();
			}
			break;
//lower to upper

			case 4:
			{
				upper(i,str5,ch);
			}
			break;
//upper to lower
			case 5:
			{
				lower(str6,ch,i);
			}
			break;
//string concatination
			case 6:
			{
				concatinate(str7,str8,i,j);
			}
			break;	
			
			case 7:
			{
				frequency(str9,ele,cnt,i);	
			}
			break;
			default:
			{
				printf("you have selected wrong choice\n");
				printf("\n");
			}
			break;
		}
	}
}	

void length(char str1[],int len,int i)
{
printf("enter the sting to find it's length\n");
			scanf("%s",str1);
			while(str1[i]!='\0')
			{
				++len;
				++i;
			}
			printf("lenth of the string is\n%d\n",len);

}

void reverse(char str1[],char str2[],int i,int j,char temp)
{
	while(str1[i]!='\0')
	{
		str2[i]=str1[i];
		++i;
	}
	printf("enter the string for reverse function\n");
	scanf("%s",str2);
	i=0;
	j=strlen(str2)-1;
	while(i<j)
	{
		temp=str2[i];
		str2[i]=str2[j];
		str2[j]=temp;
		i++;
		j--;
	}
	printf("reverse string is:\n%s\n",str2);
}

void copy()
{
	char str3[100],str4[100];
	int i=0;
	printf("enter string for copy\n");
	scanf("%s",str3);
	while(str3[i]!='\0')
	{
		str4[i]=str3[i];
		i++;
		
	}
	str4[i]!='\0';
	printf("string after copy is:\n");
	printf("%s",str4);
	printf("\n");	
}

void upper(int i,char str5[],char ch)
{
	printf("enter string to change case\n");
	scanf("%s",str5);
	for(i=0;str5[i]!='\0';i++)
	{
		ch=str5[i];
		str5[i]=ch - 32;
	}
	printf("\nLower to Upper case is\n%s\n:",str5);
}

void lower(char str6[],char ch,int i)
{
	printf("enter string to change the case\n");
	scanf("%s",str6);
	for(i=0;str6[i]!='\0';i++)
	{
		ch=str6[i];
		str6[i]=ch + 32;
	}
	printf("\nUpper to lower case is \n%s\n:",str6);
}
void concatinate(char str7[],char str8[],int i,int j)
{
	printf("enter first string for concatinate\n");
	scanf("%s",str7);
	printf("enter second string for concatinate\n");
	scanf("%s",str8);
	for(i=0;str7[i]!='\0';i++)
	{
	}
    	j=i;	
	for(i=0;str8[i]!='\0';i++)
  	{
    		str7[j]=str8[i];
    		j++;
    	}		
   	printf("\nConcatinate is \n%s\n",str7);
}

void frequency(char str9[100],char ele,int cnt,int i)
{
	cnt=0;

	printf("enter the character to check\n");
	scanf("%c",&ele);
	scanf("%c",&ele);

	printf("enter the string to check frequency of the element\n");
	scanf("%s",str9);
	
	for(i=0;str9[i]!='\0';i++)
	{
		if(ele==str9[i])
		{
			cnt++;
		}
	}
	printf("entered charactered is %d times\n",cnt);		
}
