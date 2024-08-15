// 确定1维数组需要几个参数.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void f(int* pArr, int len) //形参需要两个 一个是数组首个元素地址  一个是数组长度
{
	int i;

	for (i = 0; i < len; ++i)
	{
		printf("%d ", *(pArr + i));  //*(pArr + i) 等价于  pArr[i]  也等价于 main里的 a[i] b[i] c[i] 或 *(a+i) *(b+i) *(c+i)
		//  *pArr *(pArr+1) *(pArr+2).....
	}
	printf("\n");
}

int main(void)
{
	int a[5] = { 1,2,3,4,5 };
	int b[6] = { -1,-2,-3,-4,-5,-6 };
	int c[100] = { 1,10,100,1000 };

	a == &a[0];// a 是常量 是固定的 即该数组第一个元素的地址
	printf("%#X %#X\n", a, &a[0]); //输出16进制的 数组地址

	f(a, 5); //a 是 int* 指针变量
	f(b, 6);
	f(c, 100);

	return 0;
}