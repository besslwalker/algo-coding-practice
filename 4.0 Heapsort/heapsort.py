# Heapsort
# Bess L. Walker
# 2-21-12
# min-heap

def heapsort(unsorted):
	build_heap(unsorted)
	
	sorted = []
	for index in range(0, len(unsorted)):
		sorted.append(extract_min(unsorted))
		
	return sorted
	
def build_heap(unsorted):
	for index in reversed(range(0, len(unsorted))):
		heapify(unsorted, index)
		
def heapify(unsorted, index):
	# No children?  Nothing to do.
	if (2*index) + 1 >= len(unsorted):
		return
	
	# One child?  Very little to do.
	if (2*index) + 2 >= len(unsorted):
		if unsorted[index] > unsorted[2*index + 1]:
			temp = unsorted[index]
			unsorted[index] = unsorted[2*index + 1]
			unsorted[2*index + 1] = temp
		# No further heapifying necessary; a single child has
		# no children itself in a valid heap.
		return
			
	# Two children?  Perhaps we must recurse.
	smaller_child_index = 2*index + 1
	if unsorted[smaller_child_index] > unsorted[2*index + 2]:
		smaller_child_index += 1
	if unsorted[smaller_child_index] < unsorted[index]:
		temp = unsorted[index]
		unsorted[index] = unsorted[smaller_child_index]
		unsorted[smaller_child_index] = temp
		heapify(unsorted, smaller_child_index)
		
def extract_min(unsorted):
	if len(unsorted) < 1:
		print "ERROR: Attempting to extract from empty heap.  The return value will be None."
		return None
		
	min = unsorted[0]
	
	# Fix heap
	unsorted[0] = unsorted[-1]
	unsorted.pop()
	heapify(unsorted, 0)
	
	return min
	
permut_1 = [0, 1, 2, 3, 4, 5]
print permut_1
print heapsort(permut_1)

print

permut_2 = [5, 4, 3, 2, 1, 0]
print permut_2
print heapsort(permut_2)

print

permut_3 = [3, 2, 21, 8, 0, 7]
print permut_3
print heapsort(permut_3)

