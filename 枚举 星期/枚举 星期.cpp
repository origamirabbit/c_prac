// 枚举 星期.cpp : 
//2021-03-23 12:42
//

#include <stdio.h>

enum WeekDay //定义枚举类型
{
	Monday=2, Tuesday=3, Wednesday=4, Thursday=5, Friday=6, Saturday=7, Sunday=1
};

int main(void)
{
	//int day;
	enum WeekDay day = Tuesday;
	printf("%d\n", day);

	return 0;
}
