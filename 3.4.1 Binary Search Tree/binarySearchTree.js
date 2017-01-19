// Binary Search Tree (Integers)
// Bess L. Walker
// 1-19-17
// Practicing algorithms & coding using The Algorithm Design Manual

(function test() {
	var node_0 = new treeNode(1);
	console.log(node_0);
	
	console.log();
	
	var tree_0 = new tree();
	console.log(tree_0);
	
	console.log();
	
	var tree_1 = new tree();
	tree_1.root = new treeNode(2);
	console.log(tree_1);
	console.log("search(1): ", tree_1.search(1));
	console.log("search(2): ", tree_1.search(2));
	
})();

function treeNode (data) {
	this.parent = undefined;
	this.data = data;
	this.left = undefined;
	this.right = undefined;
	
	return this;
};

function tree () {
	this.root = undefined;
	
	this.insert = function _insert(value) {
		if (!this.root) {
			this.root = new treeNode();
		}
	};
	
	this.search = function _search(value) {
		if (!this.root) {return undefined;}
		
		if (this.root.data == value) {return this.root;}
		
		if (this.root.data < value) {
			if (!this.root.left) {return undefined;}
			
			return this.root.left.search();
		}
		
		if (this.root.data > value) {
			if (!this.root.right) {return undefined;}
			
			return this.root.right.search();
		}
	};
	
	return this;
};


	
