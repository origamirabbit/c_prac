// swap_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void swap(int* p, int* q)
{
	int t; //���Ҫ����*p��*q��ֵ ��t ��ϧ�����int ���ܶ����int* �����﷨����

	t = *p; // p �� int*������ָ����ַ��    *p �� int����������ͬ�� main��� i
	*p = *q;
	*q = t;

	return;
}

int main(void)
{
	int a = 3;
	int b = 5;

	swap(&a, &b); // swap��*p,*q���Ǵ����
	printf("a = %d, b = %d\n", a, b);

	return 0;
}