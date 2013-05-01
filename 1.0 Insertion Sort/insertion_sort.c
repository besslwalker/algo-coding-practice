// Insertion Sort (Integers)
// Bess L. Walker
// 11-9-11
// Reviewing algorithms and coding together through The Algorithm Design Manual

#include <stdio.h>

// declare functions
int insertion_sort(int input[], int input_length);
void pprint_array(int array[], int length);

int main()
{
	int len_permut = 6;
	
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	pprint_array(permut_1, len_permut);
	insertion_sort(permut_1, len_permut);
	pprint_array(permut_1, len_permut);
	
	printf("\n");
	
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	pprint_array(permut_2, len_permut);
	insertion_sort(permut_2, len_permut);
	pprint_array(permut_2, len_permut);
	
	printf("\n");
	
	int permut_3 [] = {2, 11, 14, 1, 0, 2};
	pprint_array(permut_3, len_permut);
	insertion_sort(permut_3, len_permut);
	pprint_array(permut_3, len_permut);
	
	return 0;
}

// Input: An array of numbers
// Output: The sorted (ascending) permutation of that array

int insertion_sort(int input[], int input_length)
{
	if (input_length == 0 || input_length == 1)
	{ return 1; }
	
	int ii;
	for (ii = 1; ii < input_length; ii++)
	{
		int jj;
		for (jj = ii; jj > 0; jj--)
		{
			// Strict < avoids useless swaps
			if (input[jj] < input[jj - 1])
			{
				int temp = input[jj];
				input[jj] = input[jj - 1];
				input[jj - 1] = temp;
			}
			else
			{ break; }
		}
	}
	
	return 1;
}

void pprint_array(int array[], int length)
{
	printf("[");
	if (length > 0) { printf("%d", array[0]); }
	int ii;
	for (ii = 1; ii < length; ii++)
	{ printf(", %d", array[ii]); }
	printf("]\n");
}

