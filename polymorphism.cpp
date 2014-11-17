#include<iostream>
#include<string>

using namespace std;

class A
{
   	public:
					virtual void print(string str)
					{
									cout<<str<<endl;
									cout<<"A's print() called!"<<endl;
					}
					string name;
					void print2()
					{
									cout<<"A's non-virtual function called!"<<endl;
					}
};

class B: public A
{
				public:
							void print(string str)
							{
											cout<<str<<endl;
											cout<<"B's print() called!"<<endl;
							}
							string anotherName;

};

void printName(A& a)
{
				cout<<a.name<<endl;
}

int main(void)
{
		A a;
		a.name = "hello";
		B b;
		b.name = "world";
		b.anotherName = "gabon";
		A* ap = &b;
		
		a.print2();
		ap->print2();
		cout<<ap->name<<endl;   //发生重定向，ap虽然是A类的指针，但是可以将其指向B类的对象，但是仅仅能够使用B类中从A继承过来的成员
//		cout<<ap->anotherName<<endl;   //错误

		a.print(a.name);
		ap->print(b.name);

		printName(a);
		printName(b);   //可以将基类类型的引用绑定到·派生类对象的基类部分
		return 0;
}
