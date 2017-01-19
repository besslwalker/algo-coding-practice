// The Algorithm Design Manuscript, 2nd Edition, pg. 30
// 1-28. Write a function to perform integer division with using 
// either the / or the * operators.  Find a fast way to do it.
//
// Bess L. Walker
// 1-17-2017

// Let's start with some naive ways to do it,
// and see if they point towards a fast way

// Iterative subtraction
function intDivideIS(dividend, divisor) {
	var counter = 0;
	
	while(dividend >= divisor) {
		dividend -= divisor;
		counter++;
	}
	
	return counter;
};

// Recursive subtraction
// Takes just as long, plus it might blow the stack!
function intDivideRS(dividend, divisor) {
	if (dividend < divisor) {return 0;}
	else { return 1 + intDivideRS(dividend - divisor, divisor); }
};

// Dynamic programming
// Without the recursion, and assuming a populated store, this is O(lg n) where n = dividend
// With the recursion on the remainderSum (still assuming a populated store),
// it's something like this:
//   - the remainderSum will be < 1/2 of the original dividend (NO, WRONG, 15 => 10, ARGUMENT NEEDS REWORK)
//   - so we're looking at something like O(1/2(lg(n)) + 1/4(lg(n)) + ...)
//   - so in total that approaches O(2*lg(n)), which is simply lg(n) again
// The worst case for store population is O(n), since that is essentially
// the recursive subtraction. A truly malicious enemy might therefore be able to force
// us to expend O(n*lg(n)) effort -- but only once per attack vector.
// The average case is lg(n), which I think is about the best we can hope for.
var dpStore = {};
function intDivideDP(dividend, divisor) {
	if (dividend < divisor) {return 0;}
	if (dividend == divisor) {return 1;}
	
	var count = 0;
	var remainderSum = 0;
	var place = 1;

	while (place <= dividend) {
		var hasPlace = dividend & place;
		
		if (hasPlace) {
			// populate store if not populated
			if (!dpStore[place]) {
				dpStore[place] = {};
			}
			if (!dpStore[place][divisor]) {
				if (place < divisor) {
					dpStore[place][divisor] = 0;
				}
				else {
					dpStore[place][divisor] = 1 + intDivideDP(place - divisor, divisor);
				}
			}
			
			remainderSum += place % divisor;
			count += dpStore[place][divisor];
		}
		
		place <<= 1;
	}

	return count + intDivideDP(remainderSum, divisor);
}

function pPrintPair(pair) {
	console.log(pair[0] + "/" + pair[1]);
};

function pPrintResult(pair) {
	console.log("iterative subtraction: " + intDivideIS(pair[0], pair[1]));
	console.log("recursive subtraction: " + intDivideIS(pair[0], pair[1]));
	console.log("dynamic programming: " + intDivideDP(pair[0], pair[1]));
}

(function test(){
	var pair_0 = [0, 1];
	pPrintPair(pair_0);
	pPrintResult(pair_0);
	
	console.log();
	
	var pair_1 = [1, 1];
	pPrintPair(pair_1);
	pPrintResult(pair_1);
	
	console.log();
	
	var pair_2 = [1, 2];
	pPrintPair(pair_2);
	pPrintResult(pair_2);
	
	console.log();
	
	var pair_3 = [2, 1];
	pPrintPair(pair_3);
	pPrintResult(pair_3);
	
	console.log();
	
	var pair_4 = [3, 2];
	pPrintPair(pair_4);
	pPrintResult(pair_4);
	
	console.log();
	
	var pair_5 = [13, 5];
	pPrintPair(pair_5);
	pPrintResult(pair_5);
})();