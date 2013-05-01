// Merge Sort (Integers) In Place
// Bess L. Walker
// 2-1-12
// Although I'm sure this algorithm exists somewhere, Kaben Nanlohy puzzled
// it out while we were thinking about whether it was possible.  So in my
// head, it's his algorithm.

#include <stdio.h>

int* merge_sort(int* unsorted, int length);
int* merge(int* unsorted, int length, int split_index);

int main()
{
	int permut_1 [] = {0, 1, 2, 3, 4, 5};
	int permut_1_length = 6;
	
	
	int permut_2 [] = {5, 4, 3, 2, 1, 0};
	int permut_2_length = 6;
	
	return 0;
}

// This in-place merge sort modifies the array passed to it,
// and also returns that array.
int* merge_sort(int* unsorted, int length)
{
	if (unsorted == NULL || length == 0)
	{ return NULL; }
	else if (length == 1)
	{ return unsorted; }
	
	int split_index = length / 2;  // integer division on purpose
	
	int* left = unsorted;
	merge_sort(left, split_index);
	
	int* right = unsorted + split_index;
	merge_sort(right, length - split_index);
	
	return merge(unsorted, length, split_index);
}

// The merge is the tricky thing to do in place, of course.
// unsorted must have subsets [0, split_index) and [split_index, length)
// both in sorted order; merge merges these so that the whole array is in
// sorted order.
//
// One could simply recalculate split_index instead of passing it in,
// but this way if for some reason the calculation of split_index changes,
// one does not have to remember to update it here too.
int* merge(int* unsorted, length, split_index)
{
	// The luxury of a little swap space
	// Because let's face it, xor swap is cool but not super-readable
	int temp = 0; // not a good flag value, but I suppose it should be initialized to SOMETHING
	
	// This method uses three interleaved circular arrays
	// One begins as the left subarray, which is sorted.  It remains sorted.
	int left_A_index = 0;
	int left_A_length = split_index;
	// But sometimes it is in two pieces, A and B
	int left_B_index = -1;
	int left_B_length = 0;
	
	// One begins as the right subarray, which is sorted.  It remains sorted.
	int right_A_index = split_index;
	int right_A_length = length - split_index;
	// And is also sometimes in two pieces, A and B
	int right_B_index = -1;
	int right_B_length = 0;
		
	// Also, we are building up the actual sorted part of the array
	int sorted_length = 0
	
	// Round and round and round we go...
	
	while (left_length > 0 && right_length > 0)
	{
		if (unsorted[left_A_index] <= unsorted[right_A_index])
		{
			// Is the left A list immediately following the sorted list?
			// If so, no trouble.
			if (left_A_index == sorted_length)
			{	
				sorted_length++;
				left_A_length--;
				left_A_index++;
				
				// If we've run out of A list, readjust
				// A list is now B list; B list is now empty
				if (left_A_length <= 0)
				{
					left_A_index = left_B_index;
					left_A_length = left_B_length;
					left_B_index = -1;
					left_B_length = 0;
				}
			}
			else  // Things are more complicated.
			{
				// We need to put the first element of the left A list
				// at the sorted_length index, i.e. left_B_index
				temp = unsorted[left_B_index];
				unsorted[left_B_index] = unsorted[left_A_index];
				sorted_length++;
				left_B_index++;
				left_B_length--;
				left_A_index++;
				left_A_length--;
				
				// But what do we do with poor temp?  It has to go
				// back into the left list in sorted order.
				// 1. It can't stay at the head of B -- no space there
				// 2. We don't want to move all of B down to take advantage of 
				//   the current empty space; goodness knows how long it is!
				// 3. There's only one other sorted place it can go --
				//    at the end of A.
				// Sure, there's some right list element using that space, but 
				// fortunately we have just the place to put it...
				// Our empty space, currently at index left_A_index-1
				
				// First, the current right A list becomes its B list
				right_B_index = right_A_index + 1;
				right_B_length = right_A_length - 1;
				
				// Here's the A list, in our storage space
				right_A_index = left_A_index - 1;
				right_A_length = 1;
				unsorted[right_A_index] = unsorted[right_B_index - 1]
				
				// Now we have a sorted place to put temp
				unsorted[left_A_index + left_A_length] = temp;
				left_A_length++;
			}
		}
		else
		{
			// We have got some moving around to do:
			// Save the left value we're replacing
			temp = unsorted[left_A_index];
			// Move the right value into its spot, which is the new end of the sorted list
			unsorted[left_A_index] = unsorted[right_A_index];
			sorted_length++;
			// Now the duplicate value in unsorted[right_index] is storage space
			storage_index = right_A_index;
			right_A_index++;
			right_A_length--;
			storage_length++;
			
			// But now the first element of the sorted left list is at its end,
			// in the storage space!
			// No problem, we'll redefine the beginning and end 
			//    and oh heck the middle as well.
			
			// Now the indices of the old A part are actually the B part
			// of the sorted left list.
			left_B_index = sorted_length - 1;
			left_B_length--;
			
			// And the indices in storage space are the A part!
			left_A_index = storage_index;
			left_A_length++;
			storage_index = -1;
			storage_length--;
		}
	}
}

