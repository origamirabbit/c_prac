// 阶乘的循环使用.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main(void)
{
	int val;
	int i, multi = 1;

	printf("请输入一个整数: ");
	printf("val = ");
	scanf_s("%d", &val);

	for (i = 1; i <= val; ++i)  //阶乘for循环
		multi = multi * i;

	printf("%d 的阶乘是: %d\n", val, multi);

	return 0;
}
