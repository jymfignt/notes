# Part 1
## Fundamentals of Graphs and Trees
### Graphs Fundamentals
- A Graph is a non-linear data structure consisting of nodes and edges. 
- The nodes are the vertices, and the edges are lines or arcs that connect any two nodes in the graph. 
- More formally, the graph can be defined as: 
	→A graph is a data structure that consists of: 
		→V: a set of nodes (vertices/ points). 
		→E: a set of edges that relate the nodes to each other.
	→The set of edges describes the relationship among the vertices.
  A graph G is defined as (G=(V, E))
#### Undirected and Directed Graphs
#### Weighted and Unweighted Graph
#### Cyclic and Acyclic Graph
A graph has a cycle if you start from a vertex and return to the same vertex after traversing some nodes.
#### Connected and disconnected Graph
A graph is called connected if there is a path between every pair of vertices. 
From each vertex to any other vertex, there should be some path to traverse.
#### Sparse and Dense Graph
- Sparce Graph: A graph in which the number of edges is much less than the possible number of edges. 
- Dense Graph: A graph in which the number of edges is close to the possible number of edges. 

	→Sparse Graph: A sparse graph is a graph G = (V, E) in which |E| = O (|V|) 
	→Dense Graph: A dense graph is a graph G = (V, E) in which |E| = 𝛩($|V|^2$)
#### Node degree in Graph
- Degree in undirected graphs: 
	Degree(V) = number of adjacent (incident) edges to vertex V in G
- Degree in directed graphs: 
	In-Deg(V) = number of incoming edges. 
	Out-Deg(V) = number of outgoing edges.
#### Null and Regular Graph
- A null Graph is a graph containing no edges. 
- Regular graph is a graph where each vertex has the same number of neighbors (every vertex has the same degree)
#### Adjacency
- In a graph, two **vertices** are adjacent if an edge exists between them. Adjacency is maintained by the edge connecting the two vertices. 
- In a graph, two **edges** are adjacent if they share a common vertex. Adjacency is maintained by the vertex connecting the two edges.
#### Complete Graph 
- Graph G is Complete Graph ($𝐺_𝑁$) if every node u in G is adjacent to every other node v in G. 
- A complete graph is already connected.
- Number of edges = 𝑛(𝑛 − 1)/2
### Trees Fundamentals
- A tree is a nonlinear data structure, unlike arrays, linked lists, stacks, and queues, which are linear. 
- A tree can be empty with no nodes or consisting of one node called the root. 
- It can have also zero, one, or more subtrees
#### Properties of the trees
- There is a node at the top of the tree known as the root. 
- The remaining data items are divided into disjoint subsets called subtrees. 
- The tree is expanded in height towards the bottom. 
- A tree must be connected, with a path from the root to all other nodes. 
- It does not contain any loops. 
- A tree has n-edges.
#### Vocabulary and Definitions
- root, node, parent, children, sibling, path, edge, leaf
- Level →The level of a node 𝑛 is the number of edges on the path from the root node to 𝑛. The level of the root node is zero. 
- Height →The height of a tree is equal to the maximum level of any node in the tree.
#### Binary Tree
- A binary tree has elements with at most 2 children, typically called the left and right child
- Calculating the minimum and the maximum number of nodes from height:
	h+1
	$2^{h+1}$ -1
- Calculating the minimum and the maximum height from the number of nodes:
	If there are 𝑛 nodes in binary tree, the maximum height of the binary tree is 𝑛 − 1 and the minimum height is $\lfloor \log_2{n}\rfloor$
#### A Perfect Binary Trees
- A perfect binary tree has nodes with exactly two children, and all leaf nodes are at the same level.
- A perfect binary tree of height ℎ has $2^ {(ℎ+1)} −1$nodes. 
- Number of leaf nodes in a perfect binary tree of height h = $2^ℎ$ 
- Number of internal nodes in a perfect binary tree of height h = $2^ℎ$ − 1
#### Full and Complete Binary Trees
- A full binary tree is a type of binary tree where every node has either zero or two children, and all non-leaf nodes have exactly two children.
- A binary tree is a complete if all the levels are filled except possibly the last level and the last level has all keys as left as possible.
#### Balanced Binary Trees 
- A balanced binary tree, also known as a height-balanced binary tree, is defined as a binary tree where the difference in height between the left and right subtrees of any node is not more than 1
#### Graphs and trees Comparison

