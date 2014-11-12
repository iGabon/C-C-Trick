//测试static关键字
//在类定义体之内定义了static成员之后，必须在类的定义体之外再次进行定义，但是不需要再写上static关键字，例如第19行，当删除第19行时，程序出错
#include<iostream>

using namespace std;

class A
{
		public:
				static void print()
				{
						gender = 'M';
						cout<<gender<<endl;
				};
		private:
				static char gender;
};

char A::gender;

int main(void)
{
		A::print();
		return 0;
}
