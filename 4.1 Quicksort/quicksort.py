# Quicksort
# Bess L. Walker
# 2-21-12

import random

def quicksort(unsorted):
	real_quicksort(unsorted, 0, len(unsorted))

def real_quicksort(unsorted, low, high):
	if high - low <= 1:
		return

	pivot_index = partition(unsorted, low, high)
	real_quicksort(unsorted, low, pivot_index)
	real_quicksort(unsorted, pivot_index + 1, high)
	
def partition(unsorted, low, high):
	pivot_index = random.randint(low, high - 1) # inclusive of high bound
	pivot_value = unsorted[pivot_index]
	
	# Put pivot value at the end of the partition to keep it out of the way
	unsorted[pivot_index] = unsorted[high - 1]
	unsorted[high - 1] = pivot_value
	
	lowest_high_index = low  # the lowest index of the higher-than-pivot values
	for index in range(low, high - 1):  # don't go through the pivot
		if unsorted[index] < pivot_value:
			# then put it at the end of the lower-than-pivot section
			# unless it is already there
			if not index == lowest_high_index:
				temp = unsorted[lowest_high_index]
				unsorted[lowest_high_index] = unsorted[index]
				unsorted[index] = temp
			lowest_high_index += 1
		
	# The low index of the higher-than-pivot section is where the pivot goes
	unsorted[high - 1] = unsorted[lowest_high_index]
	unsorted[lowest_high_index] = pivot_value
	return lowest_high_index
	
permut_1 = [0, 1, 2, 3, 4 ,5]
print permut_1
quicksort(permut_1)
print permut_1

print

permut_2 = [5, 4, 3, 2, 1, 0]
print permut_2
quicksort(permut_2)
print permut_2

print

permut_3 = [3, 2, 21, 8, 4, 4]
print permut_3
quicksort(permut_3)
print permut_3