// 间接调用自己举例.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int h(int n)
{
	if (n < 3)
		printf("haha\n");
	else
		n = h(n - 1);
	
	return n;
}

//int f(int n)
//{
//	n += 2; // n = n + 2；
//	return n;
//}

//void g(int m)
//{
//	f(m);
//}

int main(void)
{
	int val;

	//val = f(5);
	//printf("val = %d\n", val);  //输出值为  7

	val = h(5);

	return 0;
}
