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

function chop (target, array) {
	if (!array || array.length < 0) { return -1; }
	
	// We will search from first to last, inclusive
	var first = 0;
	var last = array.length - 1;
	
	while (first < last) {
		// note that JS does not have integer division
		var chopIndex = first + Math.floor((last - first) / 2)); // will be first if there are only two elements
		
		if (array[chopIndex] < target) {
			first = chopIndex + 1; // search right half
		}
		else if (array[chopIndex] > target) {
			last = chopIndex -1; // search left half
		}
		else {
			// found it!
			return chopIndex;
		}
	}
	
	if (first == last) {
		if (array[first] == target) { return first; }
		else {return -1;}
	}
	
	return -1;
};