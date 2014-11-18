#include<iostream>
#include<regex>
#include<string>
#include<map>

using namespace std;

string find(const string& word,const map<string,string>& rule)
{
				string model;
				for(map<string,string>::const_iterator it = rule.begin();it != rule.end();++it)
				{
						regex re(it->second);
						if(regex_search(word,re))
						{
										model = it->first;
										return model;
						}
				}
				return NULL;
}

int main(void)
{
				map<string,string> rule;
				rule.insert(make_pair("et-ic","^et[a-z]*ic$"));
				rule.insert(make_pair("al-is-tic","^al[a-z]*is[a-z]*tic$"));
				rule.insert(make_pair("s-tic","^s[a-z]*tic$"));
				rule.insert(make_pair("p-tic","^p[a-z]*tic$"));
				rule.insert(make_pair("-lyt-ic","[a-z]*lyt[a-z]*ic$"));
				rule.insert(make_pair("ot-ic","^ot[a-z]*ic$"));
				rule.insert(make_pair("an-tic","^an[a-z]*tic$"));
				rule.insert(make_pair("n-tic","^n[a-z]*tic$"));
				rule.insert(make_pair("c-tic","^c[a-z]*tic$"));
				rule.insert(make_pair("at-ic","^at[a-z]*ic$"));
				rule.insert(make_pair("h-nic","^h[a-z]*nic$"));
				rule.insert(make_pair("n-ic","^n[a-z]*ic$"));
				rule.insert(make_pair("m-ic","^n[a-z]*ic$"));
				rule.insert(make_pair("l-lic","^l[a-z]*lic$"));
				rule.insert(make_pair("b-lic","^b[a-z]*lic$"));
				rule.insert(make_pair("-clic","[a-z]*clic$"));
				rule.insert(make_pair("l-ic","^l[a-z]*ic$"));
				rule.insert(make_pair("h-ic","^h[a-z]*ic$"));
				rule.insert(make_pair("f-ic","^f[a-z]*ic$"));
				rule.insert(make_pair("d-ic","^d[a-z]*ic$"));
				rule.insert(make_pair("-bic","[a-z]*bic$"));
				rule.insert(make_pair("a-ic","^a[a-z]*ic$"));
				rule.insert(make_pair("-mac","[a-z]*mac$"));
				rule.insert(make_pair("i-ac","^i[a-z]*ac$"));
				
				string model;
				string word("static");
				model = find(word,rule);
				cout<<model<<endl;

		return 0;
}
