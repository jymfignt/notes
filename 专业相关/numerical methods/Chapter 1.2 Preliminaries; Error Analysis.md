# Binary Machine Numbers
## 64 bits (binary digit) representation 
- consisting of 0's and 1's as follows:

| sign  |          characteristic          |     mantissa      |
| :---: | :------------------------------: | :---------------: |
|       | (exponent=characteristic - 1023) | (fractional part) |
| 1 bit |             11 bits              |      52 bits      |
- sign: 0=positive and 1=negative
- characteristic range: 00000000000 to 11111111111
- 例：0 10000000011 101100100010000000(后半部分都是0，共52bits)
	S=0
	characteristic=C=$2^0+2^1+2^{10}$=1027
	mantissa=f=$2^{-1}+2^{-3}+2^{-4}+2^{-5}+2^{-8}+2^{-12}$=$\frac{2961}{4096}$
	number $= (-1)^S 2^{C-1023}(1+f)$
	=$(-1)^0 2^{1027-1023}(1+\frac{2961}{4096})$
	=$\frac{7057}{256}$
	=27.56640625
## over-flow and under-flow
- smallest normalized positive number: $$ 2^{-1023}(1+2^{-52})=10^{-308}$$这种情况就是当 S=0, C=0, f=$2^{-52}$, 二进制表示则是  1+11+51=63 bits 的0 和最后1位的1
- largest normalized positive number: $$ 2^{1024}(2-2^{-52})=10^{308}$$这种情况就是当 S=0, C=$2^{11}-1=2047$, f=$2^0-2^{-52}=1-2^{-52}$, 二进制表示则是  11+52=63 bits 的1 和第1位的0
- range of numbers in a computer: 5E-324 to 1.7E308
	P >1.7$\times$ 1.0E308 => overflow
	P< 5$\times$ 1.0E-324 => underflow 
## k-digit decimal representation
chopping or rounding(四舍五入)
# Errors and Significant Digits
- actual error: $p-\bar p$ 
- relative error: $\frac{|p-\bar p|}{|p|}$
- The number p is said to approximate p to t significant digits (or figures) if t is the largest nonnegative integer for which $$\frac{|p-\bar p|}{|p|}\le 5 \times 10^{-t}$$