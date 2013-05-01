// Merge Sort (Integers) and Input
// Bess L. Walker
// 1-4-12
//
// I'm not afraid of merge sort here, just input.

#include <stdlib.h>
#include <stdio.h>

int* merge_sort(int* unsorted, int length);
int* merge(int* left, int left_length, int* right, int right_length);

void print_array(int* array, int length);

int main()
{
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	int permut_3 [] = {3, 1, 4, 10, 1, 8};
	int* sorted_permut = NULL;
	
	print_array(permut_1, 6);
	sorted_permut = merge_sort(permut_1, 6);
	print_array(sorted_permut, 6);
	
	printf("\n");
	
	print_array(permut_2, 6);
	sorted_permut = merge_sort(permut_2, 6);
	print_array(sorted_permut, 6);
	
	printf("\n");
	
	print_array(permut_3, 6);
	sorted_permut = merge_sort(permut_3, 6);
	print_array(sorted_permut, 6);
	
	return 0;
}

int* merge_sort(int* unsorted, int length)
{
	// base case
	if (unsorted == NULL || length == 0 || length == 1)
	{return unsorted;}
	
	// recursive case
	int* sorted = (int*) calloc(length, sizeof(int));
	
	int split_index = length / 2;  // integer division on purpose
	
	int* left = unsorted;
	int left_length = split_index;
	
	int* right = unsorted + split_index;
	int right_length = length - split_index;
	
	// recursive calls
	left = merge_sort(left, left_length);
	right = merge_sort(right, right_length);
	
	sorted = merge(left, left_length, right, right_length);
		
	return sorted;
}

int* merge(int* left, int left_length, int* right, int right_length)
{
	int* merged = (int*) calloc(left_length + right_length, sizeof(int));
	int merged_index = 0;
	int left_index = 0;
	int right_index = 0;
	
	while (left_index < left_length && right_index < right_length)
	{
		if (left[left_index] <= right[right_index])
		{
			merged[merged_index] = left[left_index];
			left_index++;
		}
		else
		{
			merged[merged_index] = right[right_index];
			right_index++;
		}
		merged_index++;
	}
	
	// whack any remaining onto the end
	while (left_index < left_length)
	{
		merged[merged_index] = left[left_index];
		merged_index++;
		left_index++;
	}
	while (right_index < right_length)
	{
		merged[merged_index] = right[right_index];
		merged_index++;
		right_index++;
	}
	
	return merged;
}

void print_array(int* array, int length)
{
	printf("[");
	
	if (length > 0)
	{ printf("%d", array[0]); }
	
	int ii = 1;
	for (ii = 1; ii < length; ii++)
	{ printf(", %d", array[ii]); }
	
	printf("]\n");
}