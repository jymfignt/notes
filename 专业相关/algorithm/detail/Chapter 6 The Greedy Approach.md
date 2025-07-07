# Part 1
## Greedy Algorithm
### Greedy Algorithm- Introduction
- As dynamic programming algorithms, greedy algorithms are usually designed to solve optimization problems（找最大值或者最小值） 
- Unlike dynamic programming algorithms, greedy algorithms consist of an iterative procedure that tries to find a local optimal solution.
	动态规划会记录历史，比较所有可能的路径（代价更大，但更稳妥）
	贪心算法只看当前哪个最好，每次都做出当前最优的决定，完全不管后果
- In some instances（比如活动选择、最小生成树）, these local optimal solutions translate to global optimal solutions. However, in others（比如 0-1 背包问题）, they fail to give optimal solutions.  有些情况下，每步是最优解也不能保证整体是最优解，因为有的是需要组合来看的
- A greedy algorithm makes a correct guess on the basis of little calculation without worrying about the future. Thus, it builds a solution step by step.
- Each step increases the size of the partial solution and is based on local optimization. 
- The choice made is that which produces the largest immediate gain while maintaining feasibility. 
- Since each step consists of little work based on a small amount of information, the resulting algorithms are typically efficient. 高效但未必准确
- The hard part in the design of a greedy algorithm is proving that the algorithm does indeed solve the problem it is designed for 难点就是证明这个算法确实可以解决问题（别每一步选择搞得更复杂）
- For many optimization problems, using dynamic programming to determine the best choices is overkill; simpler, more efficient algorithms will do.
- A greedy algorithm makes the choice that looks best at the moment. It makes a locally optimal choice in the hope this choice will lead to a globally optimal solution. **贪心选择性质（greedy-choice property）**
- Greedy algorithms do not always yield optimal solutions, but for many problems they do.
### Greedy Algorithm- Summary
- It works in a top-down approach
- It may not produce the best result for all the problems, because it goes for the local best choice to produce the global best result.
### Greedy Algorithm- Problem Properties

我们可以确定这个算法能不能用于解决问题if the problem has the following properties:
1. Greedy Choice Property 
	If an optimal solution to the problem can be found by choosing the best choice at each step without reconsidering the previous steps once chosen, the problem can be solved using a greedy approach. 上文提到过，no backtracking，每一步选了当前最好的，最后就能得到最优解
2. Optimal Substructure 
	If the optimal overall solution to the problem corresponds to the optimal solution to its subproblems, then the problem can be solved using a greedy approach. 能把问题拆成子问题，并且“子问题的最优解”组成了“整体的最优解”。这个性质也是动态规划的前提，
### Elements of the greedy strategy
The process of developing a greedy algorithm will go through the following steps: 
	1. Determine the optimal substructure of the problem. 能拆成子问题才能递归然后后续解决
	2. Develop a recursive solution. 无所谓实现快慢，写出一个递归解法
	3. Show after making the greedy choice, only one subproblem remains to be solved, which maintains the structure of the original problem and ensures the greedy strategy is effective. 要证明一旦做出了贪心选择，剩下的问题还是“原问题的缩小版本”，你可以继续用相同的贪心策略解决。
	4. Prove that it is always safe to make the greedy choice. (Steps 3 and 4 can occur in either order. 两者是独立判断标准，无所谓先后)  就是所谓的**贪心选择性质**
	5. Develop a recursive algorithm that implements the greedy strategy.  写出具体递归实现
	6. Convert the recursive algorithm to an iterative algorithm. 改成迭代算法
