## 3 components:
- containers: data structures that store objects of any type
- iterators: used to manipulate container elements
- algorithms: searching, sorting and many others
### two types of container classes in the STL: sequence and associative
 • A sequence container organizes data in a sequential fashion similar to an array
	 i. Vector
	 ii. Stack
	 iii. Deque
	 iv. Queue
• An associative container uses keys to rapidly access elements.
	 i. Set
	 ii. Multiset
	 iii. Map
	 iv. Multimap
	 <u>all</u> associative containers maintain keys in sorted order
	 <u>all</u> associative containers support bidirectional iterators
	 <u>set</u> does not allow duplicate keys
	 <u>multiset</u> and <u>multimap</u> allow duplicate keys 
	 <u>multimap</u> and <u>map</u> allow keys and values to be mapped
#### sequence containers(1) : vector
1. 区分 sequence <--> associative **未完待续**
2. The implementation of a vector is based on arrays
3. vector 用于储存相似数据类型的elements，但不同于array，vector的size可以动态（dynamically) 增长
4. 
`int myarray[60];`

 ```
 int *ptrarray, *narray;
 ptrarray = new[60];
 narray = new[100];
 memcpy(ptrarray,narray,sizeof(ptraaray));  //cope elements into narray
 delete ptrarray;
 ptrarray = narray;
```
malloc和calloc? 
free()
std::realloc() **未完待续**
5. header file: `#include <vector>`
提供了多种方法去执行不同操作：
	add, access, change, remove elements
	push_back(), pop_back(), begin(), end(), at(), erase()
有许多算法以函数模版（template）的形式实现：
	random_shuffle, sort, count, max_element, min_element 
6.    `<T>` 指定vector的种类，可以是任何原始（primitive）数据类型，int, char, float, etc.

#### sequence containers(2): stack 
1. Last-in-first-out 数据结构
2. implemented with vector, list, and deque (by default)	
> A stack of int using a vector: `stack <int, vector<int>>s1;`
> A stack of int using a list      : `stack <int, list<int>>s2;`
> A stack of int using a deque: `stack <int> s3;`
3. header file:  `#include <stack>`
#### sequence containers(3): deque
1. 代表stands for double-ended queue
2. provides indexed access using indexes
3. 
**2 3 4未完待续**看示例代码
#### associative containers(1): set
1. used for storing elements in a sorted way
2. `#include <set>`
3. 需要存储有序数据可以考虑，但注意不能有重复(*duplicate*)值
4. 一旦被储存就不能被修改
5.   
```
set<int> s1 ={12,12,26,65};
set<int,greater<int> > s2={12,12,26,65}
```
**示例代码8，未完待续**

#### associative containers(2): multiset
1. are implemented using a red-black binary search tree for fast storage and retrieval of keys
2. allow duplicate keys
3. 键的顺序由STL comparator function object less`<T>`决定
4. 键一定支持用`<`的比较

#### associative containers(3): map
1. store sorted key-value pair, in which each key is unique and it can be inserted or deleted but cannot be altered.
2. 与键相关联的值可以改变

**auto用法** 示例代码11
#### associative containers(4): multimap
1. Insertion is done using objects of the class pair (with a key and value)
2. 允许重复键，一个键可以被很多事匹配
3. 键的顺序由STL comparator function object less`<T>`决定
