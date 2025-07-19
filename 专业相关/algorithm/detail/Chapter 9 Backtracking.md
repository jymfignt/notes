# Part 1
## Backtracking
### Backtracking-Introduction
- Many real-world NP-hard problems can be solved by exhaustively searching through numerous finite possibilities
- For all of these problems, there does not exist an algorithm that uses a method other than exhaustive search. 
- Thus, systematic search techniques were developed to reduce the search space significantly. 
- We present a general technique for organizing the search known as backtracking. 
- This algorithm design technique can be described as an organized exhaustive search which often avoids searching all possibilities

### Space State Tree
- a tree representing all the possible states (solution or non-solution) of the problem from the root as an initial state to the leaf as a terminal state
>比如我们要求{1,2,3}的所有排列：
           (start)
         /    |     \
        1     2     3
        / \     |     / \
        2  3   ...   1   2
        /           \
        3             1

-  根节点是“什么都没选”
- 每一层代表你选下一个数字
- 到达某个叶子节点，就是一个完整的解
- 中间如果发现某个节点“选的数字重复”，就可以剪掉这个分支 —— **剪枝**
### Backtracking Algorithm

- A backtracking algorithm is a problem-solving algorithm that uses a brute force approach for finding the desired output.
- The Brute force approach tries out all the possible solutions and chooses the desired/best solutions. 
- The term backtracking suggests that if the ==current solution== is not suitable, then backtrack and try other solutions. Thus, recursion is used in this approach. 
- This approach is used to solve problems that have ==multiple solutions==. If you want an ==optimal solution==, you must go for dynamic programming.

```pseudocode
Backtrack(x)
	if x is not a solution
		return false
	if x is a new solution
		add to list of solutions
	backtrack(expand x)
```
### Backtracking Algorithm Applications
- To solve the N Queen problem. 
- Sum of subsets Problem 
- To find all Hamiltonian Paths present in a graph. 
- Maze-solving problem. 
- The Knight's tour problem
## N-Queen Problem
### N-Queen Using Backtracking
- The N-Queens problem involves placing 𝑛 queens on an 𝑛 × 𝑛 chessboard so that no two queens share the same row, column, or diagonal. 
- It can be seen that for n =1, the problem has a trivial solution, and no solution exists for n =2 and n =3. 
- So we will consider the n = 4 queens problem and then generate it to n queens problem.
- Given a 4 x 4 chessboard and number the rows and column of the chessboard 1 through 4. 
- Since, we have to place 4 queens such as $q_1$ $q_2$ $q_3$ and $q_4$ on the chessboard, such that no two queens attack each other
### Example 1 : N-Queen Example Using Backtracking
- If the chess board is of (𝑁×𝑁) size then our mission is to place N queens on the board such that each of them are at a safe position without getting attacked from other queens. 
- Two Queens can not be placed in the same row, column, or diagonal
- To solve the 4-queens problem using backtracking, the algorithm tries to generate and search a **complete 4-ary rooted tree** in a ==depth-first manner==. 
- The root of the tree corresponds to the placement of no queens. 
- Nodes at each level represent possible queen placements in successive rows. 
- The backtracking algorithm to solve this problem is given as Algorithm 4-queens. 
- In the algorithm, we used the term **legal** to mean a placement of four queens that do not attack each other, and the term **partial** to mean a placement of less than four queens that do not attack each other. 
- If two queens placed at positions $𝑥_𝑖$ and $𝑥_𝑗$ are in the same column if and only if $𝑥_𝑖 = 𝑥_𝑗$. 
- It is not hard to see that two queens are in the same diagonal if and only if $𝑥_𝑖 − 𝑥_𝑗 = 𝑖 − 𝑗$ or $𝑥_𝑖 −𝑥_𝑗 =𝑗−𝑖$.
### Time Complexity
So the time complexity of N Queen Problem by using backtracking reduced from $O(𝑛^𝑛)$ to O(n!) because backtracking eliminates dead ends
## Sum of subsets Problem
### Sum of subsets using Backtracking
- Find the subsets of a given set S={$𝑠_1, 𝑠_2, 𝑠_3, … ,𝑠_𝑛$} of n positive integers whose sum is equal to a given positive integer sum. $$𝑠_1 ≤ 𝑠_2 ≤ ⋯≤𝑠_𝑛$$
- The subset-Sum problem can be solved using different methods: 
	→Brute-Force 
	→Dynamic programming. 
	→Backtracking.
