// Problem definition assumes that the array is sorted.
// Kata 02, codekata.com:
// Write a binary chop method that takes an integer search target 
// and a sorted array of integers. It should return the integer index 
// of the target in the array, or -1 if the target is not in the array. 
// The signature will logically be:
//   chop(int, array_of_int) -> int
// You can assume that the array has less than 100,000 elements.
// For the purposes of this Kata, time and memory performance are
// not issues (assuming the chop terminates before you get bored 
// and kill it, and that you have enough RAM to run it.	

function chop(target, array) {
	if (!array) {return -1;}
	
	return chopFrom(target, array, 0, array.length - 1);
};

// Examine from first index to last index, inclusive
function chopFrom(target, array, first, last) {
	// trivial base case: array is nonexistent, or empty, or we're looking at no part of it
	if (!array || array.length <= 0 || first > last) {
		return -1; // can't possibly find it in an empty array
	}
	
	// base case: one element
	if (first == last) {
		if (array[first] == target) {return first;}
		else {return -1;}
	}
	
	// recursive case
	// 1. Find the Chop index. If there are only two elements, the Chop index
	// will end up being the first index.
	var chopIdx = first + Math.floor((last - first) / 2)
	// 2. Get Chop value
	var value = array[chopIdx];
	// 3. Recurse or (if very lucky) finish
	if (target < value) {
		return chopFrom(target, array, first, chopIdx - 1);
	}
	else if (target > value) {
		return chopFrom(target, array, chopIdx + 1, last);
	}
	else {
		// whoohoo, a match!
		return chopIdx;
	}
};