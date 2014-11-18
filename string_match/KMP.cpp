#include<iostream>
#include<vector>

using namespace std;

vector<int> compute_prefix(const string& P)
{
				vector<int> pi;
				int m = P.size();
				pi.push_back(0);
				int k = 0;
				for(int q = 1;q < m;++q)
				{
							while(k > 0 && (P[k] != P[q]))
							{
										k = pi[k];
							}
							if(P[k] == P[q])
											k = k+1;
							pi.push_back(k);
				}

				return pi;
}

vector<int> KMP_matcher(const string& T,const string& P)
{
				vector<int> result;
				int n = T.size();
				int m = P.size();
				vector<int> pi = compute_prefix(P);
				int q = 0;
				for(int i = 0;i < n;++i)
				{
								while(q > 0 && P[q] != T[i])
												q = pi[q-1];
								if(P[q] == T[i])
												q = q+1;
								if(q == m)
								{
												result.push_back(i-m+1);
												q = pi[q-1];
								}
				}
				return result;
}

int main(void)
{
				string P("ababaca");
				string T("aababacasababacafdjk");
				vector<int> shift = KMP_matcher(T,P);

				for(vector<int>::iterator it = shift.begin();it != shift.end();++it)
				{
								cout<<*it<<endl;
				}
		return 0;
}
