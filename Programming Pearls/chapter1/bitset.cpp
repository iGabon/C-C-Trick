#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1f
#define N 10000000

#include<iostream>


using namespace std;

int a[1+N/BITSPERWORD]; //相当于C++中的bitset，a为一个10000000位向量

void set(int i)  //设置第i位为1
{
				a[i>>SHIFT] |= (1<<(i & MASK));
}
void clr(int i)  //清除第i位为0
{
				a[i>>SHIFT] &= ~(1<<(i & MASK));
}
int test(int i)  //测试某位的值
{
				return a[i>>SHIFT] & (1<<(i & MASK));
}


int main(void)
{
		set(1);
		cout<<a[0]<<endl;
		return 0;
}
