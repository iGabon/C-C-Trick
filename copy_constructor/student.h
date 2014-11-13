#include<string>

using namespace std;

class Student
{
		public:
				string name;
				int age;
				char gender;
				double score;
				Student(const Student&);
				Student(const string& name,const int& age,const char& gender,const double& score);
};

Student::Student(const Student& s)
{
    name = string(s.name);
   	age = s.age;
	gender = s.gender;
	score = s.score;
}

Student::Student(const string& name,const int& age,const char& gender,const double& score)		
{
					this->name = name;
					this->age = age;
					this->gender = gender;
					this->score = score;
}
