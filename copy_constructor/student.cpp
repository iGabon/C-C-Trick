#include"student.h"
#include<iostream>
#include<vector>

using namespace std;

void print(vector<Student> stuVec)  //Student类对象可以作为容器的对象，此处与C++ Primer中的描述不符
{
		for(vector<Student>::iterator it = stuVec.begin();it<stuVec.end();++it)
		{
				cout<<it->name<<'\t'<<it->age<<'\t'<<it->gender<<'\t'<<it->score<<endl;
		}
}

void print(Student s)			//Student类对象也可以作为函数的形参，此处与C++ Primer中的描述不符
{
	cout<<s.name<<'\t'<<s.age<<'\t'<<s.gender<<'\t'<<s.score<<endl;
		
}

int main(void)
{
		vector<Student> students;
		Student s1("gabon",21,'M',86);
		Student s2 = Student(s1);//不管有没有显式的定义复制构造函数，该语句仍然能够正常运行，
									//并且Student类对象也可以作为函数的形参和容器的对象，此处与C++ Primer中的描述不符
		Student s3("igabon",21,'M',88);
		students.push_back(s1);
		students.push_back(s2);
		print(students);
		cout<<"--------------------"<<endl;
		print(s3);

		return 0;
}
