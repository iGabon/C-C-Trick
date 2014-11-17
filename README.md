菜鸟的学习笔记：

static.cpp 主要是用来测试static关键字的作用：在类定义体之内定义了static成员之后，必须在类的定义体之外再次进行定义，但是不需要再写上static关键字

explicit.cpp 主要用来测试explicit关键字的作用：当类构造函数前面加了explicit关键字时，其他类型不能隐式转换为该类

operator.cpp 主要用来测试operator关键字，程序中主要进行了输出操作符的重载

construct.cpp 程序主要是用来测试构造函数的编写与使用

rand.cpp 程序主要是解决编程珠玑第一章的练习题4,采用了三种方法生成1000000个介于0到10000000之间的有序的随机数

phonebook.cpp 程序主要是解决编程珠玑第二章练习题6电话簿查找问题

dateProcessing.cpp 程序主要是解决编程珠玑第三章练习题4,给定两个日期，算出相隔的天数，给定一个日期，给出该日是星期几

polymorphism.cpp 程序主要是测试C++的多态性：引用和指针的静态类型与动态类型可以不同

bitset.cpp 程序主要是解决编程珠玑第一章习题2：用位逻辑运算来实现位向量

/copy_construct/*   主要是用来测试复制构造函数的编写与使用

/char shift/  其中的程序主要是字符串移位操作

           /left_shift.cpp 字符串左移操作

		   /nonneighborBlock_exchange.cpp ABC转换成CBA,方法原理与STL中的rotate方法类似           

		   /nonneighborBlock_exchange_improve.cpp ABC转换成CBA，方法为(A^B^C^)^=CBA,其中^为逆序符号           

