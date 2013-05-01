// Heapsort
// Bess L. Walker
// 2-21-12
// This is a min-heap in plain ol' C

#include<stdio.h>
#include<stdlib.h>

// pre-declarations
int* my_heapsort(int* unsorted, int length);
void build_heap(int* unsorted, int length);
void heapify(int* unsorted, int length, int index);
int extract_min(int* unsorted, int length);
void pprint_array(int array[], int length);

int main()
{
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	pprint_array(permut_1, 6);
	pprint_array(my_heapsort(permut_1, 6), 6);
	
	printf("\n");
	
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	pprint_array(permut_2, 6);
	pprint_array(my_heapsort(permut_2, 6), 6);
	
	printf("\n");
	
	int permut_3 [] = {3, 2, 21, 1, 2, 4};
	pprint_array(permut_3, 6);
	pprint_array(my_heapsort(permut_3, 6), 6);
	
	printf("\n");
	
	return 0;
}

int* my_heapsort(int* unsorted, int length)
{
	build_heap(unsorted, length);
	
	int* sorted = calloc(length, sizeof(int));
	int ii = 0;
	int heap_length = length;
	for (ii = 0; ii < length; ii++)
	{
		sorted[ii] = extract_min(unsorted, heap_length);
		heap_length--;
	}
	
	return sorted;
}

void build_heap(int* unsorted, int length)
{
	int ii = length - 1;
	for (ii = length - 1; ii >= 0; ii--)
	{
		heapify(unsorted, length, ii);
	}
}

void heapify(int* unsorted, int length, int index)
{
	// is this a leaf?  If so, we are done.
	if ((2 * index) + 1 >= length) {return;} 
	
	// does this have only one child?
	if ((2 * index) + 2 >= length)
	{
		if (unsorted[2*index + 1] < unsorted[index])
		{
			int temp = unsorted[index];
			unsorted[index] = unsorted[2*index + 1];
			unsorted[2*index + 1] = temp;
			
			// no need to continue heapifying here; a single child
			// is a leaf in any valid heap structure
		}
	}
	
	// two children; swap up the lower if necessary
	int lesser_child_index = 2*index + 1;
	if (unsorted[2*index + 2] < unsorted[2*index + 1])
	{ lesser_child_index = 2*index + 2; }
	
	if (unsorted[lesser_child_index] < unsorted[index])
	{
		int temp = unsorted[index];
		unsorted[index] = unsorted[lesser_child_index];
		unsorted[lesser_child_index] = temp;
		
		heapify(unsorted, length, lesser_child_index);
	}
}

int extract_min(int* unsorted, int length)
{
	if (length < 1)
	{
		printf("Error: extracting from empty heap.  -1 will be returned.");
		return -1;
	}
	
	int min = unsorted[0];
	
	// fix heap
	unsorted[0] = unsorted[length - 1];
	heapify(unsorted, length - 1, 0);
	
	return min;
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
