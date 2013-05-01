# Merge Sort (Integers) and Input
# Bess L. Walker
# 11-17-11
# Python first this time; let's renew familiarity with the algorithm while 
# not also trying to remember the language...

def prompt():
	int_list = []
	bad_list = []

	string = raw_input("Enter a list of integers separated by commas: ")
	
	# Tokenize
	tokens = string.strip()
	tokens = string.split(",")
	
	# Legal?  Add to integer list.	Illegal?  Add to bad input list.
	for token in tokens:
		token = token.strip()
		try:
			integer = int(token)
			int_list.append(integer)
		except:
			bad_list.append(token)
			
	print("Your list of integers is: " + str(int_list))
	if len(bad_list) > 0:
		print("Your bad input was filtered out: " + str(bad_list))
		
	return int_list
				
def merge_sort(unsorted_list):
	length = len(unsorted_list)
	
	if length in [0, 1]:
		return unsorted_list

	index_split = length / 2		# integer division is on purpose

	left = merge_sort(unsorted_list[:index_split])
	right = merge_sort(unsorted_list[index_split:])
	
	sorted_list = merge(left, right)
	
	return sorted_list

# It's not clever, but it will work.
# I'd love to write something more in-place, but I can't seem to do it
# without blowing merge() up to worst-case n^2.
# Oh well, one of the well-known issues with merge sort is that it is not in-place.
def merge(left, right):
	left_index = 0
	right_index = 0

	merged_list = []
	
	while left_index < len(left) and right_index < len(right):
		if left[left_index] <= right[right_index]:
			merged_list.append(left[left_index])
			left_index += 1
		else:
			merged_list.append(right[right_index])
			right_index += 1
		
	if left_index < len(left):
		merged_list += left[left_index:]
		
	if right_index < len(right):
		merged_list += right[right_index:]
			
	return merged_list
	



# At least in this implementation, sorted input doesn't take less time
# than anything else.  Oh well.
permut_1 = [0, 1, 2, 3, 4, 5]
print permut_1
print merge_sort(permut_1)

print

permut_2 = [5, 4, 3, 2, 1, 0]
print permut_2
print merge_sort(permut_2)

print

permut_3 = [5, 11, 17, 11, 5, 3]
print permut_3
print merge_sort(permut_3)

print

unsorted = prompt()
print
print unsorted
print merge_sort(unsorted)
