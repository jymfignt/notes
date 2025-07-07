## Introduction
- Overview of Complexity Theory: 
	Complexity theory studies how ==efficiently== problems can be solved, focusing on resources like **time, memory, and processors**. 
	The ==primary measure== is **time** or the number of **computational steps**, often expressed in terms of input size. 
- Model of Computation:  
	Computation difficulty is analyzed using an informal computational model, such as a Turing machine图灵机. 
- Focus on Yes/No Problems决策问题:  
	The discussion centers on problems that can be reduced to yes/no (decision) questions
## Classes of Problems
- 所有问题
	├── 不可计算问题（如停机问题）
	└── 可计算问题
	    ├── P类（能快速解决）
	    ├── NP类（能快速验证）
	    │   └── NP完全问题（最难的 NP）

- Problems are categorized into three broad classes: 
	1. Undefined Problems: Problems that cannot be formally defined.没有明确数学定义，无法输入输出形式化 
	2. Incomputable Problems: Formally defined problems that cannot be solved computationally. 已形式化，但**无算法**可解
	3. Infeasible Problems: Problems that are solvable theoretically but require impractical computational resources. These are termed intractable or infeasible problems已形式化，但**无算法**可解

1. Decision Problems: 
	Defined as problems where the output is either "yes" or "no." 
	Can be represented by a language 𝐿(𝑄) consisting of inputs for which the answer is "yes."
2. Optimization Problems vs. Decision Problems: 
	Optimization problems require finding the best solution (optimal configuration). 
	Decision problems are simpler; if solving a decision problem is difficult, the related optimization problem is also difficult
3. The Classes 𝑃 and 𝑁𝑃: 
	𝑃: Problems ==solvable== in polynomial time by deterministic algorithms. 
	(Properties: Closed under addition, multiplication, and composition. 对加法、乘法、组合封闭)
	𝑁𝑃: Problems for which a solution can be ==verified== in polynomial time by a deterministic algorithm. 
	𝑁𝑃-Complete problems are a subset of 𝑁𝑃 and are the most challenging within this class. 
4. Verification Algorithms: 
	Verify solutions to problems in **𝑁𝑃** using a certificate. 
	A certificate proves the solution is correct, and verification must be achievable in polynomial time. 
5. Examples: 
	True Boolean Formula: Checking if a Boolean formula is true for a given variable assignment is in 𝑃. 
	PATH Problem: Determining if a path exists between two nodes in a graph is in P
## The Class NP (Non Deterministic Polynomial)
- The set of all problems that can be solved if we always guess correctly what computation path we should follow.
- Roughly speaking, it includes problems with exponential algorithms but has not proved that they cannot have polynomial time algorithms.也就是说其实我们不知道这些问题是真的难还是我们没发现简单解法
- A Language L ∈ NP if and only if there exists a polynomial time verification algorithm A for L. 也就是说你不能保证很快找出答案，但是只要别人给一个推测，你可以很快验证对不对
- Note that L ⊆ NP. At this time we don’t know if P = NP or P ⊂ NP.> **P类问题一定属于NP类**，因为你能解题，当然也能验证嘛。但我们不知道：P是否等于NP（即：那些我们目前不会解的NP问题，将来也许能找到P类算法？）还是P只是NP的一小部分（即：**有些问题就是永远都不能快解**，只能验证）
## NP Completeness
- Reduction:
	the process of transforming one problem into another in polynomial time to demonstrate their equivalence in terms of complexity
	input: two decision problems, L1 and L2
	objective: show L1 is polynomial-time reducible to L2, written as L1 $\le p$ L2.
	若干已知问题可以转换成新问题，且只花多项式时间，那就说明--新问题和已知问题至少一样难
- definition:
	A language 𝐿 ⊆ {0,1} ∗ is NP-complete if it satisfies: 
		1. 𝐿 ∈ 𝑁𝑃 (it is in the class NP)就是能不能快速验证解. 
		2. For every 𝐿′ ∈ 𝑁𝑃, 𝐿′ ≤ 𝑝 𝐿 (there is a polynomial-time reduction from 𝐿′ to 𝐿)即所有 NP 问题都能在多项式时间规约到 L.
	If a language satisfies property 2 but not necessarily property 1, it is termed NP-hard.
- Key Theorem: 
	• If any NP-complete problem is polynomial-time solvable, then 𝑷 = 𝑵𝑷如果你能用多项式时间解出 **任何一个** NP 完全问题，**那么所有 NP 问题都能被快解**！也就是说 **P = NP**. 
	• If any problem in 𝑵𝑷 is not polynomial-time solvable, all 𝑵𝑷-complete problems are not polynomial-time solvable如果你能证明哪怕一个 NP 问题不能快解，那就能证明 P ≠ NP. 
- The 𝑷 = 𝑵𝑷 Question: 
	• It discusses the open question of whether 𝑷 = 𝑵𝑷 or 𝑷 ≠ 𝑵𝑷. 
	• 𝑷=𝑵𝑷 implies that verifying and solving problems can be done in polynomial time. 
	• Despite significant research since the problem was posed, it remains unsolved.
### Proving NP-Completeness
- Method 1 (Direct Proof): 
	•Steps to prove a problem P is NP-complete: 
		•Prove 𝑃∈𝑁𝑃. 
		•Prove all NP-complete problems can be reduced to P. 
	•Example: The Conjunctive Normal Form (CNF)Satisfiability problem.
- Common practical approaches to handle NP-complete problems include: 
	•Backtracking. 
	•Branch and Bound. 
	•Approximation Algorithms