|           Key           |                    Graph                    |               Tree               |
| :---------------------: | :-----------------------------------------: | :------------------------------: |
|       Definition        |                                             |                                  |
|          Path           |                  允许$\ge 1$                  |         2 vertices只能有一个          |
|        Root node        |                      无                      |                一个                |
|          Loops          |                     可以有                     |                无                 |
|       Complexity        |                  更复杂相比树来说                   |                                  |
| Traversal<br>techniques | Breadth-first search and depth-first search | Pre-order,  In-order, Post-order |
|     Number of edges     |          not defined<br>最多n(n-1)/2          |               n-1                |
|       Model Type        |                   Network                   |           Hierarchical           |
|          Usage          |          coloring, job scheduling           |       sorting, traversing        |
### Graph Representation
- Different data structures to represent graphs are used in practice:
	Adjacency matrix
	Adjacency list
#### Graph Representation Features
- Matrix Representations 
	→Representation is easier to implement and follow. 
	→Removing an edge takes O(1) time 
	→Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1). 
	→Consumes more space 𝑂( $𝑉^2$) .Even if the graph is sparse (contains a smaller number of edges), it consumes the same space. 
	→Adding a vertex is 𝑂( $𝑉^2$) time. 
- Linked Lists Representations 
	→Save space 𝑂(|𝑉| + |𝐸|) 
	→Adding a vertex is easier. 
	→Support sequential search only
#### Incidence matrix
- The incidence matrix of a directed graph has rows for vertices and columns for edges. Each entry `𝐴[𝑖, 𝑗]` is: 
	→1 if vertex 𝑖 is the initial vertex of edge 𝑗, 
	→-1if vertex 𝑖 is the terminal vertex of edge 𝑗, 
	→0 otherwise. 
- If a directed graph G consists of 𝑛 vertices and 𝑚 edges, then the incidence matrix is an n × m matrix $C =[c_{ij}]$ and defined by: $$C_{ij}=\begin{cases}
1, &if \text{ } V_i \text{ is the initial vertex of edge }e_j\\
-1, &if \text{ } V_i \text{ is the final vertex of edge }e_j\\
0, &if \text{ } V_i \text{ 𝑖𝑠 𝑛𝑜𝑡 𝑖𝑛𝑐𝑖𝑑𝑒𝑛𝑡 𝑜𝑛 𝑒𝑑𝑔e}e_j
\end{cases}$$
- The number of ones in an incident matrix is equal to the number of edges in the graph.
- Features of incident matrix:
	Can be applied to any directed graph
	The sum of any column = 0
	In and out-degrees of any node can be calculated (Sum of 1’s, -1’s, in the row)
	Matrix can be reduced (Deletion of any row).
#### Binary Trees Representation
- To represent a binary tree of depth ‘𝑛’ using array representation, we need one dimensional array with a maximum size of 2𝑛 + 1
- If the node is at 𝑖𝑡ℎ index 
	→Left child at: `[ 2×𝑖 +1]` 
	→Right child at: `[ 2×𝑖 +2]`
	→Parent: $\lfloor \frac{(𝑖−1)}{2}\rfloor$
- If the node is at 𝑖𝑡ℎ index 
	→Left child at: `[ 2×𝑖 ]` 
	→Right child at: `[ 2×𝑖]`
	→Parent: $\lfloor \frac{𝑖}{2}\rfloor$
