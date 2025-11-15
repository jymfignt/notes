# 1. Context: The Root-Finding Problem
solution to an equation = root-finding problem = zero(s) of a function
# 2.Introducing the Bisection Method 
- 这个方法是基于 IVT 的 [[Chapter 1.1 Preliminaries; Calc Review]]
- Suppose a continuous function f, defined on $[a,b]$ is given with f(a) and f(b) of opposite sign. By the IVT, there exists a point $p \in (a,b)$ for which f(p)=0. In what follows, it will be assumed that the root in this interval is unique.
- 简而言之，逼近法。中点处函数值等于目标值，停止；否则取半当前区间，取区间中点函数值比较
# 3.Applying the Bisection Method
# 4.A Theoretical Result for the Bisection Method
## Rate of Convergence
$p_n=p+O(\frac{1}{2^n})$
## Conservative Error Bound
The theorem gives only a bound for approximation error and that this bound might be quite conservative