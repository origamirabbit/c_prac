/*
2021-03-18
�ж��Ǹ����� �Ƿ� ������ ���������ֳ�������ָ��һ������1����Ȼ���У�����1�ʹ����������⣬�޷���������Ȼ������������Ҳ�ɶ���Ϊֻ��1�ͱ������������������� ��1�󵫲�������������Ϊ������1��0�ȷ�����Ҳ�Ǻ��������������������ź���Ҫ�ĵ�λ����
*/

#include <stdio.h>

bool isPrime(int val) //bool =�� ture or false
{
	int m;

	for (m = 2; m < val; ++m)  // ��2��ʼѭ���� val-1��ֵ
	{
		if (val % m == 0)      // ���ѭ��������һ��iֵ�ܱ� val��ֵ���� ����ֹforѭ�� ˵��val��ֵֵ�������� ��i<val ִ��else���
			break;
	}
	if (m == val)          //��i��ֵ+��val��ֵ ˵�� val��ֵ������ 
		return true;
	else
		return false;	
}

int main(void)
{
	int val;
	//int i;

	scanf_s("%d", &val);

	//for (i = 2; i < val; ++i)  // ��2��ʼѭ���� val-1��ֵ
	//{
	//	if (val % i == 0)      // ���ѭ��������һ��iֵ�ܱ� val��ֵ���� ����ֹforѭ�� ˵��val��ֵֵ�������� ��i<val ִ��else���
	//		break;
	//}
	//if (i == val)          //��i��ֵ+��val��ֵ ˵�� val��ֵ������ 
	//	printf("Yes!\n");  
	//else
	//	printf("No!\n");

	if (isPrime(val))
		printf("Yes!\n");
	else
		printf("No!\n");
		
	return 0;
}