#include <stdio.h>
/*
void max1(int i, int j) //max is name of the function and i j ��ʽ���� void��ʾ����û�з���ֵ
{
	if (i > j)                     //��һ������ �� ���ܲ���
		printf("max: %d\n", i);    //���ֵ �ҵ� �� ����
	else
		printf("max: %d\n", j);
}
*/

int max2(int i, int j) //�ڶ������� ���ܺ�һЩ ��ͨ���� �з���ֵ ��int float double....
{ 
	if (i > j)           //ֻ�ҵ� ���ֵ
		return i;
	else
		return j;
}

int main(void)
{
	int a, b, c, d, e, f;

	a = 1; b = 2; c = 3; d = 9; e = -5; f = 100;

	printf("%d\n", max2(a, b));   //�ڶ��ַ��� ����һЩ 
	printf("%d\n", max2(c, d));
	printf("%d\n", max2(e, f));

/*
	max1(a, b);
	max1(c, d);
	max1(e, f);
*/
	return 0;
}


