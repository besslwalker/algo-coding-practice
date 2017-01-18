/* Insertion Sort (Integers)
 * Bess L. Walker
 * 11-14-11
 * Java stuff!
 */

public class InsertionSort
{
	public static void main(String args[])
	{
		int[] permut_1 = {0, 1, 2, 3, 4, 5};
		PPrintArray(permut_1);
		InsertionSort(permut_1);
		PPrintArray(permut_1);
		
		System.out.println("\n");
		
		int[] permut_2 = {5, 4, 3, 2, 1, 0};
		PPrintArray(permut_2);
		InsertionSort(permut_2);
		PPrintArray(permut_2);
		
		System.out.println("\n");
		
		int[] permut_3 = {2, 11, 14, 7, 1, 8};
		PPrintArray(permut_3);
		InsertionSort(permut_3);
		PPrintArray(permut_3);
	}
	
	static void InsertionSort(int[] input)
	{
		if (input.length == 0 || input.length == 1)
		{ return; }
		
		for (int ii = 1; ii < input.length; ii++)
		{
			for (int jj = ii; jj > 0 && input[jj] < input[jj - 1]; jj--)
			{
				int temp = input[jj];
				input[jj] = input[jj - 1];
				input[jj - 1] = temp;
//				PPrintArray(input);
			}
		}
	}
	
	/* I don't think I have any way of overwriting int[]'s toString() */
	static void PPrintArray(int[] input)
	{
		String formatted = "";
		
		formatted += "[";
		if (input.length > 0) { formatted += input[0]; }
		for (int ii = 1; ii < input.length; ii++)
		{ formatted += ", " + input[ii]; }
		formatted += "]";
		
		System.out.println(formatted);
	}
}