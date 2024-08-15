#include <stdio.h>

int main(void)
{
	float score; //fenshu score
	
	printf("please enter your score: ");

	scanf_s("%f", &score);

	if (score > 100)

		printf("Dream\n");

	else if (score <= 100 && score >= 85)

		printf("Hight Distinction\n");

	else if (score < 85 && score >= 75)

		printf("Distinction\n");

	else if (score < 75 && score >= 65)

		printf("Credit\n");

	else if (score < 65 && score >= 50)

		printf("Pass\n");

	else if (score < 50 && score >= 0)

		printf("Fail\n");
	
	else

		printf("Impossible\n");

	return 0;
}