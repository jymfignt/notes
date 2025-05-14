>大一刚入门写的笔记，再看真的是恍如隔世了啊，存档一下

## 1.编程范式
- **C语言**：C 是一种过程化编程语言，所有的操作都围绕函数调用和顺序执行。程序由多个函数组成，每个函数负责执行特定任务，主要强调如何一步步地解决问题。C语言的编程更像是一步步的指令式操作。
- **C++ 语言**：C++ 是一种多范式编程语言，既支持过程化编程（像 C 那样写程序），也支持面向对象编程（OOP）。在面向对象编程中，程序是通过对象和类来设计的，数据和操作（方法）被封装在类中，可以通过继承和多态性来扩展功能。

>例子：

 - **C语言**

```
# include <stdio.h>
float calculateArea(float radius){
return 3.14*radius*radius;
}

int main(){
float radius=5.0;
printf("Area:%.2f\n",calculateArea(radius));
return 0;
}
```

   在 C 中，我们通过函数来组织代码，每个函数完成一个具体任务。这里 `calculateArea()` 函数负责计算圆的面积，`main()` 函数调用它来执行任务。

- **C++语言** (面向对象编程)：

```
#include <iostream>
using namespace std;

class Circle{
private:
float radius;
public:
Circle(float r):radius(r){}
void printArea(){
float area=3.14*radius*radius;
cout<<"Area: "<<area<<endl;
}
};

int main(){
Circle c(9.0);
c.printArea();
return 0;
}
```

在 C++ 中，通过定义类 `Circle`，我们将数据（圆的半径）和操作（计算面积）封装在一起，使用对象和成员函数来实现功能。相比 C 的过程化代码，C++ 的结构更易扩展。
## **2.内存管理**
- **C语言**：C 语言的内存管理主要依赖于手动分配和释放。程序员使用 malloc() 来动态分配内存，并必须在使用完内存后通过 free() 释放内存，否则可能导致内存泄漏。C语言没有自动的内存管理机制，程序员必须小心管理。
- **C++语言**：C++ 提供了更高效的内存管理方式。除了可以使用 new 和 delete 进行动态内存分配和释放外，C++ 通过 RAII（资源获取即初始化）机制让对象的生命周期与内存管理紧密相关。当对象不再使用时，其析构函数会自动调用，释放资源。

>例子：

 - **C语言**

 ```
 #include <stdio.h>
 #include <stdlib.h>
int main(){
int *ptr=(*int)malloc(sizeof(int));
*ptr=10;
printf("Value:%d\n",*ptr);
free(ptr);
return 0;
}
```

在 C 中，我们使用 malloc 来分配动态内存，但必须记住手动使用 free() 来释放，否则会导致内存泄漏。
- **C++语言**

```
#include <iostream>
using namespace std;

int main(){
int* ptr=new int(10);
cout<<"Value: "<<*ptr<<endl;
delete ptr;
return 0;
}
```

在 C++ 中，虽然也可以使用 `new` 和 `delete` 进行动态内存管理，但 C++ 支持更高级的 RAII 机制。例如，智能指针（如 `std::unique_ptr`）可以自动管理内存，无需显式调用 `delete`。

## **3.** **函数重载与默认参数**

- **C语言**：C 不支持函数重载，即每个函数的名字必须唯一，函数名冲突是常见问题。此外，C 也不支持默认参数，所有函数参数必须显式传递。
- **C++语言**：C++ 支持函数重载，即可以定义多个同名函数，只要它们的参数列表不同。这样可以使代码更具可读性和扩展性。此外，C++ 还支持默认参数，简化了函数调用。
>例子：

 - **C语言**
 
 ```
 #include <stdio.h>
void printNumberInt(int n){
printf("Integer: %d\n",n);
}
void printNumberFloat(float n){
printf("Float: %.2f\n",n);
}

int main(){
printNumberInt(5);
printNumberFloat(3.14);
return 0;
}
```

在 C 中，由于不支持函数重载，我们必须为每种参数类型定义不同的函数，如 `printNumberInt` 和 `printNumberFloat`。
- **C++语言**

```
#include <iostream>
using namespace std;
void printNumber(int n){
cout<<"Integer: "<<n<<endl;
}
void printNumber(float n){
cout<<"Float: "<<n<<endl;
}
void greet(string name="Guest"){
cout<<"Hello, "<<name<<endl;
}
int main(){
printNumber(5);
printNumber(3.14);
greet(); //使用默认参数
greet("Alice");
return 0;
}
```

在 C++ 中，我们可以重载 `printNumber()` 函数来处理不同类型的参数。此外，`greet()` 函数使用了默认参数，如果没有传递名字，它会使用 "Guest"。

## **4.命名空间**
- **C语言**：C 语言没有命名空间（namespace）的概念，所有全局变量和函数都共享一个全局命名空间。因此，可能会发生函数名或变量名冲突。
- **C++语言**：C++ 引入了命名空间，可以将函数、类和变量封装在命名空间中，避免命名冲突。这在大型项目中尤为有用。

>例子：

 - **C语言**

```
#include <stdio.h>
int value=10;//全局变量
void printValue(){
print("Value: %d\n",value);
}

int main(){
printValue(); //调用全局函数
return 0;
}
```

在 C 中，所有的全局变量和函数都在一个命名空间内，如果其他文件中定义了同名变量或函数，就会导致冲突。
 - **C++语言**

 ```
 #include <iostream>
 using namespace std;
namespace MyNamespace{
int value = 10;
void printValue(){
cout<<"Value: "<<value<<endl;
}
}
int main(){
MyNamespace::printValue(); //使用命名空间
return 0;
}
```

在 C++ 中，命名空间 `MyNamespace` 保护了 `value` 和 `printValue()`，即使其他文件中有同名变量或函数，也不会冲突。

