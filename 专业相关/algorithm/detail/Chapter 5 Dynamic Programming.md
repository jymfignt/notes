
# Part 1

### Introduction
- a powerful algorithm design technique that is widely used to solve optimization优化 problems
- 也被用来improve the time complexity of the brute-force methods to solve some of the NP-hard problems
- not recursive, but the underlying solution of the problem is usually stated in the form of a recursive function
- 不像分而治之算法，immediate implementation of the recurrence results in identical recursive calls that are executed more than once 
- 因此，该技术evaluates the recurrence in a bottom-up manner, saving intermediate results to be used later to compute the desired solution
>traveling salesman problem
>$O(n^22^n)$ using dynamic programming
>-- is superior to the $\Theta(n!)$ bound that enumerates枚举 all possible tours

- `Programming` refers to a tabular表格的 method, 而不是指写电脑代码
- $$\begin{cases}
\text{divide-and-conquer algorithm} &\text{划分为不相交的子问题，递归地解决，然后组合解决方案来解决原始问题} \\
\text{dynamic programming} &\text{适用于子问题重叠overlap的情况，也就是子问题共享的时候} \\
&\text{也就是在这种情况下，分而治之算法会做更多工作，重复解决common subproblems}
\end{cases}$$
- dynamic-programming algorithm 每个subproblem只解决一次，然后把回答保存到一个表格，因此避免了每次求解每个子问题时重新计算答案的工作
- optimization problems有许多possible solutions，我们希望找到a solution with the optimal (minimum or maximum) value
- 我们称呼一个解叫an optimal solution to the problem 因为可能存在several solutions that achieve the optimal value
- summary:
	1. 在所有解决方案中找到最佳解决方案，并选出最优的一个
	2. The principle of optimality introduced by Richard bellman in 1955
	3. `dynamic` reflects the time-varying aspect of the problems
	4. `programming` refers to the tabular method to solve a problem
	5. solves every subproblem just once and saves解决方案到一个表格里，避免每次遇到子问题都重新计算解
	6. 动态规划不是一种算法，只是一种设计算法的technique技术/strategy策略
### Properties
Q: 你怎么就知道优化问题可不可以用动态规划来解决呢
A: Dynamic programming works if a problem exhibits具有 the following two properties:
	1. Optimal sub-structure: An optimal solution to the problem contains within it, optimal solutions to sub-problems
	2. Overlapping sub-problems: When 递归算法重复访问同一个问题时，the optimization problem has overlapping sub-problems

#### The principle of optimality
- Bellman's principle of optimality
	An optimal policy (set of decisions) has the property that, regardless of the initial state and decisions, the subsequent decisions must from an optimal policy relative to the state resulting from the first decision
	最优策略（决策集）具有这样的特性：无论初始状态和决策如何，后续决策都必须形成相对于第一个决策所产生的状态的最优策略
- Mathematically, $$\begin{align}
&f_N(x)=max. [r(d_n)+f_N-1T(x,d_n)]d_n \in x \\
&\text{where }f_N(x)= \text{optimal return from an N-stage process when initial state is x} \\
& \text{ }\text{ } \text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }r(d_n)= \text{immediate return due to decision }d_n \\
& \text{ } \text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }T(x,d_n) = \text{the transfer function which gives the resulting state}\\
&\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{} \{x\}=\text{set of admissible decisions}\\
\end{align}$$
This equation is also known as a dynamic programming equation.
- It writes the value of a decision problem决策问题 at a certain point in time in terms of the payoff收益 from some initial choices and the value of the remaining decision problem that results from those initial choices
- this breaks a dynamic optimization problem into simpler subproblems
#### Steps to develop a Dynamic programming algorithm

1. Characterize描述 the structure of an optimal solution
2. Recursively define the value of an optimal solution
3. compute the value of an optimal solution, typically in a bottom-up自下而上 fashion
4. construct an optimal solution from computed information

 - 1-3步构成了动态规划解决问题基础
 - If 我们只需要最优解optimal solution的值而不是解本身，我们可以省略omit第4步
 - When第4步，我们有时会在第3步maintain保留额外信息，这样我们可以轻松construct an optimal solution
#### Example: Fibonacci Sequence
- Consider the inductive definition of this sequence: $$f(n)=\begin{cases}
1 & if \text{ } n=1 \text{ or } n=2, \\
f(n-1)+f(n-2) & if \text{ }n\ge3.
\end{cases}$$
- This definition suggests a recursive procedure that looks like the following (假设输入恒为正): 
	1. procedure $f(n)$
	2. if (n=1) or (n=2) then return 1
	3. else return $f(n-1) + f(n-2)$
