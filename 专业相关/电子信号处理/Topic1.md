# 1. Discrete-time signals 
- A signal is a function representing a physical quantity or variable
and typically it contains information about the behaviour or the
nature（性质） of a phenomenon.
- 数学角度看，信号可以表示为 x(t)
- 信号的两种类型：continuous-time / discrete-time signal 
	区别基于水平轴
- signal amplitude（幅度）， magnitude（模态，即绝对值）
- 两种表示离散时间信号的方式：
	1. 数学方程式：$$x(n)=\begin{cases}
	(\frac{1}{2})^n & n\ge0\\
	0 & n<0
	\end{cases}$$ or $$ \{ x(n) \}= \{1,\frac{1}{2},\frac{1}{4},\dots,(\frac{1}{2})^n,\dots \}$$
	2. 明确列出数列的值： $$\begin{align}
	\{x(n)\}= \{ \dots,0,0,1,2,2,&1,0,1,0,2,0,0,\dots \} \\
	&\uparrow
	\end{align}$$
## Basic Discrete-Time Signals
### Unit impulse sequence $\delta(n)$
$$\delta(n)=
\begin{cases}
1 & n=0 \\
0 & n\ne 0
\end{cases}$$
延伸， shifted unit impulse $\delta(n-k)$
$$\delta(n-k)=
\begin{cases}
1 & n=k \\
0 & n\ne k
\end{cases}$$
### Unit step sequence $u(n)$
$$u(n)=
\begin{cases}
1 & n\ge 0 \\
0 & n< 0
\end{cases}$$
延伸， shifted unit step $u(n-k)$
$$u(n-k)=
\begin{cases}
1 & n\ge k \\
0 & n< k
\end{cases}$$
### Complex exponential sequence
- The most general complex exponential sequence is defined as $$x(n)=C\alpha^n$$,Where 𝐶 and 𝛼 are in general complex number.
	Note that if 𝐶 = 1 and $𝛼^𝑛 = 𝑒^{𝑗Ω_0𝑛}$, we obtain the complex exponential sequence.
 - 应用欧拉定理，我们可以把 x(n)表示为 $$x(n)=e^{j\Omega_0n}+j\sin{\Omega_0n}$$
	 因此，x(n)是一个复数序列，其 real part is $\cos{\Omega_0}n$ and imaginary part is $\sin{\Omega_0n}$
-  Periodicity of $e^{j\Omega_0n}$
	序列$e^{j\Omega_0n}$ 不是对于任何 $\Omega_0$ 的值都是周期性的
	为了使其成为周期为N的周期函数，$\Omega_0$ 必须满足：$$\frac{\Omega_0}{2\pi}=\frac{m}{N}$$ 其中，m是正整数
	也就是说，如果序列是周期性的，且 $\Omega \ne 0$，基本周期则为 $$N_0=m(\frac{2\pi}{\Omega_0})$$
### Sinusoidal sequence
# 2. Discrete-time systems 
## impulse response
$$\begin{align}\delta(n)&=u(n)-u(n-1)\\u(n)&=\sum\limits_{i=0}^\infty\delta(n-i)\end{align}$$
## Causality
-  A system is said to be causal if the output does not depend on the future value of the input.
-  A system is causal if and only if the impulse response is $$h(n)=0 \text{ }\text{ }\text{ }\text{ for }n <0$$
- x(n): current input
- x(n-1): previous input
- x(n+2): future input
## Stability
 - A system is stable if and only if bounded input 𝑥(𝑛) leads to bounded output 𝑦(𝑛)
 - A system is BIBO stable if and only if its impulse response is absolutely summable (Definition: $$\sum\limits_{-\infty}^\infty|h(n)|<\infty$$
# 3. Linear Time-Invariant (LTI) Systems
## (System) Linearity
- Output of a linear system is proportional to its input.
## (System) Time-Invariance
- Time-invariance system: time shift in the input signal, leads to identical time-shift in output signal.
# 4. Convolution 
## Convolution Sum
input $x(n)=\sum\limits_{k=-\infty}^\infty x(k)\delta(n-k)$
output $y(n)=\sum\limits_{k=-\infty}^\infty x(k)h(n-k)$
     = x(n) * h(n)  
三种方式得卷积：
# 5. Difference Systems
- An LTI system can be described by a linear constant coefficient difference equation (LCCDE) of the form: $$\begin{align}&a_0y(n)+a_1y(n-1)+ \dots +a_Ny(n-N)\\&=b_0x(n)+b_1x(n-1)+\dots +b_Mx(n-M)\\&\sum\limits_{k=0}^Na_ky(n-k)=\sum\limits_{m=0}^Mb_mx(n-m), \forall n\end{align}$$
- or in the form of recursive equation $$y(n)=\frac{1}{a_0} \left\{ \sum\limits_{m=0}^Mb_mx(n-m)-\sum\limits_{k=1}^Na_ky(n-k)\right\}, \forall n$$
- Special case of the recursive equation when 𝑁 = 0 $$y(n)=\frac{1}{a_0} \left\{ \sum\limits_{m=0}^Mb_mx(n-m)\right\}, \forall n$$
- Impulse Response from the Recursive Equation $$h(n)=\frac{1}{a_0} \left\{ \sum\limits_{m=0}^Mb_m\delta(n-m)-\sum\limits_{k=1}^Na_kh(n-k)\right\}, \forall n$$
- Impulse response of a non-recursive system $$h(n)=\frac{1}{a_0} \left\{ \sum\limits_{m=0}^Mb_m\delta(n-m)\right\}= 
 \begin{cases}\frac{b_n}{a_0} &\text{for }0\le n\le M\\0 &\text{otherwise}\end{cases} $$
	 the non-recursive system is also called the finite impulse response (FIR) system.

- 区分FIR 和 IIR
