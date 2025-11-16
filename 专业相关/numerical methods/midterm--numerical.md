# 第一章
## 第一节
1. continuous和differentiable不是互相可推的，可微分一定连续，反之不然
2. Rolle's Theorem
	两端点函数值相同，则存在一点导数为0（函数连续闭区间且可微分开区间
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.7 Rolle's Theorem)]]
3. Mean Value Theorem
	存在一点导数为两端点距离的斜率（函数连续闭区间且可微分开区间
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.8 Mean Value Theorem)]]
4. Extreme Value Theorem
	极值点在两端点或导数为0的点，也就是critical points（函数连续闭区间且可微分开区间
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.9 Extreme Value Theorem)]]
5. Generalized Rolle's Theorem
	函数有n+1的根，则存在n阶导数为0（函数连续闭区间且可微分开区间
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.10 Generalized Rolle's Theorem)]]
6. Intermediate Value Theorem
	存在函数的值为两端点函数值中间（函数连续闭区间
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.11 Intermediate Value Theorem)]]
7. Weighted Mean Value Theorem for Integrals
	函数弯曲变矩形？
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.13 Weighted Mean Value Theorem for Integrals)]]
8. Taylor's Theorem
	Taylor polynomial + remainder term
	[[Chapter 1.1 Preliminaries; Calc Review#Theorem (1.14 Taylor's Theorem)]]
## 第二节
1. Error that is produced when a calculator or computer is used to perform real-number calculations is called round-off error
2. 64 bits (binary digit) representation: sign+characteristic+mantissa
	number = $(-1)^S \times 2^{C-1023} \times (1+f)$
	C 这边是从右往左，从 $2^0$ 到 $2^{11}$ 
	f 是从左往右，从 $2^{-1}$ 到 $2^{-52}$ 
	[[Chapter 1.2 Preliminaries; Error Analysis#64 bits (binary digit) representation]]
3. 溢出
	smallest / largest normalized positive number: $10^{-308}$ $10^{308}$ 什么情况下可得的
	电脑数字范围：5E-324 to 1.7E308
	[[Chapter 1.2 Preliminaries; Error Analysis#over-flow and under-flow]]
4.  k-digit decimal representation
	两种方式： chopping、rounding
	[[Chapter 1.2 Preliminaries; Error Analysis#k-digit decimal representation]]
5. Errors and Significant Digits
	actual error： 实际-approximation
	relative error： |actual|/|实际| 
	significant digits 判断 $$\frac{|p-\bar p|}{|p|}\le 5 \times 10^{-t}$$ 其中t是非负整数
	[[Chapter 1.2 Preliminaries; Error Analysis#Errors and Significant Digits]]
## 第三节
rate of convergence:
	$|\alpha-\alpha_n|\le K\beta_n \text{ for large n,}$ $\alpha_n=\alpha+O(\beta_n)$
	[[Ch 1-3 Algorithms and Convergence]]
## 练习作业
1. 练习1
	0 01111111111 0101001100000...000(43个0)1
	[IEEE 64 bits representation](https://www.geogebra.org/calculator/d28aeqwq)
2. 作业1
	f(x)=1+$ℯ^{-\cos{(x-1)}}$, $[1,2]$
	[find the max](https://www.geogebra.org/calculator/zupc87pg)

# 第二章
## Bisection Method
```octave
clc
clear 
close all 

% Define the function
f=@(x) x^3 +4*x^2 -10;

% Initial interval
a=1;
b=2;

% Tolerance
TOL=1.0E-4;
% Maximum number of iterations
NO=20;

% Convergence flag
OK=false;
% Function value at left endpoint
FA=f(a);

% Array to store approximations
P=zeros(NO,1);
% Iteration counter
i=1;

% Display header
fprintf("%10.6s \t %10.6s \t %10.6s \n",'a','b','p'); 

% Bisection method main loop
while (i<NO && !OK)
    % Calculate midpoint
    p=a+(b-a)/2;
    % Store current approximation
    P(i+1)=p;
    % Display current values
    fprintf("%10.6f \t %10.6f \t %10.6f \n",a,b,p); 
    % Evaluate function at midpoint
    FP=f(p);
    
    % Check convergence criteria
    if(FP==0 || (b-a)/2<TOL)
        fprintf("Procedure completed successfully.\n");
        fprintf("The answer is %8.6f for the first interval after running %d iterations! \n",p,i)
        OK=true;
    end
    
    % Increment iteration counter
    i=i+1;
    
    % Update interval
    if(FA*FP>0)
        % Root is in right subinterval
        a=p;
        FA=FP;
    else 
        % Root is in left subinterval
        b=p;
    end
end
```
## Fixed Point Iteration
![[Pasted image 20251116195742.png]]
## Newton‘s Method
```octave
clc
clear 
close all 

f=@(x) x-cos(x);
df=@(x) 1+sin(x);

a=0;
b=pi/2;
p0=(a+b)/2;
NO=20;
TOL=1.0E-5;
i=1;
while (i<=NO)
    p=p0-f(p0)/df(p0);
    fprintf("i=%d, p=%3.7f, f(p)=%.2e\n",i,p,f(p));
    if(abs(p-p0)<TOL)
        fprintf("Solution found after %d iterations:\n",i);
        fprintf("x= %3.7f\n",p);
        fprintf("f(x)= %3.7e\n",f(p));
        return
    end
    i=i+1;
    p0=p;
end
fprintf('Method failed after %2d iterations',NO)
```
## Secant & Regula Falsi Methods
```octave
clc
clear
close all

f = @(x) x^2 - 2* (e^x);

p0 = -1;      
p1 = 1;    
TOL = 1.0E-5;
N0 = 20;

% Step 1
i = 2;
q0 = f(p0);
q1 = f(p1);

fprintf("  i        pi             f(pi)\n");


% Step 2
while (i <= N0)

    % Step 3: Compute p_i
    p = p1 - q1 * (p1 - p0) / (q1 - q0);
    fp = f(p);

    fprintf("%3d   %12.7f    %12.4e\n", i, p, fp);

    % Step 4: check tolerance |p − p1|
    if (abs(p - p1) < TOL)
        fprintf("\nProcedure completed successfully after %d iterations.\n", i);
        fprintf("Approximate solution p = %3.7f\n", p);
        fprintf("f(p) = %3.7e\n", fp);
        return   % STOP
    end

    % Step 5: increase iteration number
    i = i + 1;

    % Step 6: Update p0, q0, p1, q1
    p0 = p1;
    q0 = q1;

    p1 = p;
    q1 = fp;

end

% Step 7: Failed
fprintf("\nThe method failed after %d iterations.\n", N0);
```
# 第三章
## Lagrange Interpolating Polynomial
[练习链接](https://www.geogebra.org/calculator/rr7vrd5k)
## Neville's Method
```octave
clc 
clear 
close all 


% input the data
x=2.1;
X=[2.0 2.2 2.3];
F=[0.6931 0.7885 0.8329];
% initialize Q
N=length(X);
n=N-1;
Q=zeros(N,N);

% Step 1
for i=1:N
    Q(i,1)=F(i);
    
end
fprintf('\nAfter computing column 1 \n');
disp(Q);
% Step 2
for i=1:n
    I=i+1;
    for j=1:i
        J=j+1;
        Q(I,J)=((x-X(I-J+1))*Q(I,J-1)-(x-X(I))*Q(I-1,J-1))/(X(I)-X(I-J+1));
     end
    fprintf('\nAfter computing column %d:\n', J);
    disp(Q);
end
fprintf("\n");

% display the Neville's Table
disp("Final result:");
for i = 1:N
    for j = 1:N
        fprintf('%12.4f ', Q(i,j));
    end
    fprintf('\n');
end
% final result
fprintf("\nThe final result is: %.4f\n", Q(N,N));
```