虽然这样准确，易写，易debug，大多数抽象；但是效率不高，过程中太多重复recursive calls
- If we assume that computing f(1) or f(2) requires a unit amount of time, then the time complexity of this procedure can be stated as: $$T(n)=\begin{cases}
1 & if \text{ } n=1 \text{ or } n=2, \\
T(n-1)+T(n-2) & if \text{ }n\ge3.
\end{cases}$$
显而易见，这个recurrence解是 $T(n) = f(n)$ (也就是说计算$f(n)$ 所需时间是$f(n)$ itself)
换句话说，计算$f(n)$所需时间is exponential in the value of n

### Memoization
- top-down approach to solving a problem with dynamic programming
- 被叫做记忆化memoization，因为we will create a memo, or a "note to self", for the values returned from solving each problem.
- 这样，当我们再次遇到同样的问题，我们simply check the memo, 而不是再次解决问题
#### Example: Top-Down Fibonacci

```python
const fibDown = (n,memo[ ])=>{
if (n==0 || n==1){
        return n;
}
    if (memo[n] == undefined){
        memo[n] = fibDown(n-1,memo) + fibDown(n-2,memo);
    }
    return memo[n];
}
```
Memoization changed the complexity from O($n^2$) to O(n), from exponential to linear

Why? Because we don’t solve the overlapping subproblems. This is a big improvement over the naive implementation.

### Tabulation: Down-up
- with bottom-up, or 制表tabulation, we start with the smallest problems and use the returned values to calculate larger values
- 我们可以理解为在table表格或spreadsheet中输入值，然后applying a formula to these values
#### Example: Fibonacci
```c
int fib(int n)
{
   if(n<=1)
	   return n;
   f[0]=0;
   f[1]=1;
   for(int i=2;i<=n;i++)
   {
	   f[i]=f[i-2]+f[i-1];
   }
   return f(n);
}
```
时间复杂度依旧为O(n)
Why？因为用了for循环，不过空间复杂度为O(1)，因为no recursion

## Assembly Line Scheduling Problem

### Assembly Line Scheduling

>Automobile factory has two assembly lines
> ->每条线有n个站点： $S_{1,1}, \dots ,S_{1,n}$ and $S_{2,1}, \dots ,S_{2,n}$
> ->corresponding stations $S_{1,j}$ and $S_{2,j}$ 执行相同的function 但是花费不同时间$a_{1,j}$ and $a_{2,j}$
> ->entry times are $e_1$ and $e_2$ and exit times are $x_1$ and $x_2$
>After going through a station, the car can either:
>-> stay on the same line at no cost, or
>->transfer to other line: cost after $S_{i,j}$ is $t_{i,j}, j=1,\dots ,n-1$
>Problem: what stations should be chosen from line 1 and line 2 in order to minimize the total time through the factory for one car?
### Brute force solution
- A brute force algorithm solves a problem through exhaustion: it goes through all possible choices until a solution is found.
- 时间复杂度通常是proportional to the input size
- 简单且一致，但是非常慢

- enumerate all possibilities for selecting stations
- compute how long it takes in each case and choose the best one
- 有 $2^n$ 个可能去选择站台，不可行Infeasible当n is large
### The steps to design an algorithm by using Dynamic programming

#### 1.Structure of the Optimal Solution
	
- 假设the fastest way through $S_{1,j}$ is through $S_{1,j-1}$
	an optimal solution to the problem “Find the fastest way through $S_{1,j}$“ contains within it an optimal solution to subproblems: ” Find the fastest way through $S_{1,j-1}$ or $S_{2,j-1}$“. 
	
	This is referred to as the optimal substructure property.
	
	Same is the case with $S_{2,j-1}$
#### 2.Recursively define the value of an optimal solution

- We define the value of an optimal solution in terms of the optimal solution to subproblems. 
- Definitions:

	$f^*$:  The fastest time to get through the entire factory.
	$f_i[j]$: the fastest time to get from the starting point through station $S_{i,j}$
	$l^*$: the line number which is used to exit the factory from the $n^{th}$ station
	$l_i[j]$: the line number (1 or 2) whose $S_{i,j-1}$ is used to reach $S_{i,j}$
  The objective function $$f^* = min(f_i[n]+x_1,f_2[n]+x_2)$$
- Base case: j=1, i=1,2 (getting through station 1)
	$f_1[1]$ = $e_1$ + $a_{1,1}$
	$f_2[1]$ = $e_2$ + $a_{2,1}$

- General case: j=2,3, ... ,n and i=1,2
The fastest way through $S_{1,j}$ is either:
	The way through $S_{1,j-1}$ then directly through $S_{1,j}$ or $f_1[j-1] + a_{1,j}$
	The way through $S_{2,j-1}$, transfer from line 2 to line 1, then through $S_{1,j}$ or $f_2[j-1] + t_{2,j-1} + a_{1,j}$
$f_1[j]=min(f_1[j-1]+a_{1,j}, f_2[j-1]+t_{2,j-1}+a_{1,j})$ 

