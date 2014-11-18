#include<iostream>


using namespace std;

void count(const int& i)
{
						for(int x = i;x != 1;)
						{
										if(x % 2 == 0)
														x /= 2;
										else
														x = 3*x+1;
						}
}



int main(void)
{
				for(int i = 2;i < 50;++i)
				{
								cout<<"test : "<<i<<endl;
								count(i);
				}

		return 0;
}
