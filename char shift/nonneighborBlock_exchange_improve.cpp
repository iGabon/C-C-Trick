//ABC类型转换为CBA

#include<iostream>
#include<string>

using namespace std;
//字符串逆序操作
void invert(string& s,int start,int end)
{
		char tmp;
		while(start <= end)
		{
				tmp = s[start];
				s[start] = s[end];
				s[end] = tmp;
				start++;
				end--;								
		}

}

//ABC转换成CBA，其中l为A块的长度，r为C块的长度，s为需要转换的字符串
void exchange(string& s,int l,int r)
{
		int len = s.size();
		invert(s,0,l-1);
		invert(s,l,len-r-1);
		invert(s,len-r,len-1);
		invert(s,0,len-1);
}

int main(void)
{
		string s;
		getline(cin,s);
		int l,r;
		cin>>l>>r;
		exchange(s,l,r);
		cout<<s<<endl;
		return 0;
}
