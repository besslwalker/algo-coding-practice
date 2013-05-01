# Insertion Sort (Integers)
# Bess L. Walker
# 11-17-11
# Practicing coding and algorithms

# Real-programming Python, not scripty Python.
# Or not as scripty as my scripts.
# Which are sometimes real-programmy when they get too big.

def insertion_sort(unsorted_list):
	if len(unsorted_list) in [0, 1]:
		return
	
	for ii in range(1, len(unsorted_list)):
		jj = ii
		while unsorted_list[jj] < unsorted_list[jj - 1] and jj > 0:
			temp = unsorted_list[jj]
			unsorted_list[jj] = unsorted_list[jj - 1]
			unsorted_list[jj - 1] = temp
			jj -= 1
	
	return
			
permut_1 = [0, 1, 2, 3, 4, 5]
print permut_1
insertion_sort(permut_1)
print permut_1

print

permut_2 = [5, 4, 3, 2, 1, 0]
print permut_2
insertion_sort(permut_2)
print permut_2

print

permut_3 = [4, 11, 17, 3, 3, 0]
print permut_3
insertion_sort(permut_3)
print permut_3