## **5.标准库和STL**
- **C语言**：C语言的标准库主要包括基本的输入输出函数（如 printf()）、字符串处理函数和数学函数（如 sqrt()）。没有现成的数据结构和算法库，程序员需要自己实现诸如链表、栈等基本数据结构。
- **C++语言**：C++ 提供了强大的标准模板库（STL），包括容器（如 vector、map 等）和算法（如 sort()）。STL 大大简化了编程工作，尤其是在数据结构和算法方面。

>例子：

- C语言：

```
#include <stdio.h>

int main(){
int arr[]={1,2,3,4,5};
for(int i=0;i<5;i++){
printf("%d ",arr[i]);
}
printf("\n");
return 0;
}
```

在 C 语言中，如果你需要更多复杂的数据结构（如动态数组或链表），必须手动实现这些结构。上例中只是一个简单的静态数组。
- C++语言（使用vector容器）：

```
#include <iostream>
#include <vector>
using namespace std;

int main(){
vector<int> vec={1,2,3,4,5};
for(int val:vec){
cout<<val<<" ";
}
cout<<endl;
return 0;
}
```

在 C++ 中，`vector` 是一个动态数组，可以自动管理内存。它不仅提供了类似数组的访问方式，还支持自动扩展、插入、删除等操作，无需手动管理内存。
##  **6.类和结构体的区别**

- **C语言**：C 语言中的结构体（struct）只能包含数据成员，不能包含函数。它们用于将不同类型的数据组合在一起，作为一种简单的数据聚合方式。
- **C++语言**：C++ 中的类（class）是结构体的扩展，不仅可以包含数据成员，还可以包含函数（称为成员函数）。类可以实现数据的封装和隐藏，并且支持面向对象的特性（如继承和多态）。

>例子：

- C语言（结构体）：

```
#include <stdio.h>

struct Rectangle{
int width;
int height;
};

int main(){
struct Rectangle rect;
rect.width=10;
rect.height=20;
printf("Area: %d\n",rect.width*rect.height);
return 0;
}
```

在 C 中，`struct Rectangle` 只能包含宽度和高度这两个数据成员，无法添加与矩形相关的函数操作。
- C++语言（类）：

```
#include <iostream>
using namespace std;

class Rectangle{
private:
int width;
int height;
public:
Rectangle(int w,int h):width(w),height(h){}
int gerArea(){
return width*height;
}
};

int main(){
Rectangle rect(10,20);
cout<<"Area: "<<rect.getArea()<<endl;
return 0;
}
```

在 C++ 中，类 `Rectangle` 不仅可以包含数据成员，还可以包含成员函数 `getArea()` 来计算矩形的面积，展示了数据和操作的封装。

## **7.异常处理**
- **C语言**：C 语言没有内置的异常处理机制。通常通过返回错误码或设置全局变量 errno 来处理错误，程序员必须手动检查这些错误。
- **C++语言**：C++ 支持异常处理机制，可以使用 try、catch 和 throw 语句来捕获和处理异常。这使得代码更加简洁，并且可以更灵活地处理错误。

>例子：

- - **C语言** (无异常处理)：

```
#include <stdio.h>
#include <stdlib.h>

int divide(int a,int b){
if(b==0){
return -1; //返回错误码
}
return a/b;
}

int main(){
int result=divide(10,0);
if(result==-1){
printf("Error: Division by zero\n");
}else{
printf("Result: %d\n",result);
}
return 0;
}
```

在 C 语言中，我们通常通过返回错误码（例如 -1）来表示错误，调用函数时需要手动检查这些错误。
  - **C++语言** (异常处理)：

```
#include <iostream>
using namespace std;

int divide(int a,int b){
if(b==0){
throw "Divison by zero";
}
return a/b;
}

int main(){
try{
cout<<"Result: "<<divide(10,0)<<endl;
}catch(const char*e){
cout<<"Error: "<<e<<endl;
}
return 0;
}
```

在 C++ 中，我们可以使用 `throw` 来抛出异常，并在 `catch` 中捕获并处理异常，避免手动检查每个函数的返回值。
## **8.模板和范式编程**
- **C语言**：C 语言不支持泛型编程。如果你想要编写处理不同数据类型的函数或数据结构，你需要为每种类型编写不同版本的代码，这可能会导致大量的重复代码。
- **C++语言**：C++ 引入了模板（template），允许编写能够处理任意数据类型的泛型代码。模板大大提高了代码的重用性和灵活性。

>例子：

- - **C语言** (无泛型)：

```
#include <stdio.h>

void printIntArray(int arr[n],int size){
for(int i=0;i<size;i++){printf("%d ",arr[i]);}
printf("\n")
}
void printFloatArray(float arr[n],int size){
for(int i=0;i<size;i++){printf("%.2f ",arr[i]);}
printf("\n")
}

int main(){
int intArr[]={1,2,3};
float floatArr[]={1.1,2.2,3.3};
printIntArray(intArr,3);
printFloatArray(floatArr,3);
return 0;
}
```

在 C 中，我们需要为每种数据类型编写不同的函数版本，如处理整数数组和处理浮点数数组的函数。
-  **C++语言** (模板)：

```
#include <iostream>
using namespace std;

//定义模版函数
template <typename T>
void printArray(T arr[],int size){
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";"
}
cout<<endl;
}

int main(){
int intArr[]={1,2,3};
float floatArr[]={1.1,2.2,3.3};
printArray(intArr,3);
printArray(floatArr,3);
return 0;
}
```

在 C++ 中，使用模板可以编写一个通用的 `printArray()` 函数，可以处理不同类型的数组，而不需要为每种类型单独编写函数。
