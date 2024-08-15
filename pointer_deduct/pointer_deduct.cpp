// pointer_deduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

//int main(void)
//{
//	//int i = 5;
//	//int j = 10;
//	int* p; //= &i;
//	int* q; //= &j;
//	
//	//p - q; //没有实际意义  一般是数组相减才有意义
//	
//	int a[5];
//    p = &a[0];
//	q = &a[4];
//	printf("p和q所指向的单元相隔 %d 个单元\n", q - p);
//
//	return 0;
//}


/*
一个指针变量到底站几个字节的问题 2021-03-21 12:48
*/
int main(void)
{
	char ch = 'A';
	int i = 90;
	double x = 66.6;

	char* p = &ch;
	int* q = &i;
	double* r = &x;

	printf("%d %d %d\n", sizeof(p), sizeof(q), sizeof(r));

	return 0;
}