## NP-Hard Problems
- A problem is 𝑵𝑷-hard if every problem in 𝑵𝑷 can be reduced to it. 
- Such problems may or may not belong to𝑵𝑷 (i.e., they may not have a polynomial-time verifiable certificate for "yes" answers可能无法验证解是否正确). 
- Example: 𝑺𝑨𝑻布尔可满足性 is both 𝑵𝑷-hard and 𝑵𝑷-complete.

|分类|能快速验证？|判定问题？|所有 NP 问题可归约？|
|---|---|---|---|
|**P**|✅ 是|✅ 是|❌|
|**NP**|✅ 是|✅ 是|❌|
|**NP-Complete**|✅ 是|✅ 是|✅ 是|
|**NP-Hard**|❌ 不一定|❌ 不一定|✅ 是|
### Satisfiability (SAT)
- SAT is the problem of determining whether a given Boolean formula is satisfiable. 
- Components of SAT: 
	Boolean variables $𝑥_1,𝑥_2$,…. 
	Boolean connectives (AND$\land$, OR$\lor$, NOT$\neg$, etc.). 
	Parentheses. 括号
- Key Properties: 
	•𝑆𝐴𝑇∈𝑁𝑃: A satisfying assignment (certificate) can be verified in polynomial time. 
	•𝑆𝐴𝑇 𝑖𝑠 𝑁𝑃−𝑐𝑜𝑚𝑝𝑙𝑒𝑡𝑒:This is proven via reductions from CIRCUIT-SAT 任何NP问题可以规约成一个SAT问题


- 3-CNF (Conjunctive Normal Form) Satisfiability
	A formula is in conjunctive normal form (CNF) if it is expressed as: $$\phi = C_1 \land C_2 \land \dots \land C_m$$
	where $𝐶_𝑖$ is a clause containing literals (variables or their negations) combined using OR (∨).  
	3-CNF Definition 
		In 3-CNF, each clause子句 has exactly three literals. 
		Example: $(x_1\lor \neg x_2 \lor x_3) \land (\neg x_4 \lor x_5 \lor x_6)$
	Formal Problem Statement 
		Input: A Boolean formula 𝝓 in 3-CNF form. 
		Question: Does there exist an assignment of truth values to variables such that 𝝓 evaluates to true? 
		Example $\phi = (x_1\lor \neg x_2 \lor x_3) \land (\neg x_4 \lor x_5 \lor x_6)$ Is there an assignment of $x_1, x_2, x_3, x_4, x_5, x_6$ that satisfies $\phi$?
	3-CNF-SAT and NP-Completeness 
		3-CNF-SAT is a fundamental problem in computational complexity. 
		It is 𝑵𝑷-complete, which means: 
			1. 3-CNF-SAT∈𝑵𝑷:A satisfying assignment (certificate) can be verified in polynomial time在多项式时间内可以验证赋值. 
			2. 3-CNF-SAT is 𝑵𝑷-hard: It is at least as hard as every other problem in 𝑵𝑷
	Proof of NP-Completeness 
		Membership in NP: 
			Given a Boolean formula 𝝓 and an assignment of values, evaluating 𝝓 takes polynomial time. 
		NP-Hardness: 
			The 𝑵𝑷-hardness of 3-CNF-SATis shown by reducing the general SAT problem(which is NP-complete) to 3-CNF-SAT in polynomial time.
	Reduction简化 to 3-CNF-SAT 
		Convert a Boolean formula into a binary parse tree: 
			Leaves = literals. 
			Internal nodes = logical operators (AND, OR, NOT). 
		Introduce auxiliary variables𝑦𝑖 for outputs of internal nodes. 
		Transform the formula into an equivalent 3-CNF form while preserving logical structure
	Significance of 3-CNF-SAT 
		3-CNF-SATis a foundational problem in computational complexity theory. 
		It serves as a starting point for proving 𝑁𝑃-completeness of other problems (e.g., CLIQUE, VERTEX-COVER). 
		Understanding reductions to 3-CNF-SAT is critical for analyzing 𝑁𝑃-complete problems.
### The CLIQUE Problem
- The CLIQUE problem is a classic NP-complete problem in computational theory and graph algorithms. 
- It focuses on determining whether a graph contains a subset of vertices that form a complete subgraph of a given size 𝑘
- definition:
	Input: An undirected graph 𝐺=(𝑉,𝐸)and an integer 𝑘. 
	Question: Does 𝑮contain a clique of size 𝑘? A clique is a subset of vertices 𝑉′⊆𝑉 such that every pair of vertices in 𝑉′is connected by an edge in 𝑮.
- example:
	For a graph G, if k=3, the problem asks whether there exists a group of 3 vertices such that all pairs among them have edges
	a triangle in G is an example of a clique of size 3
- NP-Completeness 
- To show that the CLIQUE problem is NP-complete: 
	1. 𝑳𝑰𝑸𝑼𝑬∈𝑵𝑷:  A proposed solution (a subset of 𝑘 vertices) can be verified in polynomial time by checking that all pairs of vertices in the subset are connected by edges. 
	2. Reduction:  The CLIQUE problem is proven 𝑁𝑃-Hard by reducing another 𝑁𝑃-complete problem to it. For instance, 3-SATcan be reduced to CLIQUE in polynomial time.
- Connection to Other Problems 
	Vertex-Cover:  Vertex-Cover and CLIQUE are complementary problems. If you solve one, you can solve the other in the graph's complement.  
	Hamiltonian-Cycle and TSP:  A Hamiltonian cycle can also be viewed as a clique structure when considering specific graph constructions



























