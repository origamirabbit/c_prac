// 结构体赋值与初始化.cpp
//

#include <stdio.h>

struct Student
{
	int age;
	float score;
	char sex;
};

int main(void)
{
	struct Student st = { 9, 90.9, 'F' }; //初始化 定义的同时赋初始值
	struct Student st2;
    st2.age = 11;     //分别赋值 
	st2.score = 88.8;  // 结构体变量名.成员名
	st2.sex = 'M';

	struct Student* pst = &st;
	pst->age = 16; //指针变量名->成员名
	pst->score = 75.5;
	pst->sex = 'M';




	printf("%d %f %c\n", st.age, st.score, st.sex);
	printf("%d %f %c\n", st2.age, st2.score, st2.sex);


	return 0;
}