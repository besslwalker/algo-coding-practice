// Breadth-First Search
// Bess L. Walker
// 3-15-17
// Practicing algorithms & coding using The Algorithm Design Manual

(function test() {
	// empty graph
	var g1 = new graph();
	console.log(g1.toString());
	
	console.log();
	
	// one vertex
	var v1 = new vertex(1);
	g1.vertices.push(v1);
	console.log(g1.toString());
	
	console.log();
	
	// second vertex
	var v2 = new vertex(2);
	g1.vertices.push(v2);
	console.log(g1.toString());
	
	console.log();
	
	// connect the vertices
	v1.adjacentVertices.push(v2);
	console.log(g1.toString());
	
	console.log();
	
	// third vertex
	var v3 = new vertex(3);
	g1.vertices.push(v3);
	v1.adjacentVertices.push(v3);
	console.log(g1.toString());
})();

// First, we need to know what the graph looks like.
// We use an adjacency list structure.
function vertex(_id) {
	this.id = _id;
	this.adjacentVertices = [];
	
	this.toAdjacencyList = function () {
		var str = this.id + " -> (";
		
		str += this.adjacentVertices.map(function (vert) {return vert.id;}).join(", ");
		
		str += ")";
		
		return str;
	};
	
	return this;
};

function graph() {
	this.vertices = [];
	
	this.toString = function () {
		return this.vertices.map(function (vert) {return vert.toAdjacencyList();}).join("\n");
	}
	 
	return this;
};