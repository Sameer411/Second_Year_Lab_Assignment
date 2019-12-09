import java.util.Scanner;
public class assi2
{
	public static void main(String[] args)
	{
		Scanner a=new Scanner (System.in);
		System.out.print("\nEnter the number of elements in an array :- ");
		int n=a.nextInt();
		int array[]=new int[n];
		System.out.print("\nEnter the elements :- ");
		for(int i=0;i<n;i++)
		{
			array[i]=a.nextInt();
		}
		System.out.print("\nelements are :-");
		for(int i=0;i<n;i++)
		{
			System.out.println(array[i]);
		}
	}
}
