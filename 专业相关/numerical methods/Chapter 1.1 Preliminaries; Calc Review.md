# Theorem (1.6)
If the function is differentiable at $x_0$, then f is continuous at $x_0$
但反之不可，即如果一个函数有连续性，不一定就可微分
# Theorem (1.7 Rolle's Theorem)
Suppose $f \in C[a,b]$ and f is differentiable on (a,b). If f(a)=f(b), then a number c in (a,b) exists with f'(c)=0.
- 至少存在一个c
- 注意区间一个闭区间，一个开区间
# Theorem (1.8 Mean Value Theorem)
If  $f \in C[a,b]$ and f is differentiable on (a,b),then a number c in (a,b) exists with $$f'(c)=\frac{f(b)-f(a)}{b-a}$$
- at least one c
- $c \ne a$, $c \ne b$
- 上面式子就是 slope of secant
# Theorem (1.9 Extreme Value Theorem)
If $f \in C[a,b]$, then $c_1$, $c_2 \in [a,b]$ exist with $f(c_1) \le f(x) \le f(c_2)$, for all $x \in [a,b]$. In addition, if f is differentiable on (a,b), then the numbers $c_1$ and $c_2$ occur either at the endpoints of $[a,b]$ or where f' is zero.
- endpoints 和导数为0的点就是 critical points
# Theorem (1.10 Generalized Rolle's Theorem)
Suppose $f \in C[a,b]$ is n times differentiable on (a,b). If f(x)=0 at the n+1 distinct numbers $a\le x_0 < x_1<\dots <x_n \le b$, then a number c in ($x_0$, $x_n$), and hence in (a,b), exists with $f^{(n)}(c)=0$.
-  n times differentiable, 说明 $f^{(n)}$ exists
# Theorem (1.11 Intermediate Value Theorem)
If $f \in C[a,b]$ and K is any number between f(a) and f(b), then there exists a number c in (a,b) for which f(c)=K
# Theorem (1.13 Weighted Mean Value Theorem for Integrals)
Suppose $f \in C[a,b]$, the Riemann integral of g exists on $[a,b]$, and g(x) does not change sign on $[a,b]$. Then there exists a number c in (a,b) with $$\int_a^b f(x)g(x) dx = f(c) \int_a^b g(x) dx$$
# Theorem (1.14 Taylor's Theorem)
Suppose $f \in C^n[a,b]$, that $f^{(n+1)}$ exists on $[a,b]$, and $x_0 \in [a,b]$. For every $x \in [a,b]$, there exists a number $\xi(x)$ between $x_0$ and x with $$f(x)=P_n(x)+R_n(x),$$
$$\begin{align}P_n(x)&=f(x_0)+f'(x-x_0)+\frac{f''(x_0)}{2!}(x-x_0)^2+\dots\\ &+ \frac{f^{(n)}(x_0)}{n!}(x-x_0)^n=\sum\limits_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x-x_0)^k\\R_n(x)&=\frac{f^{(n+1)}(\xi(x))}{(n+1)!}(x-x_0)^{n+1}
\end{align}$$
- $P_n(x)$ : Taylor Polynomial
- $R_n(x)$ : Remainder Term, 也就是 error term 应该要 < upper bound
