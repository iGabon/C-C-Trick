//测试explicit关键字的作用

#include<iostream>
#include<string>

using namespace std;

class A
{
	private:
			string name;
			int age;
			char gender;
	public:
		    A(char gen):name("happy"),age(0),gender(gen){};
			explicit A(string na):name(na),age(0),gender('M'){};
			bool genderSame(A);
			bool nameSame(A);
};

bool A::genderSame(A a)
{
		if(a.gender == this->gender)
				return true;
		return false;
}

bool A::nameSame(A a)
{
		if(a.name == this->name)
				return true;
		return false;
}

int main(void)
{
		string haha("haha");
		char F('F');
		A test1("gabon");
		A test2('M');
//		cout<<test1.nameSame(haha)<<endl;// 错误，因为 explicit关键字使得“haha”不能隐式的转换为A类
		cout<<test2.genderSame(F)<<endl;//正确，test2所使用的构造函数前面并没有使用explicit关键字
		return 0;
}
