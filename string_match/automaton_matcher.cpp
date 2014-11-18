#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool is_end_with(const string& s1,const string& s2)
{
		for(string::size_type t1 = 0,t2 = s2.size()-s1.size();t1 < s1.size(),t2 <s2.size();++t1,++t2)
		{
					if(s1[t1] != s2[t2])
									return false;
		}
		return true;
}

vector< vector<int> > compute_transition(string P)
{
				int m = P.size();
				vector<vector<int> > transition;
				for(int q = 0;q <= m;++q)
				{
								vector<int> temp;
						for(int i = 0;i <= 25;++i)
						{
								string pk;
								string pq;
								int k = (m+1 > q+2)?q+2:m+1;
								do
								{
									 k -= 1;
									 if(k == 0)
													 break;
									 pk = P.substr(0,k);
									 pq = P.substr(0,q);
									 pq.insert(q,1,'a'+i);
								}while(!is_end_with(pk,pq));
								
								temp.push_back(k);
						}
						transition.push_back(temp);
				}
				return transition;
}

vector<int> automaton_matcher(const string& T,const vector< vector<int> >& trans,int m)
{
				int n = T.size();
				int q = 0;
				vector<int> shift;
				for(int i = 0;i < n;++i)
				{
								q = trans[q][T[i]-'a'];
								if(q == m)
											shift.push_back(i-m+1);
				}
				return shift;
}

int main(void)
{
				string P("abcd");
				string T("abcaabcd");
				vector< vector<int> > trans = compute_transition(P);

				vector<int> shift = automaton_matcher(T,trans,P.size());
				for(vector<int>::iterator it = shift.begin();it != shift.end();++it)
				{
								cout<<*it<<endl;
				}

		return 0;
}
