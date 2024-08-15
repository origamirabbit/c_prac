// 跨函数使用内存.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void f(int** q) 
{
	int i = 5;
	//*q等价于p  q和**q都不等价于p
	*q = &i; // p = &i
}

int main(void)
{
	int* p;
	
	f(&p);
	printf("%d\n", *p); //本 语句 语法没有问题  但是 逻辑上 有问题
	//当 f()函数执行完毕 f()内的变量 内存释放 导致 主函数main 下 的 p所指向的内存 丢失 导致*p=i的值逻辑上出问题

	return 0;
}