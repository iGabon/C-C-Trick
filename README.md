菜鸟的学习笔记：

static.cpp 主要是用来测试static关键字的作用：在类定义体之内定义了static成员之后，必须在类的定义体之外再次进行定义，但是不需要再写上static关键字
explicit.cpp 主要用来测试explicit关键字的作用：当类构造函数前面加了explicit关键字时，其他类型不能隐式转换为该类
operator.cpp 主要用来测试operator关键字，程序中主要进行了输出操作符的重载
construct.cpp 程序主要是用来测试构造函数的编写与使用
/copy_construct/*   主要是用来测试复制构造函数的编写与使用
/char shift/  其中的程序主要是字符串移位操作
           /left_shift.cpp 字符串左移操作
		   /nonneighborBlock_exchange.cpp ABC转换成CBA,方法原理与STL中的rotate方法类似           
		   /nonneighborBlock_exchange_improve.cpp ABC转换成CBA，方法为(A^B^C^)^=CBA,其中^为逆序符号           
