// swap_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void swap(int* p, int* q)
{
	int t; //如果要互换*p和*q的值 则t 不惜定义成int 不能定义成int* 否则语法错误

	t = *p; // p 是 int*（变量指针或地址）    *p 是 int（变量）等同于 main里的 i
	*p = *q;
	*q = t;

	return;
}

int main(void)
{
	int a = 3;
	int b = 5;

	swap(&a, &b); // swap（*p,*q）是错误的
	printf("a = %d, b = %d\n", a, b);

	return 0;
}