- 公式来表示： $$f_1[j] = \begin{cases}
e_1 +a_{1,1} &if \text{ }j = 1\\
min(f_1[j-1]+a_{1,j}, f_2[j-1]+t_{2,j-1}+a_{1,j}) & if \text{ }j\ge 2
\end{cases}$$
$$f_2[j] = \begin{cases}
e_2 +a_{2,1} &if \text{ }j = 1\\
min(f_2[j-1]+a_{2,j}, f_1[j-1]+t_{1,j-1}+a_{2,j}) & if \text{ }j\ge 2
\end{cases}$$
#### 3.Compute the optimal solution
- using the bottom-up approach, first found optimal solutions to subproblems, and then use them to find an optimal solution to the problem
- for j>=2, each value $f_i[j]$ depends on the values of $f_1[j-1]$ and $f_2[j-1]$
- in increasing order of j
------------------------------------------->

|          |    1     |    2     |    3     |    4     |    5     |
| -------- | :------: | :------: | :------: | :------: | :------: |
| $f_1[j]$ | $f_1(1)$ | $f_1(2)$ | $f_1(3)$ | $f_1(4)$ | $f_1(5)$ |
| $f_2[j]$ | $f_2(1)$ | $f_2(2)$ | $f_2(3)$ | $f_2(4)$ | $f_2(5)$ |
# Part 2
### Longest Common Subsequence (LCS) Problem
#### Introduction
>Given 两个string A和B，分别长n和m，决定一下the length of the longest subsequence that is common to both A and B

A subsequence of A = $a_1a_2,\dots,a_n$ is a string of the form $a_{i1}a_{i2},\dots,a_{ik}$ , where each $i_j$ is between 1 and n and $1\le i_1 < i_2 < \dots <i_k \le n$ 
举例来说， if S={`x, y, z`}, A=`zxyxyz`, and B=`xyyzx`, then `xyy` is a subsequence of length 3 of both A and B, 但不是最长的 (LCS), 因为`xyyz`也是common subsequence of length 4 of both A and B

#### Common Subsequences
假设X和Yare two sequences over a set of S={A,B,C,D}
	X:ABCBDAB
	Y:BDCABA
	Z:BCBA
Z is a common subsequence of X and Y if and only if: 
	→Z is a subsequence of X 
	→Z is a subsequence of Y
LCS problem asks to find a common subsequence of X and Y that is of maximal length.
#### Example
X= {A B C B D A B }, Y= {B D C A B A}
The brute force algorithm would compare each subsequence of X with the symbols in Y
#### A Poor Approach to the LCS Problem
- 一个解决问题的方法就是用brute-force method：
	enumerate all the $2^n$ subsequence of A
	for each subsequence determine if it is also a subsequence of B in $\Theta(m)$ time
- Clearly, the running time of this algorithm is $\Theta(m2^n)$, which is exponential
#### Applying Dynamic Programming Recursive formula for LCS
- To use the dynamic programming, we first find a recursive formula for the length of the LCS
- A = $a_1a_2,\dots,a_n$ and B = $b_1b_2,\dots,b_m$
- L`[i,j]` 定义LCS的长度
- 注意i或j可能为0，也就是说A或者B可能为空string
- If i=0 or j=0, then $L[i,j]$ = 0
- $\text{Suppose that both i and j are greater than 0. Then}$
	- If $a_i = b_j$, $L[i,j] = L[i-1,j-1]+1$
	- If $a_i \ne b_j$, $L[i,j] = max{L[i,j-1],L[i-1,j]}$
- $$L[i,j]=
  \begin{cases}
  0 & if\text{ }i=0 \text{ }or\text{ }j=0, \\
  L[i-1,j-1]+1 &if\text{ } i>0, j>0, \text{ }and \text{ }a_i=b_j, \\
  max\{ L[i,j-1],L[i-1,j]\} &if\text{ }i>0, j>0,\text{ }and\text{ }a_i \ne b_j
  \end{cases}$$
#### Developing a dynamic programming solution to the LCS problem
- straightforward
- 用一个 (𝑛 + 1) × (𝑚 + 1) 表格计算`L[i,j]`值 for each pair of values of i and j, $0 \le i \le n$ and $0 \le j \le m$
- We need to fill the table $𝐿[0\dots 𝑛, 0\dots 𝑚]$ row by row using the formula
Steps:
	1. Find the length of LCS
	2. modify the algorithm to find LCS itself
	3. 定义 $X_i,Y_j$ to be the prefixes of X and Y of length i and j respectively
	4. 定义 `c[i,j]` to be the length of LCS of $X_i$ and $Y_j$
	5. Then X and Y的LCS长度就是 `c[m,n]`
$$c[i,j] = 
\begin{cases}
c[i-1,j-1]+1 &if \text{ }x[i]=y[j],\\
max(c[i,j-1],c[i-1,j]) &otherwise \\
\end{cases}$$
- steps to find actual LCS:
	从`c[m,n]`开始并往回倒
	whenever $c[i,j] = c[i-1,j-1] + 1$, $x[i]$ is a part of LCS
	当i=0 or j = 0（也就是到达开始，输出 showed letters in reverse order)