### Advantages of the Greedy Approach
1. The algorithm is easier to describe. 
2. This algorithm can perform better than other algorithms (but, not in all cases).
### Drawback of the Greedy Approach
- 主要劣势就是贪心算法不是总是produce最优解
【需总结已经学了的哪些问题适用】
### Steps of the Greedy Approach
1. the solution set is empty 解的集合为空
2. At each step, an item is added to the solution set until a solution is reached. 每一步选出一个候选解，判断是否满足条件
3. If the solution set is feasible, the current item is kept.  是->加入
4. Else, the item is rejected and never considered again.  否->拒绝且永不再选
### Different Types of Greedy Algorithm
1. Activity Selection Problem (Our next topic). 
2. Selection Sort 
3. Knapsack Problem 
4. Minimum Spanning Tree 
5. Single-Source Shortest Path Problem 
6. Job Scheduling Problem 
7. Prim's Minimal Spanning Tree Algorithm 
8. Kruskal's Minimal Spanning Tree Algorithm 
9. Dijkstra's Minimal Spanning Tree Algorithm 
10. Huffman Coding 
11. Ford-Fulkerson Algorithm
## Activity Selection Problem
- The problem of scheduling several competing activities requires exclusive use of a common resource, with a goal of selecting a maximum-size set of mutually compatible activities. 共用一个资源，选出最多个互相不冲突的活动，即不重叠
>Suppose we have a set 𝑆 = { $𝑎_1,𝑎_2,…,𝑎_𝑛$ }of 𝑛 proposed activities that wish to use a resource, such as a lecture hall, which can serve only one activity at a time. 
>Each activity $𝑎_𝑖$ has a start time $𝑠_𝑖$ and a finish time $𝑓_𝑖$, where 0 ≤ $𝑠_𝑖 < 𝑓_𝑖 < ∞$. 
>
>If selected, activity $𝑎_𝑖$ takes place during the half-open time interval $[𝑠_𝑖, 𝑓_𝑖]$. 
>Activities $𝑎_𝑖$ and $𝑎_𝑗$ are compatible if the intervals $[𝑠_𝑖, 𝑓_𝑖]$ and $[𝑠_𝑖, 𝑓_𝑖]$ do not overlap. 也就是$𝑎_𝑖$ and $𝑎_𝑗$ are compatible if $𝑠_𝑖 ≥ 𝑓_j$ or $𝑠_𝑗 ≥ 𝑓_𝑖$. 
>In the activity-selection problem, we assume that the activities are sorted in an increasing order of finish time: $𝑓_1 ≤ 𝑓_2 ≤ 𝑓_3 ≤ ⋯≤𝑓_{𝑛−1} ≤𝑓_𝑛$.

再比如Given a resource such as a CPU and 𝑛 set of activities, such as tasks that want to utilize the resource
The activity 𝑖 have the starting and finishing time which is denoted by $𝑠_𝑖$ and $𝑓_𝑖$.
### Steps of Activity Selection Algorithm
Step-1: Set $𝑓_𝑖$ i.e., finish time into non-decreasing order.  
Step-2: Select the next activity 𝑖 to the solution set if 𝑖 is compatible with each activity in the solution set. 
Step 3: Repeat step-2, until all the activities get examined.
### Activity Selection Problem-Time Complexity
GREEDY-ACTIVITY-SELECTOR schedules a set of 𝑛 activities in 𝑂(𝑛) time, assuming that the activities were already sorted initially by their finish times. 𝑇(𝑛)=𝑂(𝑛) 
If the activities are not sorted, they should be sorted by using any sorting algorithm such as merge sort, or quick sort. 
In this case, the time complexity of the sorting algorithm it should be considered
# Part 2
## Knapsack Problem – Greedy Algorithm
- Both greedy and dynamic programming strategies exploit optimal substructure, which can lead to mistakenly choosing a dynamic programming solution when a greedy one suffices, or vice versa
- 0-1 Knapsack 不满足贪心选择性质，只能用动态规划
### Fractional Knapsack Problem
- you can take fractions of items
- Both knapsack problems exhibit the optimal-substructure property.
	For the 0-1 problem, If we exclude item 𝑗 from the load, the remaining load should be the most valuable subset weighing at most 𝑤 − $𝑤_𝑗$ , chosen from the 𝑛−1 original items excluding 𝑗. 
	For the fractional problem, if we remove item 𝑗 weighing 𝑤 from the optimal load, the remaining load should be the highest-value subset weighing up to 𝑊 − 𝑤, selected from the 𝑛 − 1 original items plus $𝑤_𝑗$ − 𝑤 pounds of item 𝑗.
- Although the problems are similar, we can solve the fractional knapsack problem by a greedy strategy, but we cannot solve the 0-1 problem by such a strategy.

- To solve the fractional problem, we first compute the value per pound $𝑝_𝑖 / 𝑤_𝑖$ for each item. 
- in the greedy strategy, you can take as much as possible of the item with the greatest value per pound. 
- If the supply runs out of one item but can carry more, he takes as much as can of the item with the next highest value per pound, continuing this process until he reaches his weight limit 𝑊. 
- Thus, by sorting the items by value per pound, the greedy algorithm runs in O(𝑛𝑙𝑜𝑔𝑛) time
### Knapsack Problem (Greedy Approach) –Time Complexity
𝑇(𝑛) =𝑂(𝑛𝑙𝑜𝑔𝑛)
## Huffman Code
### File Compression
- Suppose we are given a file, which is a string of characters. 
- We wish to compress the file in such a way that the original file can easily be reconstructed. 
- Let the set of characters in the file be 𝐶 = { $𝑐_1, 𝑐_2, .. . , 𝑐_𝑛$ }. 
- Let also 𝑓( $𝑐_𝑖$ ),1 ≤ 𝑖 ≤ 𝑛, be the frequency of character $𝑐_𝑖$ in the file, i.e., the number of times $𝑐_𝑖$ appears in the file. 
- Using a fixed number of bits to represent each character, called the encoding of the character, the size of the file depends only on the number of characters in the file.
- Since the frequency of some characters may be much larger than others, it is reasonable to use variable-length encodings. 
- The characters with large frequencies should be assigned short encodings, whereas long encodings may be assigned to those characters with small frequencies. 
- When encodings vary in length, one character's encoding must not be the prefix of another's; these are called prefix codes.
**离散还是数据结构讲过**
 - Once the prefix constraint is met, decoding is unambiguous没歧义; the bit sequence is scanned until a character's encoding is found
 - To parse a bit sequence, use a full binary tree where each internal node has two branches labeled 0 and 1. 
 - The leaves in this tree correspond to the characters. 
 - Each sequence of 0’s and 1’s on a path from the root to a leaf corresponds to a character encoding. 
 - In follows we describe how to construct a full binary tree that minimizes the size of the compressed file.
