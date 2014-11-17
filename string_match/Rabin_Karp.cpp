//Rabin_Karp法解决字符串匹配问题
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool cmp(const string& s1,const string& s2)
{
				for(string::size_type it1 = 0, it2 = 0;it1 < s1.size(),it2 < s2.size();++it1,++it2)
				{
								if(s1[it1] != s2[it2])
												return false;
				}
				return true;
}

vector<int> Rabin_Karp(const string& P,const string& T,int q,int d)
{
				int m = P.size();
				int n = T.size();
				vector<int> offset;
				int p = 0;
				int t = 0;
				for(int i =0;i < m;++i )
				{
						p = (p*d+P[i]-'0')%q;
						t = (t*d+T[i]-'0')%q;
				}
				int h=1;
				for(int i = 1;i < m;++i)
				{
						h *= d;
				}
				h %= q;
				for(int s = 0;s<n-m+1;++s)
				{
								if(t == p)
								{
												if(cmp(P,T.substr(s,m)))
												{
																offset.push_back(s);
												}
												
								}
								t = (d*(t-T[s]*h)+T[s+m])%q;
								if(t<0)
												t += q;
				}

				return offset;

}

int main(void)
{
		string p("123456");
		string T("2134561234565123456");
		vector<int> shift;
		shift = Rabin_Karp(p,T,13,10);
		for(vector<int>::iterator it = shift.begin();it != shift.end();++it)
		{
						cout<<*it<<endl;
		}

		return 0;
}