- complexity:
	time complexity: 就是表格大小，$\Theta(nm)$,因为填每个entry 需要 $\Theta(1)$ 时间
	但是这个algorithm can easily be modified so that it requires only Θ(min{𝑚,𝑛}) space. 

# Part 3
### Matrix Chain Multiplication Problem
#### Introduction
假设我们需要计算三个矩阵乘积，M1 M2 M3分别是 $2\times 10 \text{ } 10 \times 2 \text{ }2 \times 10$
If 先乘 M1 M2, 结果再乘M3, 
	the number of scalar multiplications will be 2×10×2+2×2×10 = 80
Else if 先乘 M3 M2, 结果再乘M2,
	the number of scalar multiplications becomes 10 × 2 × 10 + 2 × 10 × 10 =400
普通矩阵乘法就是需要a×b×c次乘法（矩阵大小 a×b b×c）
#### The ways to multiply chain of 𝒏 matrices
- 乘两个矩阵只有一种方法，乘三个矩阵有两种途径
  也就是 $f(2)=1 \text{ and } f(3)=2$
- to make sense if the recurrence, we let f(1) = 1
- 那么first 10 terms：
	1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, .....
	有4862 ways去乘10个矩阵
- Let f(n) be the number of ways to parenthesize a product of 𝑛 matrices
	我们可以分开执行乘法 $$(M1M2\dots Mk)\times(Mk+1Mk+2\dots Mn)$$
	有 $f(k)$ 方法去乘前k个矩阵
	对于每个 $f(k)$ 方法，有 $f(n-k)$ ways 去parenthesize the remaining n-k 矩阵
	the overall number of ways to parenthesize the n matrices is given by the summation $$f(n) = \sum\limits_{k=1}^{n-1}f(k)f(n-k)$$
#### Brute-force method
- The cost of multiplying a chain of 𝑛matrices 𝑀1𝑀2...𝑀𝑛 depends on the order in which the 𝑛−1 multiplications are carried out. 
- The order which minimizes the number of scalar multiplications can be found in many ways. 
- Brute-force method tries to compute the number of scalar multiplications of every possible order.
Brute force method of exhaustive search takes time exponential in 𝑛.
#### Dynamic Programming Approach
- Dynamic programming method can be used to efficiently solve the matrix chain problem in time $\Theta(n^3)$.
1. The structure of an optimal solution:
	用 $A_{i\dots j}$ 表示 $A_i A_{i+1}\dots A_j$ 乘积
	An optimal parenthesization of the product $A_1 A_2\dots A_n$ splits the product between $A_k$ and $𝐴_{𝑘+1}$ for some integer 𝑘 where $1 \le k < n$
	先计算矩阵 $A_{1\dots k}$ 和 $A_{k+1\dots n}$， 然后把它们相乘得到 $A_{1\dots n}$
 为啥要这样分开再合并？因为一个大的问题的最优解包含子问题的最优解
2. Recursive definition of the value of an optimal solution
	let `c[i,j]` be the minimum number of scalar multiplications necessary to compute $A_{i\dots j}$ 
	minimum cost to compute $A_{i\dots n}$ is `m[1,n]`
	假设 optimal parenthesization of $A_{i\dots j}$   splits the product between $A_k$ and $𝐴_{𝑘+1}$ for some integer 𝑘 where $1 \le k < j$
	Cost of computing $A_{i\dots j}$ = cost of computing $A_{i\dots k}$ + cost of computing $A_{k+1\dots j}$ + cost of multiplying $A_{i\dots k}$ and $A_{k+1\dots j}$ ($d_{i-1}d_kd_j$)
	$$c[i,j]=
	\begin{cases}
	0 &if \text{ }i=j \\
	c[i,j]=min\{\ c[i,k]+c[k+1,j]+d_{i-1}\times d_k \times d_j \}\ &if \text{ }i<j \\
	\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }\text{ }i\le k < j
	\end{cases}$$
3. Construct Optimal Solution
	Our algorithm computes the minimum-cost table 𝑐and the split table k
	每个 entry `k[i,j]` shows where to split the product $A_iA_{i+1}\dots A_j$ for the minimum cost
	需要动态规划两个性质：Optimal Substructure（最优子结构），Overlapping Subproblems（子问题重叠）
- Number of ways for parenthesizing the matrices：
	is very closely tied to the number of ways to write valid nested parentheses
	This sequence is called the Catalan numbers
	Now there are 'L' ways of parenthesizing the left sub-list and 'R' ways of parenthesizing the right sub-list then the Total will be L.R: $$p(n) = \begin{cases}1 &if \text{ } n=1\\ \sum\limits_{k=1}^{n-1}p(k)p(n-k) &if \text{ } n \ge 2\end{cases}$$
	Also, p(n)=c(n-1) where c(n) is the nth Catalan number: $$c_n = \frac{1}{n+1}\dbinom{2n}{n} = \frac{(2n)!}{(n+1)!n!}$$