### Encoding messages
- Encode a message composed of a string of characters. 
- Codes used by computer systems: 
	ASCII 
		→uses 8 bits per character 
		→can encode 256 characters. 
	Unicode 
		→16 bits per character 
		→can encode 65536 characters 
		→includes all characters encoded by ASCII 
- ASCII and Unicode are fixed-length codes 
	→all characters represented by the same number of bits
#### Drawbacks of fixed-length codes
浪费空间
	Unicode uses twice as much space as ASCII 
		→inefficient for plain-text messages containing only ASCII characters
Potential solution: use variable-length codes 
	→variable number of bits to represent characters when the frequency of occurrence is known 
	→short codes for characters that occur frequently
#### Advantages of variable-length codes
- The advantage of variable-length codes over fixed-length is short codes can be given to characters that occur frequently 
	→The length of the encoded message is less than the fixed-length encoding
- Potential problem: how do we know where one-character ends and another begins? 
	→Not a problem if the number of bits is fixed
### Huffman Coding
- The code constructed by the algorithm satisfies the prefix constraint and minimizes the size of the compressed file
- The algorithm consists of repeating the procedure until 𝐶 consists of only one character. 
- Let $𝑐_𝑖$ and $𝑐_𝑗$ be two characters with minimum frequencies. 
- Create a new node 𝑐 whose frequency is the sum of the frequencies of $𝑐_𝑖$ and $𝑐_𝑗$, and make $𝑐_𝑖$ and $𝑐_𝑗$ the children of 𝑐. 
- 𝐿𝑒𝑡 𝐶 = 𝐶 − { $𝑐_𝑖,𝑐_𝑗$ } ∪ {𝑐}.
- Huffman’s greedy algorithm uses a table of character frequencies to optimally represent each character as a binary string. 
- Huffman Coding is a Greedy Algorithm: 
	→It is used for the lossless compression of data. 
	→It uses variable length encoding. 
	→It assigns variable length code to all the characters. 
- The code length of a character depends on how frequently it occurs in the given text. 
- Prefix Rule: 
	→Huffman Coding implements a rule known as a prefix rule. 
	→This is to prevent ambiguities while decoding. 
	→It ensures that the code assigned to any character is not a prefix of the code assigned to any other character
### Huffman coding tree
- Binary tree 
	→Each leaf contains a symbol (character). 
	→Label the edge from the node to the left child with 0. 
	→Label the edge from node to the right child with 1 
- Code for any symbol obtained by the path from the root to the leaf containing the symbol. 
- Code has prefix property 
	→Leaf node cannot appear on the path to another leaf. 
	→Note: fixed-length codes are represented by a complete Huffman tree and have the prefix property
### Building a Huffman tree
1. Find the frequencies of each symbol occurring in the message. 
2. Begin with a forest of single-node trees. 
	→Each contains a symbol and its frequency 
3. Do recursively. 
	→Select two trees with the smallest frequency at the root. 
	→produce a new binary tree with the selected trees as children and store the sum of their frequencies in the root. 
4. Recursion ends when there is one tree 
	→This is the Huffman coding tree
### Huffman Coding Algorithm
- The main operations required to construct a Huffman tree are insertion and deletion of characters with minimum frequency, a min-heap is a good candidate data structure that supports these operations. 
- The algorithm builds a tree by adding n - 1 internal vertices one at a time; its leaves correspond to the input characters. 
- Initially and during its execution, the algorithm maintains a forest of trees. 
- After adding n-1 internal nodes, the forest is transformed into a tree: the Huffman tree. 
- Algorithm Huffman gives a more precise description of the construction of a full binary tree corresponding to a Huffman code.
### Time complexity
T(𝑛) =O($n\log{n}$)

