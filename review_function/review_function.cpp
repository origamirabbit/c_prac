// review_function.cpp : ������һ����ֵ ���������2�����ֵ����������
#include <stdio.h>

//int f(int i) //����е��غ�����int bool�Ȳ�ʹ��return �����غ���ֵ����     ���û�е��غ���ʹ��void return��(�ޱ��ʽ)
//{
//	return i;   //�����ڵı��� i ��������main�ı��� i ����ͻ ֻ�ڱ������ڶ���ʹ��
//}

//int main(void)
//{
//	int val;
//	int i;
//	int j;
//
//	scanf_s("%d", &val);
//	for (i = 2; i < val; ++i)  // 2 �� i-1
//	{
//		for (j = 2; j < i; ++j) //�ж�i �Ƿ��������� ��=���������=�����
//		{
//			if (0 == i % j)
//				break;
//		}
//		if (j == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//������������ʵ����1��ĳ���������е���������������� ��������������� ���ظ��Ը���

bool isPrime(int val) //�������Ĺ����ǣ��ж�val �Ƿ��������� ��=����true ����=����false
{
	int i;

	for (i = 2; i < val; ++i)
	{
		if (0 == val % i)
			break;
	}
	if (i == val)
		return true;
	else
		return false;
}

void TraverseVal(int val) //�������Ĺ����ǰ�1��n֮����е���������ʾ�������
{
	int i;

	for (i = 2; i <= val; ++i)
	{
		if (isPrime(i))
			printf("%d\n", i);
	}
	if (val == 1)  //����ֵΪ1�����
	{
		printf("%d\n", val);
	}	
	else
	{
		printf("invalid number��", val); //����ֵ���Ϸ� //�����ر�� �����룡����
	}		
}

int main(void)
{
	int val;

	scanf_s("%d", &val);

	TraverseVal(val);

	return 0;
}