- complexity:
	$\Theta(n^3)$ time and $\Theta(n^2)$ space
# Part 4
### The 0-1 Knapsack Problem
#### Knapsack Problem-Introduction
- Let U ={ $u_1,u_2,\dots ,u_n$ } be a set of n items to be packed in a knapsack of size C
- for $1\le j \le n$, let $s_j$ and $v_j$ be the size and value of the jth item, respectively
- here C and $s_j$, $v_j$, $1 \le j \le n$, are positive integers
- objective: fill the knapsack with some item from U whose total size is at most C and such that their total value is maximum
- assume 每个item大小没超过C
- more formally, given U of n items, we want to find a subset S $\subseteq$ U such that $$\sum_{u_i\in S}v_i$$
  is maximized subject to the constraint $$\sum_{u_i \in S}s_i \le C$$
- given weights and values (profits) of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack
- two versions of the problem:
	"0-1" knapsack problem: items are indivisible, you either take an item or not
	fractional knapsack problem: items are divisible,  you can take any fraction of an item
#### 0-1 Knapsack Problem
- 已知一个背包最大容量 W，且一个由n个items 组成的set S
- 每个item i has some weight $w_i$, and benefit value $P_i$ (All $w_i$ and P and W are integer values)
- 问题就是：怎么打包背包才能实现打包物件总价值最大呢？
- naive way简单方法: cycle through all $2^n$ subsets of the n items and pick the subset with a legal weight that maximizes the value of the knapsack
- running time is O($2^n$)
- 不过我们可以找一个动态规划的算法that will usually do better than this brute force technique
#### Recursive formula of the problem
- We derive a recursive formula for filling the knapsack as follows:
	let `V[i,j]` denote the value obtained by filling a knapsack of size j with items taken from the first i items { $u_1, u_2,\dots ,u_i$ } in an optimal way
	here the range of i is from 0 to n and the range of j is from 0 to C
	Thus, what we seek is the value `V[n,c]`

	`V[0,j]` is 0 for all values of i, 因为背包里什么也没有
	`V[i,0]` is 0 for all values of j, 因为没有东西可以放到大小为0的背包里
	When both 𝑖 and 𝑗 are greater than 0, we have the following observation, which is easy to prove: $$V[i,j]=\begin{cases}0 &if \text{ }i=0 \text{ or } j=0,\\ V[i-1,j] &if \text{ } j<s_i,\\ max \{V[i-1,j],V[i-1,j-s_i]+v_i \} &if \text{ }i>0 \text{ and } j\le s_i.   \end{cases}$$
	`V[i-1,j]`: The maximum value obtained by filling a knapsack of size j with items taken form { $u_1,u_2,\dots ,u_{i-1}$ } only in an optimal way
	`V[i-1,j-`$s_i$`]` + $v_i$: The maximum value obtained by filling a knapsack of size j-$s_i$ with items taken from { $u_1,u_2,\dots ,u_{i-1}$ } in an optimal way plus the value of item $u_i$. This case applies only if j $\ge$ s, and it amounts to adding item $u_i$ to the knapsack
#### Dynamic Programming Approach
- first attempt might be to characterize a sub-problem as follows:
	let $S_i$ be the optimal subset of elements from { $l_0,l_1,\dots,l_i$ }
	我们能发现的就是 the optimal subset from the elements { $l_0,l_1,\dots,l_{i+1}$ } may not correspond to the optimal subset of elements from { $l_0,l_1,\dots,l_i$ } in any regular pattern
	The solution to the optimization problem for $S_{i+1}$ might not contain the optimal solution from problem $S_i$
- we must re-work the way we used to build the previous sub-problem:
	let `V[i,w]` represent the maximum total value of a subset $S_i$ with weight w
	目标就是找到 `V[n,W]`, where n是items总数量，W是最大weight，这个背包可以承载的
- recursive formula for subproblems: $$\begin{align}
V[i,w] &= V[i-1,w],\text{ if } w_i > w
\\
&=max \{ V[i-1,w],V[i-1,w-w_i]+P_i \}
\end{align}$$
- The best subset of $𝑆_𝑖$ that has the total weight 𝑤, either contains item 𝑖 or not.
	First case: $w-w_i <0$ 
		Item 𝑖 can’t be part of the solution! If it was the total weight would be < 0, which is unacceptable.
	Second case: $w-w_i \ge 0$ 
		Then the item 𝑖 can be in the solution, and we choose the case with greater value.
	$$V(i,w) = \begin{cases}V(i-1,w)&if\text{ }w-w_i <0\\max(V(i-1,w),V(i-1,w-w_i)+P_i) &if \text{ }w-w_i \ge 0 \end{cases}$$
