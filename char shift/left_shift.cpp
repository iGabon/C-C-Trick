//字符串左移算法

#include<iostream>
#include<string.h>

using namespace std;
//求最大公约数
int gcd(int m,int n)
{
	int num;
	if(m<n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}
	num = m%n;
	while(num)
	{
		m = n;
		n = num;
		num = m%n;
	}

	return n;
}
//STL中的rotate操作;m为左移的位数，n为字符串的长度，str为需要作左移操作的字符串
void rotate(char * str,int m,int n)
{
	int g = gcd(m,n);
	int k = 0;
	char tmp;
	for(int j = 0;j < g;j++)
	{
		tmp = *(str+j);
		char *last = str+j;
		for(int i = 1;i < n/g;i++)
		{
			k = (j+i*m)%n;
			*last = *(str+k);
			last = str+k;
		}
		*(str+k) = tmp; 
	}
}

int main(void)
{
	char str[] = "abcdefghijklmn";
	rotate(str,7,strlen(str));
	cout<<str<<endl;
	return 0;
}
