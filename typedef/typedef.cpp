// typedef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

//typedef int ZHANGSAN; // 为int再重新 定义 取 一个名字 ZAHNGSAN等价于int

//typedef struct Student
//{
//	int sid;
//	char name[100];
//	char sex;
//}ST;

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}* PST, ST; //PST 等价于struct Student*      ST表示struct Student

int main(void)
{
	//int i = 10; // 等价于 ZHANGSAN　i = 10;
	//ZHANGSAN j = 20;
	//printf("%d\n", j);

	//struct Student st; //等价于 ST st;
	//struct Student* pst = &st; //等价于 ST* pst;

	//ST st2;
	//st2.sid = 200;
	//printf("%d\n", st2.sid);

	/*struct Student st;
	PST pst = &st;
	pst->sid = 99;
	printf("%d\n",pst->sid);*/

	ST st; // 等价于 struct Student st;
	PST pst = &st; //struct Student* pst = &st;

	return 0;
}
