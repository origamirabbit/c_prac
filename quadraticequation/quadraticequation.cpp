/*
quadratic equatio with 2 roots
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;
	double delta;
	double x1, x2;
	char ch;

	do
	{
		printf("enter 3 varibles: \n");
		printf("a= ");
		scanf_s("%lf", &a);

		printf("b= ");
		scanf_s("%lf", &b);

		printf("c= ");
		scanf_s("%lf", &c);

		delta = b * b - 4 * a * c;

		if (delta > 0)
		{
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("two roots, x1 = %lf, x2 = %lf\n", x1, x2);
		}
		
		else if (delta == 0)
		{
			x1 = x2 = (-b) / (2 * a);
			printf("only one root, x1 = x2 = %lf\n", x1, x2);
		}
		else
		{
			printf("no real solution.\n");
		}

		printf("would you like to continue? (Y/N): "); //ѯ���Ƿ����ѭ�� N������� ��ֹѭ��
		scanf_s(" %c", &ch); //%cǰ�����ü�һ���ո�, �հ׷�

	} while ('y' == ch || 'Y' == ch);

	return 0;
}