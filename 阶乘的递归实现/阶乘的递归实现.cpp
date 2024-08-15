// 阶乘的递归实现.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

//假定n的值是1或大于1的值 
long f(int n)                         //求阶乘的递归
{
	if (1 == n)
		return 1;
	else
		return f(n - 1) * n;
}

long sum(int m)                         //求1+2+3+...+99+100的和的递归
{
	if (1 == m)
		return 1;
	else
		return sum(m - 1) + m;
}

int main(void)
{
	printf("%ld\n", f(8));
	
	printf("%ld\n", sum(100));

	return 0;
}
