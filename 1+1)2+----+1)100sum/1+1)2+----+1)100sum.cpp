/*
2021-03-13

1+1)2+----+1)100sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include <stdio.h>

int main(void)
{
	int i;                            // float i;  is not correct.�������洢���⣬ �������Ĵ�������������⣬float��double�����ܱ�֤���Ծ�ȷ�Ĵ洢һ��С�� 
	float sum = 0;                    // if (|x-0.000001| < 0.000001)  

	for (i = 1; i <= 100; ++i)        //ѭ���и��µı������ܶ���ɸ�����float
	{
		sum = sum +  1/(float)(i);    // 1.0 / i or 1 / (float)(i) force to change to float.
	}                                 // example: (int)(4.5+2.2) == 6 (��������)�����ʽ��

	printf("i = %d\n", i);
	printf("sum = %f\n", sum);        // use %f output float value  

	return 0;
}