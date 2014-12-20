#include<iostream>
#include<vector>

using namespace std;

void lu_discomposition(vector< vector<int> >& A,vector<vector<int> >& L,vector<vector<int> >& U)
{
			int n = A.size();
			for(int k =0;k < n;++k)
			{
							U[k][k] = A[k][k];
							for(int i = k+1;i <n;++i)
							{
										L[i][k] = A[i][k]/U[k][k];
										U[k][i] = A[k][i];
							}
							for(int i = k+1;i < n;++i)
							{
											for(int j = k+1;j < n;++j)
											{
															A[i][j] = A[i][j]-L[i][k]*U[k][j];

											}
							}
			}
}

int main(void)
{
		vector<vector<int> > A;
		vector<int> a0;
		vector<int> a1;
		vector<int> a2;
		a0.push_back(4);
		a0.push_back(-5);
		a0.push_back(6);
		a1.push_back(8);
		a1.push_back(-6);
		a1.push_back(7);
		a2.push_back(12);
		a2.push_back(-7);
		a2.push_back(12);
		A.push_back(a0);
		A.push_back(a1);
		A.push_back(a2);
		vector<vector<int> > temp(A);
			vector< vector<int> > L;
			vector< vector<int> > U;
			vector<int> iver(A.size());
			for(int i = 0;i < A.size();++i)
			{
					L.push_back(iver);
					U.push_back(iver);
					L[i][i] = 1;
			}
		lu_discomposition(temp,L,U);

		for(vector<vector<int> >::iterator it = L.begin();it !=L.end();++it)
		{
						for(vector<int>::iterator t = (*it).begin();t != (*it).end();t++)
						{
										cout<<*t<<" ";
						}
						cout<<endl;
		}
		for(vector<vector<int> >::iterator it = U.begin();it !=U.end();++it)
		{
						for(vector<int>::iterator t = (*it).begin();t != (*it).end();t++)
						{
										cout<<*t<<" ";
						}
						cout<<endl;
		}
		return 0;
}
