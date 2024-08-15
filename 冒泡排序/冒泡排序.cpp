// 冒泡排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void sort(int* a, int len)
{
	int i, j;
	int t;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1]) //>表示升序 <表示降序
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int a[7] = { 10,2,8,2,-8,11,0 };
	int i = 0;

	sort(a, 7);

	for (i = 0; i < 7; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}