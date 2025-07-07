[课件1](https://l.xmu.edu.my/pluginfile.php/1144959/mod_resource/content/1/Chapter%201%20%28i%29-Introduction%20to%20Algorithms.pdf)
[课件2](https://l.xmu.edu.my/pluginfile.php/1153353/mod_resource/content/1/Chapter%201%20%28ii%29-%20Introduction%20to%20Algorithms.pdf)

### Part 1
#### Algorithm Properties
- finiteness   有限行
- clarity   易懂清楚
- sequence    Steps must have defined order, with clear start and stop points
- inputs/outputs
- feasibility   可执行
- correctness  准确解决问题
- well-ordered and effectively computable operations  
#### Simple Example
- must be unambiguous
- definite and effective instruction
- proper termination
#### Definition 
- An algorithm is a sequence of definite and effective steps that terminates with correct output from given input.
#### Algorithms VS. Programs
- a program doesn't need to meet the finiteness condition (runs in a loop until new jobs arrive)
- since our programs always terminate,两者皆可
- design phase creates an algorithm, implementation phase creates an program
- a program is the concrete expression of an algorithm in a specific programming language
#### Algorithms Classification
- Recursive algorithms 
- Greedy algorithms
- Backtracking algorithms 
- Branch and bound algorithms
- Divide and conquer algorithms 
- Brute force algorithms
- Dynamic programming algorithms
- Randomized algorithms
#### Algorithm Analysis
- estimates the time an algorithm takes based on the size of the input (N)
- helps in choosing different algorithms
- not provide exact time measurement  这取决于电脑种类, user load, processor speed, compiler optimization
- focuses on the algorithm itself, 而不是硬件
- exact operation counts are impractical, 特别是当N越来越大
   - the difference between algorithms with N+5 and N+250 operations becomes negligible
- analysis rules:
     - assume a basic time unit
     - takes 1 time unit: assignment, single I/O, Boolean operations, numeric comparisons, arithmetic operations, function return, array indexing, and pointer dereferencing
     - the time to evaluate the condition + the maximum time of individual clauses: selection statements (比如switch)
     - (assuming) maximum number of iterations: loops
     - 1 time unit of setup + time for parameter calculations and function execution: function calls
- another approach:
   - estimate the resources an algorithm needs, which depends on specific computational models
   - several commonly used models:
     -Random Access Machine 随机访问机(RAM): Measures time and space, typical for traditional serial computers.
     -Parallel Random Access Machine 平行随机访问机(PRAM): Considers parallel time, number of processors, and read/write constraints
     -Message Passing Model消息传递模型: Evaluates communication costs (number of messages) and computational costs
     -Turing Machine图灵机: Focuses on time and space, representing an abstract theoretical model

### Part 2
#### How to write an Algorithm
- prerequisites:
    - problem
    - constraints
    - input
    - output
    - solution
- steps:
    1. Define the problem
    2. List the inputs and the outputs
    3. Describe the steps needed to convert or manipulate the inputs to produce the outputs
    4. Test the algorithm
#### Algorithm Phase
- Design Phase
    - identify the problem and fully understand it
    - Consultation with people interested in similar problems
- Analysis Phase
    - theoretical study of computer program performance and resource usage
    - many solution algorithms can be derived for a given problem
    - analyze those proposed solution algorithms and implement the best suitable solution
- ![[Pasted image 20250407092546.png]]
- 
- Implement Phase
    - writing and coding the algorithm
    - use the programming language you are familiar with
    - choose the best programmer to write the code 如果在一个团队内
    - understand and write each line in your code carefully 为了完成一个高效算法
- Experiment Phase
    - test your algorithm with different cases and variables
    - Detect if the algorithm results match the desired and expected output. 
    - If there is any fault after testing the algorithm, you may amend修正 the previous phases.
- The design and analysis of algorithms is a circular process
- The quality of good algorithm can be measured by:
    - Time
    - Memory
    - Accuracy
    - Sequence
    - Generality
#### Operations in Algorithms
- Sequential operations
	- a single well-defined task
- Conditional operations
	- "question-asking" instructions
- Iterative operations
	- "loops" instructions
#### Representing Algorithms
- In terms of Natural Language.  
	- advantage: familiar
	- disadvantages:
		1. verbose冗长
		2. imprecise -> ambiguity
		3. rarely used (for complex or technical algorithms)
- In terms of Formal Programming Language. 
	- advantages:
		1. precise -> unambiguous
		2. will ultimately program in these languages
	- disadvantages:
		1. It has syntactic details which are not important in the algorithm design phase.
		2. Not familiar to the person who is not interested in this programming language.
- In terms of Pseudocode. 
	- advantages:
		1. a middle-ground compromise 中间立场的妥协
		2. resembles many popular programming languages
		3. relatively free of grammatical rules. 
		4. Only well-defined statements are included “A programming language without details” 没有细节的编程语言
	- Disadvantage: Compared with flowchart it is difficult to understand the program logic
	- pseudocode:  **未完待续**
		- No standard pseudo code syntax exists.
		- The steps are numbered.
		- not an executable program.
		- Flowcharts can be thought of a graphical alternative to pseudocode.
	- pseudocode language constructs:
		- computation / assignment
			1. compute
			2. assign
			3. increment / decrement
		- input / output:
			1. get
			2. display
		- selection: **详见课件**
			1. single selection 
				IF condition THEN
				1.1 statement 1
				1.2 etc.
			2. double selection 
				IF condition THEN
				1.1 statement 1
				1.2 etc. 
		- repetition: **详见课件**
	- pseudocode example: *对比课件另一种方法*
	 1. Get dividend
	 2. While True
		 1. Get divisor
		 2. IF divisor != 0
			 1. break
		3. Display "Enter a valid number"
	3. Compute quotient = dividend / divisor
	4. Display dividend, divisor, quotient
	- pseudocode exercises: **未完待续**
		- 1. Get num1, num2 第一题
		  2.Compute sum=num1+num2
		  3.Display sum
		- 1. Get sum 第二题
		 2.IF num>=0 THEN
			2.1Display "positive"
		 3.ELSE
			3.1Display "negative"
		- 1. Get n 第六题
		  2.For i in n:
			2.1Get number
			2.2Add number to sum
		 3.Compute avg = sum / n
		 4.Display sum, avg
- Flowcharts
	- Advantages:
		1. Makes logic clear. 
		2. Effective analysis 
		3. Easy to code and test. 
	- Disadvantages:
		1. difficult to use for large programs
		2. Difficult to modify.
	- Flowchart Exercises: **详见课件**
		1. Get A, B, C
		2. IF A>B
			1. IF A>C
			2. Display A
		3. IF B>C
			1. Display B
		4. Else
			1. Display C
### Part 3
#### Efficiency of Algorithms
- An algorithm is considered efficient if its resources consumption is below some acceptable level.
- Measures:
	- Time: Duration to complete.
	- Space: Working memory required:
		- Memory for code.
		- Memory for data.
- Optimization: Both time and space must be optimized for efficiency
- Influencing Factors:
	- Machine clock rate
	- Compiler code quality.
	- Multi-programming status.
- Input Parameters: Execution time is a function of input values.
- Predictability: Knowing this function allows time prediction without execution.
- Time Efficiency: Speed of algorithm execution (time complexity).
- Space Efficiency: Amount of extra memory used (space complexity).
- Time efficiency remains a significant focus. Extra space required by algorithms is less of a concern now.
- Focus of Analysis: Primarily on time efficiency, but the framework can also analyze space efficiency.
#### Units for Measuring Running Time
- Seconds or milliseconds can measure algorithm running time.
- Drawbacks:
	- Dependent on computer speed.
	- Influenced by program quality.
	- Affected by compiler performance.
- Ideal Metric: A metric for efficiency that is independent of these factors is desired.
- Basic Operation: Identify the most important operation that dominates running time.
#### Space Efficiency
- For large quantities of data space/memory should be analyzed.
- Major Space Components:
	- Instruction space
	- Data space
	- Run-time stack space.
- Factors Affecting Running Time:
	- Compiler used.
	- Memory and disk read/write speed.
	- Machine architecture (32-bit vs. 64-bit).
	- Input size (critical for analyzing time complexity).
#### Time Complexity Analysis Approaches
1. Estimation of Running Time:
	- Operation Counts
	- Step Counts
2. Asymptotic Categorization 渐进分类
#### Order of Growth 
- Efficiency measures should be technology-independent to remain relevant across technological advances.
- The primary focus is on the algorithm's performance with large input sizes, not small ones
- For large input sizes, the focus is on the rate of growth or order of growth of the running time.
- If the running time of an algorithm is at most $cn^2$  for some constant c > 0 , the constant becomes insignificant as n increases.
- 随着n逐渐增大，幂数小的项不重要，比较两算法的系数也不重要
- $\log{n}$ < n < $n \log{n}$  < $n^2$ < $n^3$ ，当n足够大
- $$\begin{cases} 
\text{logaithmic} & \log^k{n}\\
\text{sublinear} & n^c\text{ or }n^c\log^c{n},0<c<1 \\
\text{linear} & cn\\
\text{sub-quadratic(functions between linear and quadratic)}  & n\log{n} \text{ and }  n^{1.5}\\
\text{quadratic} & cn^2\\
\text{cubic} & cn^3
 \end{cases}$$
#### Asymptotic Notation *不考?* 
- In asymptotic analysis, we evaluate an algorithm's performance based on input size, focusing on how time or space requirements increase.
- 考虑三种情况：
	1. Worst case: Provides an upper bound on performance and is usually the primary focus
	2. Average case: Often more complex to determine and can align一致 with the worst case.
	3. Best case: 很少被考虑 Rarely considered
- 算法复杂度最常见的渐进符号：
	1. Big-O (O) Notation: Represents the upper bound of an algorithm's running time, indicating worst-case complexity. 上限
	2. Big-Ω (Omega) Notation: Represents the lower bound of running time, indicating best case complexity. 下限
	3. Big-Θ (Theta) Notation: Encloses the function from above and below, representing both upper and lower bounds, and is used for analyzing average-case complexity.  分析平均复杂度
##### The O-notation
- Generally, the running time of an algorithm is 𝑂(𝑔(𝑛))
> Given f(𝑛) and g(𝑛) - functions defined for positive integers
   $$\text{Then } f(n) = O(g(n))$$ 
   If there exists a $c (c\ge1)$ such that:
$$f(n)\le c(g(n)), \text{ for all sufficiently large positive integers } n (n\ge n_0)$$
- Big O notation 定义了一个算法的上限，仅从上方限制函数
- *f* grows no faster than some constant times *g*
- 可用作简化simplification工具
>For instance, instead of writing
> $$f(n) = 5n^3 +7n^2 -2n +13$$
>we may write
>$$f(n) = 5n^3 + O(n^2)$$
- finding Big-O runtime的步骤
	1. figure out input是什么和n代表什么
	2. 用n表示maximum number of operations
	3. 消除eliminate所有项除了最高阶项
	4. 移除所有常数因子factors
>$$f(n) = 4n^2 +n+12$$
>**Solution:**
>Big O for this function is: $O(n^2)$
>To prove this, we assume that:
>$$C = 5, \text{则 } 5n^2 \ge 4n^2 +n +12$$
>解得: $n \le -3 \text{ or } n \ge 4$
>when $n_0$ = 4, both equation are equal 
>when $n_0$ >4, $5n^2 > 4n^2 +n+12$ 
##### Big-Ω (Omega)Notation
- $Ω(g(n))$ = { $f(n)$: there exist positive constants c and  $n_0$  such that:
  $$0 \le c \times g(n) \le f(n)$$
       $\text{for all n }\ge n_0$ }.
- Omega notation最不常用，因为best-case最用不到
##### The Θ-notation (Theta)
- 不像其他notation，Θ-notation提供了一个算法的running time growth的建准表达
- 有些算法，像insertion sort，不能用Θ-notation表示，因为它们的多变的运行时间 （linear to quadratic）
- 像selection sort就可以用Θ-notation准确描述
- 𝑂is similar to ≤, Ω is similar to ≥, and Θ is similar to =
- $Ω(g(n))$ = { $f(n)$: there exist positive constants $c_1$, $c_2$ and  $n_0$  such that:
  $$0 \le c_1 \times g(n) \le f(n) \le c_2 \times g(n)$$
     for all n $\ge n_0$  }.