- Sum of Subsets Problem: Given a set of ==positive integers==, find the ==combination of numbers== that sum to given value M. 
- Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. 
- We are considering the set contains **non-negative values**. It is assumed that the input set is unique (no duplicates are presented)
### Exhaustive Search (Brute force) Algorithm for Subset Sum
- One way to find subsets that sum to K is to consider all possible subsets. 
- A power set contains all those subsets generated from a given set. 
- The size of such a power set is $2^N$
### Backtracking Algorithm for Subset Sum
- Backtracking can be used to make a systematic consideration of the elements to be selected. 
- Assume given set of 4 elements, say $w[1] … w[4]$. 
- State-space tree is used to design backtracking algorithms. 
- We need to explore the nodes along the breadth and depth of the tree.
- Generating nodes along breadth is controlled by loop and nodes along the depth are generated using recursion (post order traversal)

- Algorithm Steps: 
	1. Start with an empty set. 
	2. Add the next element from the list to the set. 
	3. If the subset is having sum M, then stop with that subset as solution. 
	4. If the subset is not feasible or if we have reached the end of the set, then backtrack through the subset until we find the more suitable value. 
	5. If the subset is feasible (sum of subset < M, then go step 2). 
	6. If we have visited all the elements without finding a suitable subset and if no backtracking is possible then stop without solution.
```pseudocode
if(subset is satifying the constraint)
	print the subset
	exclude the current element and consider next element
else
	generate the nodes of present level along breadth of tree and
	recur for next levels
```
### Time complexity
$T(n) = 1+2+2^2+2^3+\dots +2^n = 2^{n+1} -1=O(2^n)$
## Graph coloring Problem
### Graph Coloring
- Graph coloring is the process of labelling graph components such as vertices, edges, and regions under some constraints. 
- In a graph, no two adjacent vertices, adjacent edges, or adjacent regions are colored with the same color.
- We have been given a graph and we asked to color all vertices with “M” number of colors, in such a way that no two adjacent vertices should have the same color. 
- If It is possible to color all vertices with the given colors then we have to output the colored result, otherwise output will be “ no solution possible”. 
- The least possible value of “M” required to color the graph successfully is known as the chromatic number of the given graph.
- Graph coloring problem is **both** a decision problem and an optimization problem. 
- A decision problem is stated: “With given M colors and graph G, is such a color scheme possible or not ?”. 
- The optimization problem is stated: “with given M colors and graph G, find the minimum number of colors required for graph coloring."
- A graph is said to be k-colorable if it can be properly colored using k colors. 
- K-chromatic graph: The smallest number of colors needed to color a graph G is called its chromatic number, and a graph that is k-chromatic if its chromatic number is exactly k. 
- Graph coloring is NP-complete problem.
### Graph coloring – Vertex Coloring
- The problem can be solved simply by assigning a unique color to each vertex, but this solution is not optimal. 
- It may be possible to color the graph with colors less than |V|

- Cycle graphs with even number of vertices require 2 colors. 
- Cycle graphs with odd number of vertices require 3 colors

- Steps: 
	1. Choose a vertex with the **highest degree**, and color it. Use the same color to color as many vertices as possible without coloring vertices joined by an edge of the same color. 
	2. Choose a new color and repeat step 1 for vertices not already colored. 
	3. Repeat step 1 until all vertices are colored.
### Graph coloring – Complete Graph
- In the complete graph, each vertex is adjacent to remaining (n-1) vertices. 
- Each vertex requires a new color. Hence, the chromatic number = 𝑛
### Graph coloring – Brook’s Theorem
Brook’s theorem states that a connected graph can be colored with only x colors, where x is the **maximum degree** of any vertex in the graph ==except for== complete graphs and graphs containing an odd length cycle, which requires x + 1 colors.
### Graph coloring – Region coloring
- Region coloring is an assignment of colors to the regions of a planar graph such that no two adjacent regions have the same color. 
- Two regions are said to be adjacent if they have a common edge.
### Graph coloring using backtracking
The vertex coloring can be solved using backtracking as follows: 
	1. List down the vertices and colors in two lists. 
	2. Assign color 1 to vertex 1. 
	3. If vertex 2 is not adjacent to vertex 1 then assign the same color, otherwise assign color 2. 
	4. Repeat the process until all vertices are colored. 
	5. The algorithm backtracks whenever color 𝑖 is not possible to assign to any vertex k, it selects the next color 𝑖 + 1 and the test is repeated.