- We use an $(n+1) \times (C+1)$ table to evaluate the values of `V[i,j]`
- We only need to fill the table 𝑉 `[0..𝑛,0..𝐶]` row by row using the formula.
- The time complexity of the algorithm is exactly the size of the table, Θ (𝑛C) or Θ (𝑛𝑊) ,as filling each entry requires Θ(1) time. $$T(n) = O(n×C)$$
- It can also be easily modified so that it requires only Θ(𝐶) of space, as only the last computed row is needed for filling the current row.
### Floyd's Algorithm
#### Floyd's Algorithm-Introduction
- Floyd-Warshall Algorithm 是between all the pairs of vertices in a weighted graph找最短路径的算法
- for both the directed and undirected weighted graphs
- does not work for the graphs with negative cycles (Where the sum of the edges in a cycle is negative)(may contain negative edges)
- Let G = (V, E) be a directed graph in which each edge (𝑖, 𝑗) has nonnegative length `𝑙[𝑖, 𝑗]`.
- if there is no edge from vertex 𝑖 to vertex 𝑗, then $𝑙[𝑖, 𝑗] = ∞$
- For simplicity, we will assume that 𝑉 = {1,2,...,𝑛}. 
- Let 𝑖 and 𝑗 be two different vertices in V . 
- Define $𝑑_{𝑖,𝑗}^𝑘$ to be the length of a shortest path from 𝑖 to 𝑗 that does not pass through any vertex in {𝑘 + 1,𝑘 + 2,...,𝑛}.
- Then, by definition, $𝑑_{𝑖,𝑗}^n$  is the length of a shortest path from 𝑖 to 𝑗 , i.e., the distance from 𝑖 to 𝑗 .
- $$d^k_{i,j}=\begin{cases}
l[i,j] &if\text{ }k=0 \\
min \{ d_{i,j}^{k-1}, d_{i,k}^{k-1}+d_{k,j}^{k-1}\} &if\text{ }1\le k \le n
\end{cases}$$
- Summary
	a weight matrix, where:
		$l(i,j) = 0 \text{ }if \text{ }i=j$
		$l(i,j) = \infty \text{ }if\text{ there is no edge between i and j}$  
		$l(i,j) =$ "weight of edge"
	Principle of optimality (一个问题的最优解包含其子问题的最优解) is applies to shortest-path problems.
#### The subproblem
- How can we define the shortest distance $𝑑_{𝑖,𝑗}$ in terms of “smaller” problems?
	One way is to restrict the paths to only include vertices from a restricted subset. →Initially, the subset is empty. 
	→Then, it is incrementally increased until it includes all the vertices
- Let$D^{(k)}[𝑖,𝑗]$ =weight of a shortest path from $𝑣_𝑖$ to $𝑣_𝑗$ using only vertices from { $𝑣_1,𝑣_2,…,𝑣_𝑘$ }as intermediate vertices in the path. 
	→D(0)=W 
	→D(n)=D which is the goal matrix 
- How do we compute D(k) from D(k-1)?
#### The Recursive Formula
- Case 1: A shortest path from $𝑣_𝑖$ to $𝑣_𝑗$ restricted to using only vertices from { $𝑣_1, 𝑣_2, …,𝑣_𝑘$ } as intermediate vertices does not use $𝑣_𝑘$. 
	→Then $D^{(k)}[𝑖,𝑗] = D^{(k-1)}[𝑖,𝑗]$. 
- Case 2: A shortest path from $𝑣_𝑖$ to $𝑣_𝑗$ restricted to using only vertices from { $𝑣_1, 𝑣_2, …,𝑣_𝑘$ } as intermediate vertices does use $𝑣_𝑘$. 
	→Then $D^{(k)}[𝑖,𝑗] = D^{(k-1)} [𝑖,𝑘]+ D^{(k-1)}[𝑘, 𝑗]$.
- We conclude: $$D^{(k)}[i,j] = min \{D^{(k-1)}[i,j],  D^{(k-1)} [𝑖,𝑘]+ D^{(k-1)}[𝑘, 𝑗]\}$$
#### The Algorithm
- solves the given recurrence in a bottom-up fashion
- uses n + 1 matrices $𝐷_0, 𝐷_1, …,𝐷_𝑛$ of dimension 𝑛 × 𝑛 to compute the lengths of the shortest paths. 
- Initially, we set $𝐷_0[𝑖, 𝑖]$ = 0 and $𝐷_0[𝑖,𝑗] = 𝑙[𝑖,𝑗]$ if 𝑖 ≠ 𝑗 and (𝑖,𝑗) is an edge in G; otherwise, $𝐷_0[𝑖, 𝑗] = ∞$. 
- We make 𝑛 iterations such that after the 𝑘𝑡ℎ iteration, $𝐷_𝑘[𝑖,𝑗]$ contains the value of a shortest length path from vertex 𝑖 to vertex 𝑗 that does not pass through any vertex numbered higher than 𝑘. 
- In the 𝑘𝑡ℎ iteration, we compute $𝐷_𝑘[𝑖,𝑗]$ using the formula: $$D_k[i,j] = min \{D_{k-1}[i,j] ,D^{(k-1)} [𝑖,𝑘]+ D^{(k-1)}[𝑘, 𝑗]\} $$
- The overall time complexity of the Floyd Warshall algorithm is $𝑂(𝑛^3)$ where 𝑛 denotes the number of nodes in the graph.
- Its space complexity is $𝑂(𝑛^2)$

