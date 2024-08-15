// return_multiple_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void f(int* p, int* q)
{
	*p = 1;
	*q = 2;
}

int main(void)
{
	int a = 3, b = 5;
	
	f(&a, &b); // p变量 保存了 a变量 的 地址     实参a 和 形参p 是不同的变量
	printf("a = %d b = %d\n", a, b);

	return 0;
}
