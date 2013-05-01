// Insertion Sort (Integers)
// Bess L. Walker
// 11-14-11
// Practicing algorithms & coding using The Algorithm Design Manual

#include <iostream>

using namespace std;

// pre-declarations
bool insertion_sort(int input [], int input_length);
void pprint_array(int array [], int length);

int main()
{
	int len_permut = 6;
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	pprint_array(permut_1, len_permut);
	insertion_sort(permut_1, len_permut);
	pprint_array(permut_1, len_permut);
	
	cout << endl;
	
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	pprint_array(permut_2, len_permut);
	insertion_sort(permut_2, len_permut);
	pprint_array(permut_2, len_permut);
	
	cout << endl;
	
	int permut_3 [] = {2, 11, 14, 1, 1, 6};
	pprint_array(permut_3, len_permut);
	insertion_sort(permut_3, len_permut);
	pprint_array(permut_3, len_permut);
	
	return 0;
}

bool insertion_sort(int input[], int input_length)
{
	if (input_length == 0 || input_length == 1)
	{return true;}
	
	for (int ii = 1; ii < input_length; ii++)
	{
		for (int jj = ii; jj > 0; jj--)
		{
			// Strict < avoids needless swaps
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
	
	return true;
}

void pprint_array(int array [], int length)
{
	cout << "[";
	if (length > 0) { cout << array[0]; }
	for (int ii = 1; ii < length; ii++)
	{ cout << ", " << array[ii]; }
	cout << "]" << endl;
}