### Graph coloring -Using Naive Algorithm
- In this approach using the brute force method, we find all permutations of color combinations that can color the graph. 
- If any of the permutations is valid for the given graph and colors, we output the result otherwise not. 
- This method is not efficient in terms of time complexity because it finds all colors combinations rather than a single solution.
### Graph coloring- Using Backtracking Algorithm
 Steps To color graph using the Backtracking Algorithm: 
 - Different colors: 
	 1. Check if it is valid to color the current vertex with the current color by ensuring none of its adjacent vertices are colored the same. 
	 2. If yes, then color it and otherwise try a different color. 
	 3. Check if all vertices are colored or not. 
	 4. If not, then move to the next adjacent uncolored vertex. 
	 5. If no other color is available, then backtrack (i.e., un-color last colored vertex).
- Here, backtracking means stopping further recursive calls on adjacent vertices by returning false. 
- In this algorithm Step-1 (Continue) and Step-2 (backtracking) is causing the algorithm to try different color option
### Complexity
time complexity: O($m^V$)
space complexity: O(V)
### Graph coloring Applications 
Map coloring 
Making a timetable. 
Mobile radio frequency assignment. 
Data mining. 
Image segmentation. 
Networking. 
Resource allocation. 
Processes scheduling.
# Part 2
## Hamiltonian Cycle Problem
- Hamiltonian path: A simple path in graph G that passes through every vertex exactly once, but doesn't need to return to the starting point. 
- The Hamiltonian cycle is the cycle in the graph which visits all the vertices in graph exactly once and terminates at the starting node. It may not include all the edges. 
- The Hamiltonian cycle problem is the problem of finding a Hamiltonian cycle in a graph if there exists any such cycle.
- Input: an undirected, connected graph
### Dirac's and Ore's Theorem
- There are certain theorems which give sufficient but not necessary conditions for the existence of Hamiltonian graphs
- Dirac’s Theorem: “ If G is a simple graph with 𝑛 ≥ 3 vertices such that the degree of every vertex in G is at least Τ 𝑛/ 2, then G has Hamiltonian cycle
- Ore’s Theorem: If G is a simple graph with 𝑛 ≥ 3 vertices such that deg(u) + deg(v) ≥ 𝑛 for every pair of non-adjacent vertices u and v in G, then G has a Hamiltonian cycle

- These theorems are sufficient but not necessary conditions for the existence of Hamiltonian cycle in a graph. 
- There are certain graphs that have a Hamiltonian cycle but do not follow the conditions in these theorems (Ore’s and Dirac’s theorems)
### Hamiltonian Cycle Problem
- The Hamiltonian cycle problem is also both, decision and optimization problem. 
- A decision problem is stated as, “Given a graph, is there a Hamiltonian cycle in the graph?”. 
- The optimization problem is stated as, “Given graph G, find the maximum Hamiltonian cycle for the graph.”
### Hamiltonian Cycle Problem –The constraints
We can define the constraint for the Hamiltonian cycle problem as follows: 
1. In any path, vertex 𝑖 and (𝑖+1)must be adjacent. 
2. 1𝑠𝑡 and (𝑛–1)𝑡ℎ vertex must be adjacent (𝑛𝑡ℎ of cycle is the initial vertex itself). 
3. Vertex 𝑖 must not appear in the first (𝑖–1) vertices of any path.
### Hamiltonian Cycle Problem – Steps of solution
- Using the backtracking method, we can easily find all the Hamiltonian Cycles present in the given graph. 
- The idea is to use the Depth-First Search algorithm to traverse the graph until all the vertices have been visited.
### Hamiltonian Cycle Problem – Time complexity
T(n)=n!
## Knapsack Problem using Backtracking
The knapsack problem has two variants. 
→0/1 knapsack does not allow breaking up the item, whereas a fractional knapsack does. 
→0/1 knapsack is also known as a binary knapsack.
### Time complexity
T(n)=$2^n$









