#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<set>
#include<map>
#include<fstream>

using namespace std;

void addTags(string& name,multimap<string,string>& nameTags,const multimap<char,int>& keyboard)
{
		string str;
		for(string::iterator it = name.begin();it != name.end();++it)
		{
			int i = keyboard.find(*it)->second;
			char buffer[10];
			snprintf(buffer, sizeof(buffer), "%d", i);
			str+=buffer;
		}
		nameTags.insert(make_pair(str,name));
}


int main(void)
{
		ifstream infile;
		infile.open("namebook");
		char name[20];
		multimap<char,int> num;
		num.insert(make_pair('a',2));
		num.insert(make_pair('b',2));
		num.insert(make_pair('c',2));
		num.insert(make_pair('d',3));
		num.insert(make_pair('e',3));
		num.insert(make_pair('f',3));
		num.insert(make_pair('g',4));
		num.insert(make_pair('h',4));
		num.insert(make_pair('i',4));
		num.insert(make_pair('j',5));
		num.insert(make_pair('k',5));
		num.insert(make_pair('l',5));
		num.insert(make_pair('m',6));
		num.insert(make_pair('n',6));
		num.insert(make_pair('o',6));
		num.insert(make_pair('p',7));
		num.insert(make_pair('q',7));
		num.insert(make_pair('r',7));
		num.insert(make_pair('s',7));
		num.insert(make_pair('t',8));
		num.insert(make_pair('u',8));
		num.insert(make_pair('v',8));
		num.insert(make_pair('w',9));
		num.insert(make_pair('x',9));
		num.insert(make_pair('y',9));
		num.insert(make_pair('z',9));

		multimap<string,string> nameTags;
		vector<string> names;
		while(infile.getline(name,20))
		{
				names.push_back(name);
		}
		for(vector<string>::iterator it = names.begin();it != names.end();++it){
			addTags(*it,nameTags,num);
		}
		
		string input;
		getline(cin,input);

		typedef map<string,string>::iterator name_num_it;

		pair<name_num_it,name_num_it> pos = nameTags.equal_range(input);
		while(pos.first != pos.second)
		{
				cout<<pos.first->second<<endl;
				++pos.first;
		}

		return 0;
}