# Part 3
## Dijkstra’s Algorithm-Shortest Path Problem

The shortest path problem is about finding a path between two vertices in a graph such that the total sum of the weights of the edges is minimum. 
	→Minimization or Optimization problem. 
There are different methods to find the shortest path in a graph, for example: 
	→Depth-First Search (DFS). 
	→Breadth-First Search (BFS). 
	→Bidirectional Search. 
	→Dijkstra’s Algorithm. 
	→Bellman-Ford Algorithm. 
The choice of the proper algorithm is based on the use-case.
### Dijkstra’s Algorithm-Introduction
- Let G = (V, E) be a directed or undirected graph in which each edge has a nonnegative length, and there is a vertex s called the source. 
- The single source shortest path problem is to determine the distance from s to every vertex in V, where the distance from vertex s to vertex x is the length of a shortest path from s to x. 
- For simplicity, we will assume that V= {1, 2, . . . , n} and s= 1. 
- This problem can be solved by a greedy technique known as Dijkstra’s algorithm. 
- Initially, the set of vertices is partitioned into two sets X = {1} and Y = {2, 3, . . . , n}
- The set X contains the vertices whose distance from the source has already been determined. 
- At each step, we select a vertex y ∈ Y whose distance from the source vertex has already been found and moved to X. 
- Associated with each vertex y in Y is a label `λ[y]`, which is the length of a shortest path that passes only through vertices in X. 
- Once a vertex y ∈ Y is moved to X, the label of each vertex w ∈ Y that is adjacent to y is updated, indicating that a shorter path to w via y has been discovered. 
- For any vertex v ∈ V , `δ[v]` will denote the distance from the source vertex to v. 
- At the end of the algorithm, `δ[v] = λ[v]` for each vertex v ∈ V
### Dijkstra’s Algorithm-Greedy Algorithm
- Greedy strategy can be applied: 
	→Problem is solved in stages by taking one step and considering one output at a time to get the optimal solution. 
- Main Idea: 
	→Shortest path vertex is selected next. 
	→Update the shortest path of other vertices. 
- Any vertex can be selected as a source. 
- It can be applied to directed and undirected connected Graphs. 
- Dijkstra does not work for Graphs with negative weight edges. 如果想处理负边，可以考虑 **Bellman-Ford** 算法。
### Dijkstra’s Algorithm-Algorithm Steps
1. Mark your selected initial node with a current distance of 0 and the rest with infinity. 
2. Set the non-visited node with the smallest current distance as the current node. 
	→For each neighbor N of your current node C: 
		→Add the current distance of C with the weight of the edge connecting C to N; if it is smaller than the current distance of N, set it as the new current distance of N. 
		→This called relaxation process. 
3. Mark the current node C as visited. 
4. If there are non-visited nodes, go to step 2.
### Dijkstra’s Algorithm-Time Complexity
$Θ(𝑚 + 𝑛^2) = Θ(𝑛^2)$
### Improving the time bound
- Making a major improvement to Algorithm Dijkstra to lower its $Θ(𝑛^2)$ time complexity to $𝑂(𝑚\log{𝑛})$. 
- The basic idea is to use the min-heap data structure to maintain the vertices in the set Y so that the vertex y in Y closest to a vertex in 𝑉− 𝑌can be extracted in O(log n) time. 
- The key associated with each vertex v is its label `λ[v]`.
### Dijkstra’s Algorithm Applications 
→To find the shortest path. 
→In social networking applications. 
→In a telephone network. 
→To find the locations in the map.
## Kruskal’s Algorithm for finding minimal spanning tree.
### Spanning Tree
- A spanning tree is a sub-graph of an undirected connected graph, which includes all the vertices of the graph with a minimum possible number of edges. 
- If a vertex is missed, then it is not a spanning tree. 
- The edges may or may not have weights assigned to them. 
- The total number of spanning trees with 𝑛 vertices that can be created from a complete graph is equal to $𝑛^{(𝑛−2)}$
### Kruskal’s Algorithm for finding minimal Cost spanning tree
- Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. 
- Kruskal’s algorithm follows the greedy approach as in each iteration it finds an edge that has the least weight and adds it to the growing spanning tree. 
- Kruskal's algorithm finds a minimum spanning tree by selecting a subset of a graph's edges to include every vertex. 
- The resulting tree will have the minimum sum of weights among all the trees that can be formed from the graph
### Kruskal’s Algorithm – Algorithm Steps:
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If a cycle is not formed, include this edge. Else, discard it. 
3. Repeat step 2 until there are (𝑉 − 1) edges in the spanning tree
### Kruskal’s Algorithm – time Complexity
$𝑂(𝑚 \log{𝑛})$














