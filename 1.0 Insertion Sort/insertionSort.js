// Insertion Sort (Integers)
// Bess L. Walker
// 1-16-17
// Practicing algorithms & coding using The Algorithm Design Manual

(function test() {
	
	var permut_0 = undefined;
	
	console.log(permut_0);
	insertionSort(permut_0);
	console.log(permut_0);
	
	console.log();
	
	var permut_1 = [];
	
	console.log(permut_1);
	insertionSort(permut_1);
	console.log(permut_1);
	
	console.log();
	
	var permut_2 = [0, 1, 2, 3, 4, 5];
	
	console.log(permut_2);
	insertionSort(permut_2);
	console.log(permut_2);
	
	console.log();
	
	var permut_3 = [5, 4, 3, 2, 1, 0];
	
	console.log(permut_3);
	insertionSort(permut_3);
	console.log(permut_3);
	
	console.log();
	
	var permut_4 = [2, 11, 14, 1, 0, 2];
	
	console.log(permut_4);
	insertionSort(permut_4);
	console.log(permut_4);
})();

function insertionSort(array) {
	if (!array || array.length <= 1) {return array;}
	
	// go through the possibly unsorted portion
	for (var i = 1; i < array.length; i++) {
		// go through the sorted portion
		for (var j = 0; j < i; j++) {
			if (array[i] < array[j]) {
				// swap
				var temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			// can't short-circuit on array[i] >= array[j] here
			// if the array supports duplicates
		}
	}
	
	// allow chaining
	return array;
};