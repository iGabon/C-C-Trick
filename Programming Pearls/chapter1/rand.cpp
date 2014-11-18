//生成1000000个介于0到10000000之间的不同的随机数，并且用位图法排序
#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

/*
 *生成m个介于0到n之间的有序的随机数
 */
void knuthRand(vector<int>& num,int m,int n)
{
		srand(time(0));
		for(int i = 0;i<n;++i)
		{
			if((rand()%(n-i)) < m)
			{
					num.push_back(i);
					m--;
			}
		}
}

void setRand(set<int>& num,int m,int n)
{
	srand(time(0));
	int temp;
	while(num.size() < m)
	{
			temp = rand()%n;
			num.insert(temp);
	}
}

void swapRand(vector<int>& num,int m,int n)
{
		srand(time(0));	
		int temp;
		for(int i = 0;i<n;++i)
		{
				num.push_back(i);
		}
    	int t;	
		for(int j = 0;j < m;++j)
		{
				t = j+rand()%(n-j);
				temp = num[j];
				num[j] = num[t];
				num[t] = temp;
		}
		sort(num.begin(),num.begin()+m);
}


int main(void)
{
		int n = 100;
		vector<int> num1;
		set<int> num2;
		vector<int> num3;
		int m = 50;
		knuthRand(num1,m,n);
		setRand(num2,m,n);
		swapRand(num3,m,n);

		for(vector<int>::iterator it = num1.begin();it != num1.end();++it)
		{
				cout<<*it<<' ';
		}
		cout<<endl;
		
		for(set<int>::iterator it = num2.begin();it != num2.end();++it)
		{
				cout<<*it<<' ';
		}
		cout<<endl;

		for(vector<int>::iterator it = num3.begin();it < num3.begin()+m;++it)
		{
				cout<<*it<<' ';
		}
		cout<<endl;

		return 0;
}
