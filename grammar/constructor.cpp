//测试多个构造函数的作用

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
			A(const string a,char gen):name(a),age(0),gender(gen){};
			A(){};
			void print();

};

void A::print()
{
		cout<<name<<endl;
		cout<<age<<endl;
		cout<<gender<<endl;
}


int main(void)
{
		A a("gabon",'c');
		A b;
		a.print();
		cout<<"-----------------"<<endl;
		b.print();
		return 0;
}
