# The Algorithm Design Manuscript, 2nd Edition, pg. 30
# 1-28. Write a function to perform integer division with using 
# either the / or the * operators.  Find a fast way to do it.
#
# Bess L. Walker
# 2-9-12

# Recursion?  Sure.
def recurse_divide(dividend, divisor):
	pass
	
# Wait why would I want the overhead of recursion
# When a while loop can take care of this no problem?
def iterative_divide(dividend, divisor):
	if dividend < divisor:
		return 0
	else:
		counter = 0
		while dividend >= divisor:
			dividend -= divisor
			counter += 1
	return counter
	
# Could have skipped the if case there, compact version looks like this:
def iterative_divide_2(dividend, divisor):
	quotient = 0
	while dividend >= divisor:
		dividend -= divisor
		quotient += 1
	return quotient
	
# Faster?  That's O(n), anything reasonable at the O(logn) level?
def conquer_by_dividing(dividend, divisor):
	if dividend < divisor:
		return 0
	else:
		# drat no, binary divide-and-conquer rather requires the / operator
		
# We could use + and count up, but that's really no different.
# We are allowed to use %, but I don't think it really gives me any useful info.
# O(n) is the best I am going to do here.