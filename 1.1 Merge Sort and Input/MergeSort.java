// Merge Sort (Integers) and Input
// Bess L. Walker
// 12-11-11
// Now in Java.  Do I hate input in Java?  I don't remember.

// Input's not bad.  But I remember one thing I don't like about Java at all:
// everything is an Object... except basic int, bool, etc. types.  So they
// actually turn out to be quite second-class citizens.  ARGH ARGH ARGH.

import java.util.*;
import java.io.*;

public class MergeSort
{
	public static void main(String [] args)
	{
		ArrayList<Integer> permut1 = new ArrayList<Integer>(Arrays.asList(0, 1, 2, 3, 4, 5));
		ArrayList<Integer> permut2 = new ArrayList<Integer>(Arrays.asList(5, 4, 3, 2, 1, 0));
		ArrayList<Integer> permut3 = new ArrayList<Integer>(Arrays.asList(1, 12, 11, 4, 2, 6));
		
		System.out.println(permut1);
		System.out.println(mergeSort(permut1));
		
		System.out.println();
		
		System.out.println(permut2);
		System.out.println(mergeSort(permut2));
		
		System.out.println();
		
		System.out.println(permut3);
		System.out.println(mergeSort(permut3));
		
		System.out.println();
		ArrayList<Integer> unsorted = prompt();
		System.out.println(unsorted);
		System.out.println();
		System.out.println(mergeSort(unsorted));
	}
	
	// Prompts for integers, parses out the real ones from arbitrary input,
	// and returns the list of verified integers (reporting what it returns)
	public static ArrayList<Integer> prompt()
	{
		// Prompt and read
		String string = "";
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Enter a list of integers separated by commas: ");
		
		try
		{
			string = reader.readLine();
		}
		catch (IOException e)
		{
			System.out.println("An error occurred while reading input; exiting.");
			System.exit(0);
		}
		
		//Process
		String [] tokens = string.split(",");
		String token = "";
		ArrayList<Integer> goodList = new ArrayList<Integer>();
		ArrayList<String> badList = new ArrayList<String>();
		for (int ii = 0; ii < tokens.length; ii++)
		{
			token = tokens[ii];
			try
			{
				goodList.add(new Integer(token.trim()));
			}
			catch (NumberFormatException e)
			{
				badList.add(token.trim());
			}
		}
		
		//Report
		System.out.println("Your list of integers is: " + goodList);
		if (!badList.isEmpty())
			System.out.println("Your bad input was filtered out: " + badList);
			
		//Return
		return goodList;
	}
	
	// Uses merge sort to sort an array of integers least to greatest
	// Returns a new array, sorted.
	public static ArrayList<Integer> mergeSort(ArrayList<Integer> unsorted)
	{
		// Base case: arrays of length 0 or 1 are sorted
		if (unsorted.isEmpty() || unsorted.size() == 1)
		{ return unsorted; }
	
		int splitIndex = unsorted.size() / 2;  // integer division on purpose
		
		ArrayList<Integer> left  = mergeSort(new ArrayList<Integer>(unsorted.subList(0, splitIndex)));
		ArrayList<Integer> right = mergeSort(new ArrayList<Integer>(unsorted.subList(splitIndex, unsorted.size())));
		
		ArrayList<Integer> sorted = merge(left, right);
		
		return sorted;
	}
	
	// Merges two least-to-greatest sorted arrays of integers into one
	// new array of integers, still sorted.
	public static ArrayList<Integer> merge(ArrayList<Integer> left, ArrayList<Integer> right)
	{
		ArrayList<Integer> sorted = new ArrayList<Integer>();
		
		int leftIndex = 0, rightIndex = 0;
		
		while (leftIndex < left.size() && rightIndex < right.size())
		{
			if (left.get(leftIndex) <= right.get(rightIndex))
			{
				sorted.add(left.get(leftIndex));
				leftIndex++;
			}
			else
			{
				sorted.add(right.get(rightIndex));
				rightIndex++;
			}
		}
		
		// Kicks in when the right list has been exhausted but the left has not
		if (leftIndex < left.size())
		{
			sorted.addAll(left.subList(leftIndex, left.size()));
		}
		
		// Kicks in when the left list has been exhausted but the right has not
		if (rightIndex < right.size())
		{
			sorted.addAll(right.subList(rightIndex, right.size()));
		}
		
		return sorted;
	}
}