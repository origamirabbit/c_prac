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
//	//p - q; //û��ʵ������  һ�������������������
//	
//	int a[5];
//    p = &a[0];
//	q = &a[4];
//	printf("p��q��ָ��ĵ�Ԫ��� %d ����Ԫ\n", q - p);
//
//	return 0;
//}


/*
һ��ָ���������վ�����ֽڵ����� 2021-03-21 12:48
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