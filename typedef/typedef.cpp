// typedef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

//typedef int ZHANGSAN; // Ϊint������ ���� ȡ һ������ ZAHNGSAN�ȼ���int

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
}* PST, ST; //PST �ȼ���struct Student*      ST��ʾstruct Student

int main(void)
{
	//int i = 10; // �ȼ��� ZHANGSAN��i = 10;
	//ZHANGSAN j = 20;
	//printf("%d\n", j);

	//struct Student st; //�ȼ��� ST st;
	//struct Student* pst = &st; //�ȼ��� ST* pst;

	//ST st2;
	//st2.sid = 200;
	//printf("%d\n", st2.sid);

	/*struct Student st;
	PST pst = &st;
	pst->sid = 99;
	printf("%d\n",pst->sid);*/

	ST st; // �ȼ��� struct Student st;
	PST pst = &st; //struct Student* pst = &st;

	return 0;
}
