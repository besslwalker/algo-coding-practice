// Selection Sort (Integers)
// Bess L. Walker
// 1-16-17
// Practicing algorithms & coding using The Algorithm Design Manual

(function test() {
	var permut_0 = undefined;
	console.log(permut_0);
	sort(permut_0);
	console.log(permut_0);
	
	console.log();
	
	var permut_1 = [];
	console.log(permut_1);
	sort(permut_1);
	console.log(permut_1);
	
	console.log();
	
	var permut_2 = [1];
	console.log(permut_2);
	sort(permut_2);
	console.log(permut_2);
	
	console.log();
	
	var permut_3 = [1, 2, 3, 4, 5, 6];
	console.log(permut_3);
	sort(permut_3);
	console.log(permut_3);
	
	console.log();
	
	var permut_4 = [6, 5, 4, 3, 2, 1];
	console.log(permut_4);
	sort(permut_4);
	console.log(permut_4);
	
	console.log();
	
	var permut_5 = [0, 4, 2, 6, 2, 3];
	console.log(permut_5);
	sort(permut_5);
	console.log(permut_5);
})();

function sort(array) {
	if (!array || array.length <= 1) { return array;}
	
	for (var ii = 0; ii < array.length; ii++) {
		for (var minIndex = ii, jj = ii + 1; jj < array.length; jj++) {
			if (array[jj] < array[minIndex]) { minIndex = jj; }
		}
		var temp = array[ii];
		array[ii] = array[minIndex];
		array[minIndex] = temp;
	}
}