右子树似乎需要空出两个？
#### Linked List Representation
Two types of nodes are used: one for representing the node with data called ‘data node’ and another for representing only reference called ‘ reference node’
#### Double Linked List Representation
In a double-linked list, every node consists of three fields. The first field is for storing the left child address, the second for storing actual data, and the third for storing the right child address.
#### Graph Searching (Traversing Algorithms)
- Graphs have become a powerful means of modelling and capturing data in real-world scenarios such as social media networks, web pages and links, and locations and routes in GPS. 
- If you have a set of objects that are related to each other, then you can represent them using a graph. 
- Graph Operations: The most common graph operations are: 
	→Check if the element is present in the graph. 
	→Graph Traversal. 
	→Add elements(vertex, edges) to graph. 
	→Finding the path from one vertex to another
#### Spanning Tree
- Properties of the spanning tree connected to graph G: 
- A connected graph G can have more than one spanning tree. 
- All possible spanning trees of graph G have the same number of edges and vertices. 
- The spanning tree does not have any cycle (loops). 
- Removing one edge from the spanning tree will make the graph disconnected because the spanning tree is minimally connected. 
- Adding one edge to the spanning tree will create a circuit or loop because the spanning tree is maximally acyclic.

- A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together without any cycles and with the minimum possible total edge weight. 
- It is a spanning tree whose sum of edges weights is as small as possible. 
- If each edge has a distinct weight, then there will be only one unique minimum spanning tree.
# Part 2
## Depth-First Search (DFS) Algorithm
- In some algorithms, the order of visiting the vertices is unimportant; the important is the vertices are visited in a systematic order, regardless of the input graph
- Depth first Search (DFS) or Depth first traversal is a recursive algorithm for searching all the vertices of a graph or tree data structure. 
- Traversal means visiting all the nodes of a graph. 
- DFS puts each vertex of the graph into one of two categories: 
	1. Visited 
	2. Not Visited 
- The purpose of the algorithm is to mark each vertex as visited while avoiding cycles. 
- In DFS, each node branch is explored fully before backtracking to explore other branches.
### How DFS Works
- Let G = (V, E) be a directed or undirected graph. A depth-first search traversal of G works as follows: 
	1. First, all vertices are marked unvisited. 
	2. Next, a starting vertex is selected, say v ∈ V , and marked visited. 
	3. Let w be any vertex that is adjacent to v. We mark w as visited and advance to another vertex, say x, that is adjacent to w and is marked unvisited. 
	4. Again, we mark x as visited and advance to another vertex that is adjacent to x and is marked unvisited. 
	5. This process of selecting an unvisited vertex adjacent to the current vertex continues as deep as possible until we find a vertex y whose adjacent vertices have all been marked visited. 
	6. At this point, we back up to the most recently visited vertex, say z, and visit an unvisited vertex that is adjacent to z, if any. 
	7. Continuing this way, we finally return back to the starting vertex v.
#### Steps
1. Start by putting any one of the graph's vertices on top of a stack. 
2. Take the top item of the stack and add it to the visited list. 
3. Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the top of the stack. 
4. Keep repeating steps 2 and 3 until the stack is empty
### Time complexity of depth-first search
- It follows that the running time of the algorithm is Θ(𝑚+𝑛). 
- If the graph is connected or 𝑚≥𝑛, then the running time is simply Θ(𝑚)
### Depth First Search (DFS) –Applications 
1.For finding the path. 
2.To test if the graph is bipartite 
3.For finding the strongly connected components of a graph 
4.For detecting cycles in a graph
## Breadth-First Search (BFS) Algorithm
- BFS starts at the tree root (or a node of a graph, sometimes referred to as a ‘ search key’) and explores all the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level. 
- It uses the opposite strategy of depth-first search (DFS); instead of going deep into a single branch, breadth-first search (BFS) explores all neighboring nodes at the current level before moving on to the next level. 
- Breadth First Search (BFS) uses a queue to remember to get the next vertex to start a search when a dead end occurs in any iteration.
### BFS Rules 
1. Visit the adjacent unvisited vertex. Mark it as Visited. Display it. Insert it in a queue. 
2. If no adjacent vertex is found, remove the first vertex from the queue. 
3. Repeat Rule 1 and Rule 2 until the queue is empty.
### Complexity
- If the graph is connected or 𝑚 ≥ 𝑛, then the time complexity is simply Θ(𝑚). 
- The space complexity of the algorithm is 𝑂(𝑛)
### Breadth-First Search (BFS)- Applications 
1. To build an index by search index. 
2. For GPS navigation. 
3. Pathfinding algorithms. 
4. In the Ford-Fulkerson algorithm to find maximum flow in a network.
5. Cycle detection in an undirected graph. 
6. In minimum spanning tree.
## Prim’s Algorithm
### Minimum Cost Spanning Tree Algorithm
- Two Greedy Algorithms for MST 
	→Kruskal’s Algorithm 
		→Adds edges one by one into a growing spanning tree. ( Refer to Greedy Algorithms Ch.6 (iii)) 
	→Prim’s Algorithm 
		→Attaches vertices to a partially built tree by adding small-cost edges repeatedly.