void insert_from_left(int* unsorted, int& sorted_length, int& left_A_index, int& left_A_length, int& right_A_index, int& right_A_length)
{
	// Is this even possible?  Is there anything in the left list?
	if (left_A_length == 0) { return; }
	
	int temp;

	// If left A list is immediately after the sorted section, no big deal
	if (sorted_length == left_A_index)
	{
		sorted_length++;
		bump_A_index(left_A_index, left_A_length, left_B_index, left_B_length);
	}
	else  // It's time to juggle.
	{
		// Save first element of B list
		// B list doesn't own that spot any more
		temp = unsorted[left_B_index];
		bump_B_index(left_B_index, left_B_length);
		
		// Insert first element of A list into unowned spot
		// Sorted list now owns that spot
		// A list no longer owns its first spot
		unsorted[sorted_length] = unsorted[left_A_index];
		sorted_length++;
		bump_A_index(left_A_index, left_A_length, left_B_index, left_B_length);
		
		// Need someplace to put temp, originally the beginning of B list
		// The only sorted place is the end of the A list
		
		// Which right list immediately follows the left A list?
		if (left_A_length == right_A_index)
		{
			// Put beginning of right A list into unowned spot
			// right A now owns that spot (between left B and left A)
			// the previous right A becomes right B
			// but doesn't own the emptied spot
			unsorted[left_B_length] = unsorted[right_A_index];
			right_B_index = right_A_index;
			right_B_length = right_A_length;
			bump_B_index(right_B_index, right_B_length);
			right_A_index = left_B_length;
			right_A_length = 1;
			
		}
		else // right B list follows; much simpler
		{
			// Put beginning of the right B list into unowned spot
			// This is actually at the end of the right A list, hurrah!
			// Right A list now owns that spot
			// Right B list no longer owns its first spot
			unsorted[right_A_length] = unsorted[right_B_index];
			right_A_length++;
			bump_B_index(right_B_index, right_B_length);
		}
		
		// Now the element after the end of the left A list is unowned
		// temp finally has a home!
		// And the left A list owns this spot now.
		unsorted[left_A_length] = temp;
		left_A_length++;
	}
	
	return 0;
}

void insert_from_right(int* unsorted, int& sorted_length, int& left_A_index, int& left_A_length, int& right_A_index, int& right_A_length)
{
	// Is there a right to insert from?
	if (right_A_length <= 0) { return; }
	
	// Is the right A list immediately following the sorted portion?
	// (This only happens if the left list is empty entirely)
	if (sorted_length == right_A_index)
	{
		// Sorted section now owns the first element of right A list
		sorted_length++;
		bump_A_index(right_A_index, right_A_length, right_B_index, right_B_length);
	}
	else
	{
		// Which left list is immediately following the sorted portion, then?
		if (sorted_length == left_A_index)
		{
			// Save the beginning of the left A list
			// Left A list no longer owns this spot
			temp = unsorted[left_A_index];
			bump_A_index(left_A_index, left_A_length, left_B_index, left_B_length);
			
			// Move the beginning of the right A list to the unowned spot
			// Sorted list owns that spot
			// Right A list no longer owns its first spot
			unsorted[sorted_length] = unsorted[right_A_index];
			sorted_length++;
			bump_A_index(right_A_index, right_A_length, right_B_index, right_B_length);
			
			// Move temp into unowned spot
			// Old left list A becomes left list B
			// Left list A now owns the unowned spot
			unsorted[right_A_index - 1] = temp;
			left_B_index = left_A_index;
			left_B_length = left_A_length;
			left_A_index = right_A_index - 1;
			left_A_length = 1;
			
			// (Note left A list now directly follows left B list, but
			// it's best to keep treating them separately.)
		}
		else
		{
			// Save the beginning of the left B list
			// left B list no longer owns this spot
			temp = unsorted[left_B_index];
			bump_B_index(left_B_index, left_B_length);
		}
	}
}


void bump_B_index(int& B_index, int& B_length)
{
	// Shrink the B list, possibly down to size 0
	// If size 0, make index -1
	B_length--;
	if (B_length <= 0) { B_index = -1; }
	else               { B_index++; }
}

void bump_A_index(int& A_index, int& A_length, int& B_index, int& B_length)
{
	// If we're not going to run off the A section, no worries
	if (A_length > 1)
	{
		A_index++;
		A_length--;
	}
	else  // Not many more worries, really
	{
		// B list becomes A list
		A_index = B_index;
		A_length = B_length;
		// which means no more B list at all
		B_index = -1;
		B_length = 0;
	}
	
	// If B list was empty anyway, A is now also empty.
}
