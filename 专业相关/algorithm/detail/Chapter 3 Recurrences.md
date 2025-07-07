[课件1](https://l.xmu.edu.my/pluginfile.php/1157153/mod_resource/content/1/Chapter%203%20%28i%29%20-%20Recurrences.pdf)
[课件2](https://l.xmu.edu.my/pluginfile.php/1157811/mod_resource/content/1/Chapter%203%28ii%29-Recurrences.pdf)
### General Introduction to Recurrences
- an equation that describes a function based on its value at smaller input
- Solving a recurrence means finding a function that works for all natural numbers and satisfies the recurrence
>the worst-case running time of MERGE-SORT is described by the recurrence:
>$$T(n) = \begin{cases}
\theta (1) &\text{if n = 1}\\
2T(\frac{n}{2}) + \theta(n) &\text{if n} \ge 1
\end{cases}$$
- three methods to solve: substitution, iteration, master
- when solving recurrences, we often ignore floors, ceilings, and boundary conditions
- recursive function is a function that calls itself until a “base condition” is true, and execution stops.
- Divide-and conquer” is Solutions to sub-problems are combined to solve the original problem.
- Mostly used to traverse or search data structures such as binary search trees, graphs, and heaps. It also works for sorting algorithms, like quicksort and heapsort.
- The goal of recursion analysis is to find an asymptotic bound, like θ or O, from the recurrence equation of a recursive algorithm.
#### Example 1: Factorial of an integer number
```
def factorial (n):
  if n==1
     return 1
  else：
     return(n*factorial(n-1))
  num=5
  print(factorial(num))
```
- push inside the stack

|      stack       |
| :--------------: |
|                  |
|                  |
|                  |
|        1         |
| 2 * Factorial(1) |
| 3 * Factorial(2) |
| 4 * Factorial(3) |
| 5 * Factorial(4) |

#### Example 2: Fibonacci of an integer number
```
def fibonacci(n):
  if(n <= 1):
    return n
  else:
    return(fibonacci(n-1)+fibonacci(n-2))

n = int(input("Enter number of terms:"))
print("Fibonacco sequence:")
for i in range(n):
  print(fibonacci(i))
```

### The complexity of recursive algorithms
- goal: obtain a formula without recurrence 
#### The complexity of Recursive Algorithms – The iteration Method
- basic idea: expand the recurrence and express it as a summation of terms dependent only on "n" and the initial condition
- Steps:
	first convert the recurrence into a summation
	Convert the recurrence into a summation and try to bound it using known series.
	Use back-substitution to express the recurrence in terms of n and the initial (boundary) condition.
##### Example 1:
```
def sum(int n)int{
   if n==1{
        return 1
        }
    return n + sum(n-1)
}
```
$$T(n) = \begin{cases}
1 & \text{if n = 1} \\
T(n-1) + 1 &\text{if n>1}
\end{cases}$$
$$\begin{align}
T(n) &= T(n-1) +1\\
&=T(n-2) +1 + 1\\
& \dots \\
& = T(1) + (n-1)
\end{align}$$
Therefore, the complexity of this algorithm is O(n)
##### Example 2:
```
Void Test(int n)
{
   if (n>0)
{
    print("%d",n);
    Test(n-1)
  }
}
```
同上，复杂度为O(n)
##### Example 3: T(n) = c + T(n/2)
$$\begin{align}
T(n) &= T(n/2) +c\\
&=T(n/4) +c + c\\
& \dots \\
& = T(1) + c\log{n}\\
&=O(logn)
\end{align}$$
##### Example 4: T(n) = n + 2T(n/2)
$$\begin{align}
T(n) &= 2T(n/2) +n\\
&=4T(n/4) +n + n\\
& \dots \\
& = 2^iT(n/2^i) + in  \\
&=kn + 2^k T(1) \text{ (where k = logn}\\
&=n\log{n}+nT(1)\\
&=O(n\log{n})
\end{align}$$
##### Example 5
$$T(n) = \begin{cases}
1 &if\text{ n=1} \\
2T(n-1) &if\text{ n>1} 
\end{cases}$$

$$\begin{align}
T(n)&=4T(n-2)\\
&=\dots\\
&=2^iT(n-i)\\
&=2^{n-1}T(1)\\
&=2^{n-1}\\
&=Q(2^n)

\end{align}$$
##### Exercise **未完待续**
#### The complexity of Recursive Algorithms – The substitution/induction Method
- The substitution method can be used to establish either upper or lower bounds on a recurrence.
- In the substitution method, instead of trying to find an exact closed-form solution, we only try to find a closed-form bound on the recurrence.
- Substitution method: guess the solution and then prove its correctness by induction.
- Steps:
	Guess the exact form of the solution
	Prove the correctness of the guess 
##### Making a Good Guess **未完待续**
- no general way to guess the correct solution to recurrences
- some heuristics启发式 can help us make a good guess (e.g., recursion tree)
- if a recurrence is like the one, we have seen before, then guessing a similar solution is reasonable
- another way to make a good guess is to prove the loose upper and lower bounds on the recurrence and then reduce the recurrence and then reduce the range of uncertainty
>start with and prove the initial lower bound of T(n) = $\Omega$(n) for recurrence
>start with and prove the initial upper bound of T(n) =  O($n^2$) for the recurrence
>then gradually lower the upper bound and raise the lower bound until convergence to the correct
- there are times when we can correctly guess at an asymptotic bound on the solution of a recurrence, but somehow the math doesn't seem to work out in the induction
- changing variables
- Usually, the problem is that the inductive assumption isn't strong enough to prove the detailed bound.
- Revising the guess by subtracting a lower-order term often permits the math to go through.

##### Example 6
$T(n) = 2T(\frac{n}{2}) + n$
1. Guess $T(n) \in O(n\log{n})$
2. Prove $T(n) \le cn \lg{n}$
	1. Assume $T(\frac{n}{2}) \le c\frac{n}{2}\lg{\frac{n}{2}}$
	2. Inductive step: $T(n) = 2T(\frac{n}{2}) +n$
$$\begin{align}
T(n) &\le 2(c\frac{n}{2}\lg{\frac{n}{2}}) +n\\
&=cn\lg{\frac{n}{2}} +n\\
&=cn(\log{n}-log{2})+n\\
&=cn\log{n}-(c-1)n\\
&\le cn\log{n} \text{ (for c }\ge 1)\\
T(n) \le cn&lg{n} \text{ can dedrive T(n)} \le cn\log{n}.\\
\text{Therefore,} &T(n) \in O(n]lg{n}) \text{is proved.}
\end{align}$$
##### Example 7
`T(n) = T(n-1) + n`
1. Guess $T(n) \in O(n^2)$
2. Prove $T(n) \le cn^2$
	1. Assume $T(n-1) \le c(n-1)^2$
	2. Inductive step: $T(n) = T(n-1) +n$
	$$\begin{align}
	T(n) &\le c(n-1)^2+n \\
	&=c[n^2-2n+1]+n\\
	&=cn^2 -2cn +n+c\\
	&=cn^2 + n(1-2c)+c\\
	&\le cn^2 \text{ (for c} \ge 1 )\\
	T(n) \le cn^2 &\text{ can dedrive T(n)}\le cn^2.\\
	\text{Therefore,}&T(n)\in O(n^2) \text{ is proved.}\\
	\end{align}$$
##### Example 8
$T(n) = 2T(\frac{n}{2}) + 1$
1. Guess $T(n) \in O(n)$
2. Prove $T(n) \le cn$
	1. Assume $T(\frac{n}{2}) \le c\frac{n}{2}$
	2. Inductive step: $T(n) = 2T(\frac{n}{2}) +1$
	$$\begin{align}
	T(n) &\le 2(c\frac{n}{2}) +1\\
	&=cn +1\\
	&\not= cn \\
	\text{which does not imply T(n)}&\le cn.\text{ We need to show the exact form.}
	\end{align}$$
To overcome this hurdle:
	 Revise our guess; say T(n)=O(n^2). However, our original guess was correct!
	 Sometimes it is easier to prove something stronger.
**Again**
$T(n) = 2T(\frac{n}{2}) + 1$
1. Guess $T(n) \in O(n)$
2. Prove $T(n) \le cn-b$
	1. Assume $T(\frac{n}{2}) \le c\frac{n}{2}-b$
	2. Inductive step: $T(n) = 2T(\frac{n}{2}) +1$
	$$\begin{align}
	T(n) &\le 2(c\frac{n}{2}-b) +1\\
	&=cn -2b+1\\
	&\le cn-b \\
	\text{We prove that T(n)}\le &\text{cn -b, with c=2, b=1 and }n_0 \text{, so T(n) = O(n)}
	\end{align}$$
##### Example 9
$T(n) =T(\lfloor n/2\rfloor)+T(\lceil n/2 \rceil) +1$
1. Guess $T(n) \in O(n)$
2. Prove $T(n) \le cn-b$
	Basis: When n = 1, T(1)=1$\le c-b$, for choosing any $c \ge 1+b$
	Inductive Step: Suppose $T(\lfloor n/2\rfloor)\le c\lfloor n/2\rfloor -b$ and $T(\lceil n/2\rceil) \le c\lceil n/2 \rceil -b$
	      $T( n) \le c\lfloor n/2\rfloor + c\lceil n/2 \rceil +1=cn+1$
	$T(n) \le cn+1$ can't imply $T(n)\le cn$. How can we do?
**again**
	1. Guess $T(n) \in O(n)$
	2. Prove $T(n) \le cn-b$
		Basis: When n = 1, T(1)=1$\le c-b$, for choosing any $c \ge 1+b$
		Inductive Step: Suppose $T(\lfloor n/2\rfloor)\le c\lfloor n/2\rfloor -b$ and $T(\lceil n/2\rceil) \le c\lceil n/2 \rceil -b$
		      $$\begin{align}
		      T(n) &\le c\lfloor n/2\rfloor -b + c\lceil n/2 \rceil -b +1\\
		      &=cn-2b+1\\
		      &\le cn-b \text{ (for }b \ge 1)
		      \end{align}$$
		$T(n) \le cn-b$ can derive $T(n)\le cn$. Therefore $T(n) \in O(n)$ is proved.
##### Example 10




