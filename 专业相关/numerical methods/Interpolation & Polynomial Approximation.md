# Lagrange Interpolating Polynomials I
## 1 Weierstrass Approximation Theorem
>**Algebraic Polynomials**
>One of the most useful and well-known classes of functions mapping the set of real numbers into itself is the algebraic polynomials, the set of functions of the form
>$$P_n(x)=a_nx^n+a_{n-1}x^{n-1}+\dots+a_1x+a_0$$
where n is a nonnegative integer and $a_0,\dots,a_n$ are real constants

- 这个之所以重要，主要是因为 uniformly approximate continuous functions，
也就意味着，对于任何定义在 closed and bounded interval 且连续的函数，都存在一个多项式可以按需 "close" to 给定的函数
- 这个结果也在 Weierstrass Approximation Theorem 里得到了精确的表达
>**Weierstrass Approximation Theorem**
>Suppose that f is defined and continuous on $[a,b]$. For each $\epsilon>0$, there exists a polynomial P(x), with the property that
>$$|f(x) - P(x)|< \epsilon, \text{ for all x in [a,b].}$$

- 另一个在 approximation of functions 中考虑 the class of polynomials 的重要原因是多项式的 the derivative and indefinite integral 很容易确定，且它们本身也是多项式
- 由于这些原因， polynomials 经常被用来逼近连续函数
## 2 Inaccuracy of Taylor Polynomials ?泰勒多项式具体表达 
#TOC
- 泰勒多项式被认为是 fundamental building blocks of numerical analysis 之一
- 可能因此，你会认为 polynomial interpolation（插值）会大量使用这些函数
- 但并非如此
- 泰勒多项式在特定点上与给定函数尽可能接近，但它们的精度集中在==该点附近==
- 一个好的插值多项​​式需要在==整个区间==上提供相对精确的近似值，而泰勒多项式通常做不到这一点。

>例题 $f(x)=e^x$
>we will calculate the first six Taylor polynomials about $x_0$ = 0 for $f(x)=e^x$

首先，函数的 derivatives (导数)均为 $e^x$, 也就是当 $x_0 = 0$ 时的值为 1
Taylor polynomials are as follows:
$$\begin{align}
P_0(x)&=1 \\
P_1(x)&=1+x \\
P_2(x)&=1+x+\frac{x^2}{2}\\
P_3(x)&=1+x+\frac{x^2}{2}+\frac{x^3}{6} \\
P_4(x)&=1+x+\frac{x^2}{2}+\frac{x^3}{6} +\frac{x^4}{24}\\
P_5(x)&=1+x+\frac{x^2}{2}+\frac{x^3}{6} +\frac{x^4}{24} +\frac{x^5}{120}\\
\end{align}$$
```functionplot
---
title: e^x 的泰勒展开
xLabel: x
yLabel: y
bounds: [-1.5, 4, -5, 25]
disableZoom: true
grid: true
---
P_0(x)=1
P_1(x)=1+x
P_2(x)=1+x+x^2/2
P_3(x)=1+x+x^2/2+x^3/6
P_4(x)=1+x+x^2/2+x^3/6+x^4/24
P_5(x)=1+x+x^2/2+x^3/6+x^4/24+x^5/120
e^x=exp(x)
```
注意，即使对于 higher-degree polynomials, 随着我们远离 0，误差也会越来越大


>A more extreme case
>Taylor Polynomials for f(x)=1/x about $x_0$ = 1

找一个极端一下的例子，对函数 $f(x)=\frac{1}{x}$​，在 x=1 处展开成泰勒多项式，然后用不同阶数的多项式去近似$f(3)=\frac{1}{3}$​。
since $$f(x)=x^{-1}, f'(x)=-x^{-2},f''(x)=(-1)^2 2x^{-3}$$
and, in general, $$f^{(k)}(x) = (-1)^k k!x^{-k-1}$$
the Taylor polynomials are $$P_n(x)=\sum\limits_{k=0}^n \frac{f^{(k)}(1)}{k!}(x-1)^k = \sum\limits_{k=0}^n (-1)^k (x-1)^k$$
然后可得到如下值

|    n     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
| :------: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| $P_n(3)$ |  1  | -1  |  3  | -5  | 11  | -21 | 43  | -85 |


## 3 Constructing the Lagrange Polynomial
$$L_{n,k}(x)=\frac{(x-x_0)\dots(x-x_{k-1})(x-x_{k+1})\dots(x-x_n)}{(x_k-x_0)\dots(x_k-x_{k-1})(x_k-x_{k+1})\dots(x_k-x_n)}=\prod\limits_{i=0 \text{ } i\ne k}^n \frac{(x-x_i)}{(x_k-x_i)}$$
$$P_n(x)=f(x_0)L_{n,0}(x)+\dots +f(x_n)L_{n,n}(x)=\sum\limits_{k=0}^n f(x_k)L_{n,k}(x)$$
## 4 Example: Second-Degree Lagrange Interpolating Polynomial


