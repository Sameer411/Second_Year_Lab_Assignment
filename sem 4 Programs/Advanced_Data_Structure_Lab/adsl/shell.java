import java.util.Scanner;
import java.io.*; 
public class shell 
{
	static void display(int arr[]) 
	{
		int i;
		int n=arr.length;
	for(i=0;i<n;i++)
		System.out.print(arr[i]+" ");
	System.out.println();
	}
	static int sort(int arr[]) 
	{
		int i,j,gap,temp;
		int n=arr.length;
		for(gap=n/2;gap>0;gap/=2)
		{
			for(i=gap;i<n;i++)
			{
				for(j=i-gap;j>=0 && arr[j]>arr[j+gap];j-=gap)
				{
					temp=arr[j];
					arr[j]=arr[j+gap];
					arr[j+gap]=temp;
				}
			}
		System.out.print("Pass "+gap+":");
		for(int k=0;k<n;k++)
			System.out.print(" "+arr[k]+" ");
		System.out.println();
		}
		return 0;
	}
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no. of elements:");
		int n=sc.nextInt();
		int arr[]=new int[n];
		int i;
		System.out.println("Enter the elements:");
		for(i=0;i<n;i++)
			arr[i]=sc.nextInt();
		System.out.println("Array before sorting:");
		display(arr);
		sort(arr);
		System.out.println("\nAfter sorting :");
		display(arr);
	
	}
}


