// Breadth-First Search
// Bess L. Walker
// 3-15-17
// Practicing algorithms & coding using The Algorithm Design Manual

(function test() {
	// empty graph
	var g1 = new graph();
	console.log(g1.toString());
	console.log(bfs(g1));
	
	console.log();
	
	// one vertex
	var v1 = new vertex(1);
	g1.vertices.push(v1);
	console.log(g1.toString());
	console.log(bfs(g1));
	
	console.log();
	
	// second vertex
	var v2 = new vertex(2);
	g1.vertices.push(v2);
	console.log(g1.toString());
	console.log(bfs(g1));
	
	console.log();
	
	// connect the vertices
	v1.adjacentVertices.push(v2);
	console.log(g1.toString());
	console.log(bfs(g1));
	
	console.log();
	
	// third vertex
	var v3 = new vertex(3);
	g1.vertices.push(v3);
	v1.adjacentVertices.push(v3);
	v3.adjacentVertices.push(v1);
	console.log(g1.toString());
	console.log(bfs(g1));
	
	console.log();
	
	// more vertices
	var v4 = new vertex(4);
	var v5 = new vertex(5);
	g1.vertices.push(v4);
	g1.vertices.push(v5);
	v2.adjacentVertices.push(v4);
	v3.adjacentVertices.push(v5);
	v5.adjacentVertices.push(v4);
	console.log(g1.toString());
	console.log(bfs(g1));
	console.log(bfs(g1, v3));
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
		return "Graph:\n" + this.vertices.map(function (vert) {return vert.toAdjacencyList();}).join("\n");
	}
	 
	return this;
};

function bfs(g, start_vertex) {
	if (!g || g.vertices.length == 0) { return "BFS Order: []";}
	
	if (!start_vertex) {
		start_vertex = g.vertices[0];
	}
	
	var order = [];
	var queue = [];
	queue.push(start_vertex);
	
	// set processed and discovered states
	for (var i = 0; i < g.vertices.length; i++) {
		g.vertices[i].processed = false;
		g.vertices[i].discovered = false;
	}
	
	while (queue.length > 0) {
		var vertex = queue.shift();
		if (vertex.processed) {continue;}
		
		vertex.discovered = true;
		
		for (var j = 0; j < vertex.adjacentVertices.length; j++) {
			var adj_vert = vertex.adjacentVertices[j];
			if (!adj_vert.discovered) {
				queue.push(adj_vert);
			}
		}
		
		vertex.processed = true;
		order.push(vertex.id);
	}
	
	return "BFS order: " + order.join(", ");
}