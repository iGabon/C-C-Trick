#include<iostream>
#include<vector>

using namespace std;

bool binary_search(const vector<int>& iv,int num,int first,int last,int& count)
{
				if(first>last)
				{
								cout<<"no "<<num<<endl;
								return false;
				}
							count++;
							int mid = (first+last)/2;
							if(iv[mid] == num)
							{
											cout<<"position is : "<<mid<<endl;
											return true;
							}
							else if(iv[mid] > num)
							{
											last = mid-1;
											binary_search(iv,num,first,last,count);
							}
							else{

											first = mid+1;
											binary_search(iv,num,first,last,count);
							}
}

int main(void)
{
				int count = 0;
				vector<int> iv;
				iv.push_back(1);
				iv.push_back(2);
				iv.push_back(4);
				iv.push_back(6);
				iv.push_back(7);
				iv.push_back(8);
				iv.push_back(11);
				iv.push_back(32);

				binary_search(iv,43,0,iv.size()-1,count);
				cout<<"compared "<<count<<" times"<<endl;
		return 0;
}
