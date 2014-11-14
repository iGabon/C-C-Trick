//生成1000000个介于0到10000000之间的不同的随机数，并且用位图法排序
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;

int main(void)
{
		srand(time(0));
		int i = 1000000;
		vector<int> num;
		
		int m = 1000000;
		for(int i = 0;i < 10000000;i++)//随机数生成算法，生成的数各不相同，编程珠玑120页
		{
			if((rand()%(10000000-i)) < m)
			{
				num.push_back(i);
				m--;
			}
		}
		
		vector<int> sortedNum;
		time_t begin = time(0);
		bitset<10000000> bit;
		bit.reset();
		int temp;	
		for(vector<int>::iterator it = num.begin();it != num.end();++it)
		{
				temp = *it;
				bit.set(temp);
		}
		for(int j = 0;j<10000000;j++)
		{	
			if(bit.test(j))
					sortedNum.push_back(j);
		}
		time_t end = time(0);
		cout<<"bitsort time : "<<difftime(end,begin)<<endl;

		begin = time(0);
		sort(num.begin(),num.end());
		end = time(0);
		cout<<"quicksort time : "<<difftime(end,begin)<<endl;

/*
		ofstream outfile_("sortedNum",ofstream::app);
		if(outfile_)
		{
				for(int j = 0;j<10000000;j++)
				{
						if(bit.test(j))
								outfile_<<j<<endl;
				}
		}
		outfile_.close();
		outfile_.clear();
		*/
		return 0;
}