# Part 5
### Optimal Binary Search Tree
#### Introduction
- A binary search tree is one of the most important data structures in computer science. A binary Tree is defined as a tree data structure where each node has at most 2 children, the left and right child.
- An optimal binary search tree (OBST) is a binary search tree which provides the smallest possible search time (or expected search time) for a given sequence of accesses (or access probabilities).
- One of its principal applications is to implement a dictionary, a set of elements with searching, insertion, and deletion operations.
- It focuses on reducing the cost of the search of the Binary Search Tree (BST)
- 可能没有lowest height
- needs 3 tables to record probabilities, cost, and root.

- OBST has 𝑛 keys (representation $𝑘_1,𝑘_2,…,𝑘_𝑛$ ) in sorted order (so that $𝑘_1 < 𝑘_2 < ⋯ < 𝑘_𝑛$ ), and we wish to build a binary search tree from these keys. 
- For each $𝑘_𝑖$ , we have a probability $𝑝_𝑖$ that a search will be for $𝑘_𝑖$. 
- Some searches may be for values not in $𝑘_𝑖$, so we have 𝑛 + 1 “dummy keys” $d_0, 𝑑_1, …,𝑑_𝑛$ not in $𝑘_𝑖$. 
- $𝑑_0$ represents all values less than $𝑘_1$, and $𝑑_𝑛$ represents all values greater than $𝑘_𝑛$, for i =1,2,…,𝑛 −1, the dummy key $𝑑_𝑖$ represents all values between $𝑘_𝑖$ and $𝑘_𝑖$+1. 
- 也就是说 $d_0$ 代表 ( $-\infty ,k_1$ ), $d_1$ 代表（ $k_1, k_2$ ）, $\dots$, $d_i$ 代表 ( $k_i, +\infty$ ) 
- The dummy keys are leaves (external nodes), and the data keys mean internal nodes.
- Successful Search: Finding the element within the tree. 
- Unsuccessful Search: not Finding the element within the tree and it is represented by dummy nodes. 
- Search could be successful or unsuccessful, in both cases we need to know the number of comparisons that we are doing, the number of comparisons is the cost of searching an element in BST
- The total number of possible Binary Search Trees with 𝑛 different keys can be calculated by:  $CountBST(n))=Catalan \text{ } number \text{ }C_n = \frac{(2n)!}{((n+1)!\times n!)}$
#### Formula & Prove
- The case of search is two situations, one is a success, and the other, is a failure. We can get the first statement : $$\sum\limits_{i=1}^{n}p_i +\sum\limits_{i=1}^{n}q_i =1$$
  $p_i -> success$,   $q_i -> failure$
- 已知probabilities of searches for each key and each dummy key，我们可以determine期望cost of a search
- 假设the actual cost of a search is the number of nodes examined, i.e., the depth of the node found by the search in T plus 1.
- Then the expected cost of a search in T is: $$\begin{align} E[\text{search cost in T}]&= (i=1 \sim n)\sum p_i \times (depth_T(k_i)+1)  \\
+ (i=0 \sim &n)\sum q_i \times (depth_T(d_i)+1)  \\
 = 1 +(i&=1 \sim n)\sum p_i \times depth_T(k_i)  \\
+ (i=&0 \sim n)\sum q_i \times depth_T(d_i) \end{align}$$
  Where $depth_T$ denotes a node’s depth in the tree T
