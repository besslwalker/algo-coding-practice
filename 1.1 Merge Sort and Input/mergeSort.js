// Merge Sort (Integers) and Input
// Bess L. Walker
// 1-17-17

(function test() {
	var permut_0 = undefined;
	console.log(permut_0);
	console.log(mergeSort(permut_0));
	
	console.log();
	
	var permut_1 = [];
	console.log(permut_1);
	console.log(mergeSort(permut_1));
	
	console.log();
	
	var permut_2 = [0, 1, 2, 3, 4, 5];
	console.log(permut_2);
	console.log(mergeSort(permut_2));
	
	console.log();
	
	var permut_3 = [5, 4, 3, 2, 1, 0];
	console.log(permut_3);
	console.log(mergeSort(permut_3));
	
	console.log();
	
	var permut_4 = [1, 12, 11, 4, 2, 6];
	console.log(permut_4);
	console.log(mergeSort(permut_4));
})();

function mergeSort(array) {
	if (!array) {return undefined;}
	if (array.length <= 1) {return array.slice();}
	
	var splitIndex = Math.floor(array.length / 2);
	
	var left = mergeSort(array.slice(0, splitIndex));
	var right = mergeSort(array.slice(splitIndex));

	return merge(left, right);
}

function merge(left, right) {	
	if (!left || left.length == 0) {return right;}
	if (!right || right.length == 0) {return left;}
	
	var merged = [];
	
	var jj = 0;
	var kk = 0;
	
	while (jj < left.length && kk < right.length) {
		// we'll take from the left if they're the same
		if (left[jj] <= right[kk]) {
			merged.push(left[jj]);
			jj++;
		}
		else {
			merged.push(right[kk]);
			kk++;
		}
	}
	console.log("left: " + left + ", jj: " + jj + ",right: " + right + ", kk: " + kk);
	// when left has been exhausted but right still has contents
	if (kk < right.length) {
		merged.concat(right.slice(kk));
	}
	
	// when right has been exhausted but left still has contents
	if (jj < left.length) {
		merged.concat(left.slice(jj));
	}
	
	return merged;
}