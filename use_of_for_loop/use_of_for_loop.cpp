#include <stdio.h>

int main(void)
{
	int i,  j;

	for (i = 0; i < 3; ++i)       // i = 0;1;2;
		for (j = 2; j < 5; ++j)   // j = 2;3;4;    3x3 = 9 times "haha!"
			printf("haha!\n");
	printf("lol!\n"); 
	return 0;
}