- height最小不一定有最小cost，同时最大概率不在leave？
#### Dynamic Approach
##### Step1: The structure of an OBST
- To characterize the optimal substructure of OBST, we start with an observation about subtrees.
- Consider any subtree of a BST. It must contain keys in a contiguous range $𝑘_𝑖,…,𝑘_𝑗$, for some 1≤𝑖≤𝑗≤𝑛. 
- A subtree that contains keys  $𝑘_𝑖,…,𝑘_𝑗$ must have as leaves the dummy keys $𝑑_{𝑖−1},…,𝑑_𝑗$
- Given keys  $𝑘_𝑖,…,𝑘_𝑗$, 其中一个 $k_r (i\le r\le j)$ will be the root of 优化子树 containing these keys
- left subtree of the root $k_r$ 会包含 keys ( $k_i,\dots ,k_{r-1}$) and dummy keys ( $d_{i-1},\dots ,d_{r-1}$ )
- right subtree of the root $k_r$ 会包含 keys ( $k_{i+1},\dots ,k_j$) and dummy keys ( $d_r,\dots ,d_j$ )
- If we examine all roots 𝑘𝑟,and determine all optimal binary search trees containing  $k_i,\dots ,k_{r-1}$ and those containing $k_{i+1},\dots ,k_j$, we will guarantee the finding of an OBST
##### Step2: A recursive solution
- We pick the subproblem domain as finding an OBST containing the keys $𝑘_𝑖,…,𝑘_𝑗$, where 𝑖≥1,𝑗≤𝑛, and 𝑗≥𝑖−1. (When 𝑗= 𝑖−1,there are no actual keys; we have just the dummy key $𝑑_{𝑖−1}$)
- 让 $e[i,j]$ the expected cost of searching an OBST containing the keys $𝑘_𝑖,…,𝑘_𝑗$. Ultimately, we wish to compute $𝑒[1,𝑛]$
- The easy case occurs when 𝑗=𝑖−1. Then we have just the dummy key $𝑑_{𝑖−1}$. The expected search cost is $𝑒[𝑖,𝑖−1]=𝑞_{𝑖−1}$.
- For a subtree with keys $𝑘_𝑖,…,𝑘_𝑗$ let us denote the sum of probabilities as: $$w(i,j) = (l = i \sim j) \sum p_l + (l = i-1 \sim j)\sum q_l$$
- Thus, if $𝑘_𝑟$ is the root of an optimal subtree containing keys $𝑘_𝑖,…,𝑘_𝑗$, we have: $$e[i,j] = p_r + (e[i,r-1] + W(i,r-1) + (e[r+1,j]+w(r+1,j))$$
- We rewrite $𝑒[𝑖,𝑗]$ as: $𝑒[ 𝑖, 𝑗] = 𝑒 [𝑖, 𝑟 − 1] +𝑒[ 𝑟 +1,𝑗] +𝑤(𝑖,𝑗)$
- 这个recursive equation是假设我们知道那个node被用作root
- 所以我们选择gives the lowest expected search cost的root，也因此得到final recursive formula: 
	$e[i,j]$ = 
		case 1: if $i\le j, i\le r\le j$
		$e[i,j] = min\{  e[i,r-1]+e[r+1,j]+w(i,j) \}$
		case 2: if j = i-1;
		$e[i,j]=q_{i-1}$
- To help us keep track of the structure of OBST, we define $r𝑜𝑜𝑡[𝑖,𝑗]$,for 1≤𝑖≤𝑗≤𝑛 to be the index 𝑟 for which $𝑘_𝑟$ is the root of an OBST containing keys $𝑘_𝑖,…,𝑘_j$
##### Step3: Computing the expected search cost of an OBST
- We store $𝑒[𝑖,𝑗]$ values in a table $𝑒[1. . 𝑛 + 1,0..𝑛]$.
	The first index needs to run to n+1 而不是n，因为要有只含dummy key $d_n$ 的subtree，我们需要计算和存储 $e[n+1,n]$
	The second index needs to start from 0 to have a subtree containing only the dummy key $𝑑_0$, we need to compute and store $𝑒[1,0]$
	我们只用entries $𝑒[𝑖, 𝑗]$ for which 𝑗 ≥ 𝑖 − 1
- We also use a table $𝑟[𝑖, 𝑗]$, for recording the root of the subtree containing keys $𝑘_𝑖, …,𝑘_𝑗$
	This table uses only the entries for which 1 ≤ 𝑖 ≤ 𝑗 ≤ 𝑛
- We will need one other table for efficiency. Rather than compute the value of 𝑤(𝑖,𝑗) from scratch every time we are computing $𝑒_{𝑖,𝑗} ,we store these values in a table $𝑤[1..𝑛+1,0..𝑛]$.
	For the base case, we compute for $1\le i \le n$: $$w[i,i-1]=q_{i-1}$$
	For $j \ge i$, we compute: $$w[i,j]=w[i,j-1]+p_j+q_j$$
##### Formulas
1. to calculate $e[i,j]$ $$e[i,j]=\begin{cases}
q_{i-1} &if \text{ }j=i-1 \\
min \{ e[i,r-1]+e[r+1,j]+w(i,j) \} \\
i\le r\le j \} & if \text{ }i\le j
\end{cases}$$
2. to calculate $w[i,j]$ $$w(i,j)=\sum\limits_{m=i}^{j}p_m + \sum\limits_{m=i-1}^{j}q_m$$
3. 把所有 `r ∈ [i, j]` 的代价（就是上面算e的时候那个公式）都算一遍，谁最小，就把 `r` 存进 `root[i][j]`
##### Complexity
- Running time $$\begin{align}
T(n)&=\sum\limits_{m=1}^{n}\sum\limits_{i=1}^{n-m+1}\sum\limits_{j=i}^{n-1+1}\Theta(1) \\
&=\sum\limits_{m=1}^{n}\sum\limits_{i=1}^{n-m+1}n=\sum\limits_{m=1}^{n}n^2\\
&\Theta(n^3)
\end{align}$$
  $T(n)=O(n^3)$
- The algorithm’s space efficiency is quadratic; $O(𝑛^2)$













































