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
	
	f(&a, &b); // p���� ������ a���� �� ��ַ     ʵ��a �� �β�p �ǲ�ͬ�ı���
	printf("a = %d b = %d\n", a, b);

	return 0;
}
