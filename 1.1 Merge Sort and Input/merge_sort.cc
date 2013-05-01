// Merge Sort (Integers) and Input
// Bess L. Walker
// 1-31-2012
// Hurrah, new and delete instead of calloc and free

#include <iostream>

using namespace std;

//pre-declarations
int* merge_sort(int* unsorted, int length);
int* merge(int* left, int left_length, int* right, int right_length);
void pprint_intarray(int intarray [], int length);

int main()
{
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	int permut_1_len = 6;
	pprint_intarray(permut_1, permut_1_len);
	cout << endl;
	pprint_intarray(merge_sort(permut_1, permut_1_len), permut_1_len);
	
	cout << endl;
	
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	int permut_2_len = 6;
	pprint_intarray(permut_2, permut_2_len);
	cout << endl;
	pprint_intarray(merge_sort(permut_2, permut_2_len), permut_2_len);
	
	cout << endl;
	
	int permut_3 [] = {3, 1, 31, 10, 1, 5};
	int permut_3_len = 6;
	pprint_intarray(permut_3, permut_3_len);
	cout << endl;
	pprint_intarray(merge_sort(permut_3, permut_3_len), permut_3_len);
	
	cout << endl;
	
	return 0;
}

int*  merge_sort(int* unsorted, int length)
{
	if (unsorted == NULL || length == 0)
	{return NULL;}
	else if (length == 1)
	{return unsorted;}
	
	int* sorted = NULL;
	int split_index = length / 2;  // integer division on purpose
	
	int* left = merge_sort(unsorted, split_index);
	int* right = merge_sort(unsorted + split_index, length - split_index);
	
	sorted = merge(left, split_index, right, length - split_index);
	
	// if left and/or right came from a merge, they need to be deleted
	// that is, if they have length > 1
	if (split_index > 1) { delete left; }
	if (length - split_index > 1) { delete right; }
	
	return sorted;
}

int* merge(int* left, int left_length, int* right, int right_length)
{
	int* merged = new int [left_length + right_length];
	int merged_index = 0;
	int left_index = 0;
	int right_index = 0;
	
	while (left_index < left_length && right_index < right_length)
	{
		if (left[left_index] <= right[right_index])
		{
			merged[merged_index] = left[left_index];
			merged_index++;
			left_index++;
		}
		else
		{
			merged[merged_index] = right[right_index];
			merged_index++;
			right_index++;
		}
	}
	
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

void pprint_intarray(int intarray [], int length)
{
	cout << "[";
	if (length >= 1) { cout << " " << intarray[0]; }
	for(int ii = 1; ii < length; ii++)
	{ cout << ", " << intarray[ii]; }
	cout << "]";
}