- Prim’s algorithm for finding a minimum spanning tree for an undirected graph is so similar to Dijkstra’s algorithm for the shortest path problem. 
- The algorithm grows the spanning tree starting from an arbitrary vertex.
- Prim’s algorithm uses the greedy approach to find the minimum spanning tree. 
- In Prim’s algorithm we grow the spanning tree from a starting position. 
- Unlike an edge in Kruskal’s algorithm, we add a vertex to the growing spanning tree in Prim’s algorithm. 
- Prim’s algorithms start with a single node and explore all the adjacent nodes with all the connecting edges at every step. 
- The edges with the minimal weights causing no cycles in the graph got selected.
### MST-Prim’s Algorithm -Steps
1.  Remove all loops and parallel edges from the given graph. In the case of parallel edges, keep the one which has the least cost associated and remove all others. 
2. Initialize an MST with the randomly chosen vertex. 
3. Find all the edges that connect the tree in the above step with the new vertices. From the edges found, select the minimum edge and add it to the tree. 
4. Repeat step 3 until the minimum spanning tree is formed.
### Prim’s Algorithm-Complexity
- It follows that the time complexity of the algorithm is $Θ(𝑚+𝑛^2) =Θ(𝑛^2)$
- Time complexity of Algorithm prim can be improved (same as we did to Algorithm Dijkstra) from $Θ(𝑛^2)$ time complexity to $𝑂(𝑚\log{𝑛})$
### Prim’s Algorithm-Applications 
In network designed. 
To make protocols in network cycles
## Shortest path problems Algorithms
- Floyd’s-Warshal Algorithm. (Dynamic Programming). 
- Dijkstra’s Algorithm-Shortest Path in Graph. (Greedy Algorithms). 
- Bellman-Ford Algorithm.
### Bellman-Ford Algorithm
- Bellman-Ford (BF) Algorithm is a single source shortest path algorithm. 
- BF is slower than Dijkstra’s Algorithm, it works in the cases when the weight of the edge is positive or negative, and it also finds negative weight cycle in the graph. 
- The Idea of Bellman-Ford algorithm is to relax all the edges of the graph one-by-one in some random order at most (n-1) times
- Bellman ford algorithm can find the negative loop in the graph. Thus, they used in some application to find the negative loops or cycle
#### Bellman-Ford Algorithm Steps 
- S is the starting node, and it can be chosen randomly 
- E is the number of edges. 
- V is the number of nodes. 
- D is an array that tracks the best distance from S to all nodes. 

- The steps as follow: 
	1. Set `D[S]` to 0. (Set the starting node to 0) 
	2. Set every entry in D to ∞. (The other nodes set them to ∞) 
	3. Relax each edge 𝑉−1time
#### Bellman-Ford Algorithm- Complexity
- Time Complexity (E => edges), (V=> vertices) 
	→Best Case Complexity O(E) 
	→Average Case Complexity O(VE) 
	→Worst Case Complexity O(VE) 
- Space Complexity 
	→space complexity is O(V)
#### Bellman-Ford Algorithm-Applications 
For calculating shortest paths in routing algorithms 
For finding the shortest path




































