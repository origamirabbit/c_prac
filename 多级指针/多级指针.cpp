// 多级指针.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main(void)

{
	int i = 10;
	int* p = &i;
	int** q = &p;
	int*** r = &q;

	printf("i = %d\n", ***r);

	return 0;
}