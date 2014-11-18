//重载操作符<<
#include<iostream>
#include<string>

using namespace std;

class A
{
		public:
				string name;
				int age;
				char gender;
};

ostream& operator<<(ostream& os,const A& a)
{
		os<<a.name<<'\t'<<a.age<<'\t'<<a.gender<<'\t';
		return os;
}

int main(void)
{
		A a;
		a.name = "gabon";
		a.age = 23;
		a.gender = 'M';
		operator<<(cout,a);
		cout<<a<<endl;

		return 0;
}
