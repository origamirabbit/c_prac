// 不同函数之间相互调用.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>

void f(int);
void g();
void h();

int main(void)
{
	f(3);
	return 0;
}

void f(int n)                   //自己函数调用自己 
{
	if (n == 1)
	    printf("haha！\n");
	else
	    f(n - 1);
	    
}

//void f()                   //三个函数之间调用的顺序 
//{
//	printf("F\n");
//	g();
//	printf("1\n");
//}
//
//void g()
//{
//	printf("G\n");
//	h();
//	printf("2\n");
//}
//
//void h()
//{
//	printf("H\n");
//	printf("3\n");
//}

