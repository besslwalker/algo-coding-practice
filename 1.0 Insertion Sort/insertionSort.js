// performs in-place sorting
// we could return a sorted copy by performing the
// same in-place sort on a slice()'d copy (array.slice())
// after making sure array exists
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
			else {
				// found the right place, stop
				break;
			}
		}
	}
	
	return array;
};