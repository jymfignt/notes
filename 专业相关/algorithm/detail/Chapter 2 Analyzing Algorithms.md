[课件1](https://l.xmu.edu.my/pluginfile.php/1154515/mod_resource/content/1/Chapter%202%20%28i%29-%20Probabilistic%20Analysis.pdf)
[课件2](https://l.xmu.edu.my/pluginfile.php/1156210/mod_resource/content/1/Chapter%202%20%28ii%29-%20Amortized%20and%20Empirical%20Analysis.pdf)
### Lecture (1) Probabilistic Analysis
#### definition
- often used to evaluate an algorithm's running time
- 包括应用概率论分析问题
- 有些算法需要概率分析，而不是依赖确定性方法 deterministic methods 
- instead of只focus on best-case或worst-case，而是通过以下方式考虑所有情况：
	1. 评估assess每种情况的概率分布probability distribution
	2. 根据此分布计算预期expected运行时间
- 也能用于分析各种数量various quantities
>估算estimate招聘助理Hire-Assistant流程中的招聘成本hiring cost
#### hiring problem
- a few requirements to be fulfilled:
	1. 你总是希望拥有最好的候选人candidate
	2. whenever你面试一位候选人 & 觉得候选人比现任助理优秀，你必须解雇fire现任助理，然后聘用hire该候选人
	3. 你应该始终聘用面试的第一位候选人
- a few points to be considered for the Cost Model:
	1. 我们不关心concerned招聘助理的运行时间running time
	2. 我们必须决定雇用最好的候选人的总成本total cost
	> If n位候选人被面试，m位候选人被雇用，则成本为 $nc_i + mc_h$
	> 我们必须支付 $nc_i$ 的成本来面试候选人，无论录取了多少候选人
	> 因此，需重点分析招聘成本 $mc_h$  
	> m varies with 候选人的顺序order
- 为了说明illustrate概率分析，请考虑以下内容：
	1. 采访一名候选人成本 $c_i$
	2. 雇用一名候选人成本 $c_h$
	3. 假设assume $c_i << c_h$
	4. 总成本total cost: $O(c_i \times n + c_h \times m)$, where m = number of hirings
 ```Pseudocode:
 Hire-Assistant(n)
1 best = 0//fictional least qualified candidate
2 for i = 1 to n
3     interview candidate i//paying cost c_i
4     if candidate i is better than candidate best
5         best = i
6         hire candidate i //paying cost c_h
 ```
$$\begin{cases}
\text{best case} & \text{cost: }c_in + c_h \text{ and } O(c_in+c_h)=O(c_in) \\
\text{worst case} & O(c_in+c_hn) = O(c_hn) \text{ since }c_h > c_i\\
\text{average case} & \text{假设申请人按随机顺序出现，申请人的每个排列permutation都有同等的可能equally likely}
\end{cases}$$
#### Hiring Problem Probabilistic Analysis
- total number of permutations for n位候选人是 $n!$ 
- 每个排列都有相同的概率成为面试的顺序sequence
- 假设候选人根据其排名rank或者优先级priority以随机顺序出现
- 在现实中，候选人可能不会随机出现，which会导致分析出现问题issues
- 为了解决上条所说问题，我们可以用随机算法randomized algorithm来增强控制并确保顺序的随机性
##### randomized algorithm
- 在average-case analysis里，我们通常假设所有inputs是equally likely
- in reality，有些input可能性更高
- if unlucky，可能性最高的inputs是most costly，就像在quicksort算法里见到的那样
>我们可以force all inputs to be equally likely通过randomizing the input，确保一个更balanced分析
- 我们可能不知道或者无法模拟model概率分布
- 相反，我们可以在算法中用随机化randomization to 对输入施加impose a distribution
- an algorithm is randomized when其部分行为由随机数生成器random number generator决定
>在hiring problem里，这导致了一个变化：
	1. employment agency 提前提供了a list of n位候选人
	2. we get to 选择面试interview顺序，并且我们决定以随机顺序采访候选人
  这让我们能通过强制执行enforce random order来take control over 是否随机排序，从而使average case成为预期值expected value

>在hire-assistant problem里，we can：
>	 >1. 随机排列permute 候选人名单list first
>	 >2. then， run the hiring algorithm
>保证了对于任何input，the expected number of hires will be approximately $\ln{n} +O(1)$.
>
>问题就成了：我们怎么打乱shuffle the list使每一个排列有相同的可能性？
>	  >我们假设access to a good 随机数生成器
>	  >目标是确保每个possible permutation有相同的被选中的可能性
>当输入是随机的，the running time is referred to as the expected running time
#### Probabilistic Analysis with Indicator Random Variables (IRV)
- 在probabilities和expectation中转换
	Random variable (X): 一个根据概率分布可以去任何值的变量
	Expected value $(E[X])$: 如果我们反复采样sample观察observe的平均值
- Introduction
	这种技术使我们能够计算随机变量的预期值，即使there is 依赖关系dependence between variables
- IRVs are a useful tool in probabilistic analysis, 特别是当分析dependent events
- definition
	an IRV is a variable that indicates whether a specific event has occurred
	it takes a value of:
		->1 if the event happens, and
		->0 if the event doesn't happen
- expected value的应用
	for a given event A, the corresponding Indicator Random Variable $I_A$ is defind as:
		$I_A$ = 1 if event A occurs.
		$I_A$ = 0 if event A does not occur.
	The expected value of $I_A$ is the probability that event A occurs:
		E$[I_A]$ = P(A)
- practical use: IRV are particularly useful when 分析multiple events的问题 where:
	we define an IRV for each event
	by summing the IRVs, we 可以计算hires总数量的期望值

>Let's define $I_i$ as the Indicator Random Variable for hiring candidate i
>$I_i$ = 1 if candidate i is hired, and 0 otherwise
>期望值：
>$$E[\text{number of hires}] = E[\sum\limits_{i=1}^{n}I_i] = \sum\limits_{i=1}^{n}E[I_i]$$
>	由于$E[I_i] = P(\text{hiring candidate i})$, the expected value gives us the average number of hires across all candidates
>这个技术simplifies 概率分析 by 把问题分解成更小的独立或依赖events 并计算期待值 in a manageable way
##### Example: Applying Indicator Random Variables (IRVs) to the scenario of flipping a coin
1. Flipping a Coin Once
	Step 1: Define the Indicator Random Variable (IRV)
	define event X for the event "the coin lands heads" , the IRV will be defined as:$$X = \begin{cases}
	1, & \text{if heads occurs} \\
	0, & \text{if tails occurs} 
	\end{cases}$$
	Step 2: Compute the Expected Value
	$$E[X] = 1·P(heads) + 0·P(tails) = \frac{1}{2}$$
2. Flipping a Coin n times
	Step 1:  Define the Indicator Random Variables (IRVs)
	define event $X_i$ for each flip i (where i =1, 2, ..., n) to indicate whether heads occurs on the i-th flip:$$X_i = \begin{cases}
	1, & \text{if the i-th flip is heads} \\
	0, & \text{if the i-th flip is tails} 
	\end{cases}$$
	Step 2: Total Number of Heads
	$$X = X_1 + X_2 + ... + X_n$$
	Step 3: Compute the Expected Value
	$$\begin{align*}
	E[X] &= E[X_1 + X_2 + \dots +X_n] = E[X_1] + E[X_2] + \dots + E[X_n] \\
	&= \frac{1}{2} + \frac{1}{2} + \dots + \frac{1}{2} \\
	&= n·\frac{1}{2} \\
	&= \frac{n}{2} 
	\end{align*}$$
	Thus, the expected number of heads in n flips is  $\frac{n}{2}$  
3. Conclusion: the use of IRVs simplifies the calculation of expected values, as it breaks down the problem into smaller, manageable components where each event can be treated independently. This technique can be applied to a wider range of probabilistic analyses.
##### Example: Using IRVs in Quicksort to Analyze Expected Comparisons
- in quicksort, the key operation is comparing elements to a chosen pivot to partition the array into subarrays. The number of comparisons made directly affects the algorithm's performance.
- Setup:
	suppose we're sorting an array of n distinct elements using Quicksort
	we want to compute the expected number of comparisons made by the algorithm during the sorting process
- Step 1: Defining Indicator Random Variables
	define an IRV $I_{ij}$ for each pair of element i and j, where i < j:
		$I_{ij}$ = 1 if elements i and j are compared at some point during the execution of Quicksort
		$I_{ij}$ = 0 if element i and j are never compared
- Step 2: When Are Two Elements Compared?
	if and only if one of them is the first to be chosen as a pivot from the subarray containing both i and j. 一旦 pivot被选出来，the elements are placed in different subarrays, and no further comparisons are made between them.
	$$P(\text{i and j are compared}) = \frac{2}{j - i+1}$$
	Thus,
	$$E[I_{ij}] = \frac{2}{j-i+1}$$
- Step 3: Total Expected Number of Comparisons
	for all pairs of elements i and j:
	$$E[\text{total comparisons}] = \sum\limits_{1\le i\le j\le n}E[I_{ij}] = \sum\limits_{1\le i\le j\le n} \frac{2}{j-i+1}$$
	it turns out that this sum simplifies to:
	$$E[\text{total comparisons}] = 2n \ln{n} + O(n)$$
- Conclusion
	the expected number of comparisons in Quicksort is $2n \ln{n}$, which explains its average-case time complexity of $O(n\log{n})$ 
##### Sequential (Linear) Search Example
```
1: function SEQSEARCH(A[],n,K)
2:    for i = 1 to n do
3:      if A[i] = K then
4:        return i
5:      end if
6:    end for
7:    return -1
8: end function
```
- For this algorithm: 
$$\begin{cases}
\text{best case: A[1] = K, T(n)}\in O(1) \\
\text{worst case: K} \notin A, T(n)\in O(n) \\
\text{expected case:}\\
\text{ ->assume } K \in  A \text{ and that all positions have equal likehood of containing }K \\
\text{ ->assume } A\text{ has no duplicates } \\
\text{ ->all permutations of A are equally likely}
\end{cases}$$
- The expected run time is:
$$E[T(n)] = \sum\limits_{q=1}^{n}t (A[q] = k) \times p_r (A[q] = k)$$
	then,
	$$\begin{align}
	E(T(n)) &= \sum\limits_{q=1}^{n}qc \times \frac{1}{n} \\
	E(T(n)) &= \frac{c}{n}\sum\limits_{q=1}^{n}q \\
	 = \frac{c}{n} \times &\frac{n(n+1)}{2}  \\
	 = &\frac{c(n+1)}{2} \\
	 &\approx \frac{2}{n}  \\
	 \text{Expected case} &\text{ runtime is:} \\
	 E(T(n)) &\in O(n)
	\end{align}$$

#### Hiring Problem Revisited: Applying IRVs to the Hire-Assistant Problem
- 你想要决定how many times you'll hire a new assistant based on the qualifications of candidates （以随机顺序到达的）
##### Setup
- suppose you interview n candidates, one by one
- the algorithm works by hiring a candidate if they are more qualified than all previously interviewed candidates.
- we want to compute the expected number of hires
##### Step 1: Defining Indicator Random Variables
- define an IRV $I_i$ for each candidate i (where $1 \le i \le n$ ):
	$I_i = 1$ if candidate i is hired.
	$I_i = 0$ if candidate i is not hired.
##### Step 2: Expected Value of an Indicator Random Variable
- 由于候选人按随机顺序到达，候选人i 在前i位候选人中 most qualified 的概率是 $\frac{1}{i}$ 
- Thus,
$$E[I_i] = P(\text{candidate i is hired}) = \frac{1}{i}$$
##### Step 3: Total Expected Number of Hires
- for all candidates:
$$E[\text{total hires}] = E [\sum\limits_{i = 1}^{n}I_i] = \sum\limits_{i=1}^{n}E[I_i] = \sum\limits_{i=1}^{n} \frac{1}{i}$$
- the sum is known as the harmonic series, and it approximates to:
$$\begin{align*}
H_n &= 1 + \frac{1}{2} + \frac{1}{3} +\frac{1}{4} + \dots + \frac{1}{n} \\
&= \sum\limits_{k=1}^{n} \frac{1}{k} \\
&= \ln{n} + O(1)\\
\\
E[\text{total hires} ] \approx \ln{n} + O(1)
\end{align*}$$
##### Conclusion
- expected number of hires is approximately ln n
- for large n, 期望值增长缓慢
- IRVs 通过定义specific events发生与否来帮我们分解复杂的概率问题

### Lecture (2) Amortized Analysis and Empirical Analysis
#### Amortized Analysis
##### definitions
- a strategy for analyzing a sequence of operations to show the average cost per operation is small, even though a single operation within the sequence might be expensive
- calculates the average running time for each operation over the worst-case scenario
- not a method to design algorithms, but rather a more accurate way to analyze algorithms under specific conditions
- doesn't involve probabilities, unlike average-case performance
- $$\begin{cases}
\text{average-case analysis }& \text{considers all possible inputs} \\
\text{probabilistic analysis }& \text{involves all random choices} \\
\text{amortized analysis }&\text{looks at a sequence of operations}
\end{cases}$$
##### three methods
###### aggregate method
1. find the upper limit $T(n)$ for the total cost of n operations (worst case)
2. calculates the average cost as $T(n)$ / n
###### accounting method
1. calculate the cost of each operation, considering both its immediate time and its impact on future operations
2. assign each type of operation a different amortized cost
3. overcharge some operations and store the extra as a "credit"
4. this credit can be used later to compensate补偿 for expensive operations
###### potential method
1. similar to the accounting method but stores the credit as "potential energy"
2. overcharge early operations to cover the cost of future expensive operations
##### Amortized Analysis & Probabilistic analysis - Summary
###### probabilistic analysis
1. average case running time: average over all possible inputs for one algorithm (operation)
2. if using probability, called expected running time
###### amortized analysis
1. no involvement of probability
2. average performance on a sequence of operations, even some operation is expensive
3. guarantee average performance of each operation among the sequence in worst case
##### examples
###### Dynamic Tables
- to balance the size of a hash table for insertions, you need to balance two factors: space and time
	If the hash table is larger: searching for an item will be faster, but the table will require more memory (space)
	If ------------------smaller: save space but may take more time to find or insert an item
- the solution is to use a dynamic table, which grows in size when it becomes full
- steps when the Dynamic table is full:
	1. allocate memory for a table that is double the current table
	2. copy all the contents from the old table to the new one
	3. free the memory of the old table
	4. if space is available, simply insert the new item in the empty slot
- initially table is empty and size is 0

| operation                                    | hash table |       |        |     |     |     |     |     |
| -------------------------------------------- | ---------- | ----- | ------ | --- | --- | --- | --- | --- |
| insert item 1 (overflow)                     | 1          | \     | \      | \   | \   | \   | \   | \   |
| insert item 2 (overflow)                     | 1          | 2     | \      | \   | \   | \   | \   | \   |
| insert item 3                                | 1          | 2     | 3      | \   | \   | \   | \   | \   |
| insert item 4 (overflow)                     | 1          | 2     | 3      | 4   | \   | \   | \   | \   |
| insert item 5                                | 1          | 2     | 3      | 4   | 5   | \   | \   | \   |
| insert item 6                                | 1          | 2     | 3      | 4   | 5   | 6   | \   | \   |
| insert item 7                                | 1          | 2     | 3      | 4   | 5   | 6   | 7   | \   |
| next overflow would happen when we insert 9, | table size | would | become | 16  |     |     |     |     |
- simple analysis gives an upper bound, but not a tight upper bound for n insertions as all insertions do not take $\theta(n)$ time
- so, let's try solving it by **Aggregate Analysis**:
$$\frac{\text{Cost(n operations)}}{n} = \frac{\text{Cost(normal operations) + Cost(Expensive operations)}}{n}$$
- $$\begin{align}\text{Total Cost } = \sum_{i=1}^nc_i \\
\le n + \sum\limits_{j=0}^{[\log{n}]}2^j \\
= n + \frac{2^{[\log{n}]+1}-1}{2-1} \\
= n + 2\times 2^{[\log{n}]} -1 \le n+2n-1 &\le 3n-1 = \theta(n)
\end{align}$$
- Thus, the average cost of each dynamic table operation is $\theta(n)/n = \theta(1)$ 
- **2- accounting method**
	assign different charges to different operations
	the amount of the charge is called amortized cost
	amortized cost is more or less than the actual cost
	when amortized cost > actual cost, the difference is saved in specific objects as credits
	credits can be used by later operations whose amortized cost < actual cost 
	in **aggregate analysis**, all operations have same amortized costs
- A charge of 2 per insertion again is not enough, but a charge of 3appears to be best
- The bank balance must not go negative,$$\sum\limits_{i=1}^{n}c_i \le \sum\limits_{i=1}^{n}c_i'$$ for all n
- thus, the total amortized costs provide an upper bound on the total true costs
- **3-potential method**
- different from **accounting method** 
	the prepaid work not as credit, but as "potential energy", or "potential"
	the potential is linked to the entire data structure, not to individual elements within it
	the most powerful method(and the hardest to use)
$$\begin{align}
\text{(actual cost + potential change)}\\
c_i'=c_i + Φ_i - Φ_{i-1}
\end{align}$$
$$\begin{align}
&\text{Initial data structure } 𝐷_0,\\
 &n \text{ operations, resulting in }D_0,𝐷_1,\dots,D_n \text{ with costs } c_1,C_2,\dots,c_n. \\
 &Φ(D_i) \text{is called the potential of }D_i.\\
 &\text{amortized cost }c_i' \text{ of the ith operation is:}\\
&  ->c_i' = c_i + Φ(D_i)-Φ(D_{i-1})\text{ (actual cost + potential change)} \\  
\end{align}$$
- So, the total amortized cost of n operations is the actual cost plus the total increase in potential:$$\begin{align}
\sum\limits_{i=1}^{n}c_i'&=\sum\limits_{i=1}^{n}(c_i + \Phi(D_i) - \Phi(D_{i-1}) \\
&= \sum\limits_{i=1}^{n}c_i + \Phi(D_n) -\Phi(D_0)
\end{align}$$
- A potential function is valid if $\Phi_i - \Phi_n \ge 0$ for every 𝑖. If the potential function is valid, then the total actual cost of any sequence of operations is always less that the total amortized cost:$$\sum\limits_{i=1}^{n}c_i = \sum\limits_{i=1}^{n}c_i' - \Phi_n \le \sum\limits_{i=1}^{n}c_i'$$
- $\Phi = 2 \times$ no of items in the array - capacity of the array
#### The Empirical Analysis of an Algorithm
##### definitions
- in practice, we will often need to resort借助 to empirical rather than theoretical analysis to compare algorithms
##### Issues to consider
- many more factors that need to be controlled in some way
	test platform (hardware, language, compiler)
	measures of performance (what to compare)
	benchmark test set (what instances to test on)
	algorithmic parameters
	implementational details
- Practical considerations prevent complete testing.
##### Measures of Performance
- for the time being, we focus on sequential algorithms
- goal:
	compare two algorithms
	improve the implementation of a single algorithm
- possible measures:
	empirical running time (CPU time, wall-clock)
	representative operation counts
##### Measuring Time
- three relevant measures of time taken by a process:
	user time measures the amount of time (number of cycles taken by a process in "user mode")
	system time the time taken by the kernel execution on behalf of the process
	wall-clock time is the total "real" time taken to execute the process
- generally, user time is the most relevant, though it ignores some crucial operations (I/O, etc.)
- wall-clock times should be used cautiously/sparingly but many be necessary for assessment of parallel codes
##### Representative Operation Counts
- What operations should we count?
	profilers can count function calls and executions of individual lines of code to identify bottlenecks
	we may know a priori先验 what operations we want to measure (for example comparisons and swaps in sorting)
##### Test Set
- The instances must be chosen carefully in order to allow proper conclusions to be drawn
- we must pay close attention to their size, inherent difficulty, and other important structural properties
- this is especially important if we are trying to distinguish among multiple algorithms
- Example: set
##### Comparing Algorithms
- we can do the comparison using some sort of summary statistic:
	arithmetic mean
	geometric mean
	variance
##### Scientific Method
- Empirical analysis: analyze running time based on observations and expriments
- apply the scientific method:
	1. make observations and gather data：
		run the program multiple times, systematically increasing the inout size for each run
		time each program run and record the elapsed time along with the associated input size
	2. hypothesize an explanation for the observations
	3. make predictions based on the hypothesis
	4. formulate an experiment to see if the predictions occur
	5. analyze experimental results to confirm or falsify伪造 the hypothesis
**课堂问题答案？**

##### Empirical versus Theoretical Analysis
- for sequential algorithms, asymptotic analysis is often good enough for choosing between algorithms. It is less ideal with respect to the tuning调整 of implementation details
- for parallel algorithms, asymptotic analysis is far more problematic
	the details not captured by the model of computation can matter much more
	there is an additional dimension on which we must compare algorithms: for example, scalability