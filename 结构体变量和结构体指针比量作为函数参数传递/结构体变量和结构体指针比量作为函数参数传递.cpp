// 结构体变量和结构体指针比量作为函数参数传递.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

struct Student // st 总字节数 为 108 考虑 对齐！
{
	int age; //4个字节
	char sex; //1个字节
	char name[100]; //100个字节 共105个字节
};

void InputStudent(struct Student* ); //前置声明
void OutputStudent(struct Student* );

int main(void)
{
	struct Student st;

	InputStudent(&st);  //对结构体变量输入 必须发送st的地址
	//printf("%d %c %s\n", st.age, st.sex, st.name);

	OutputStudent(&st); //对结构体变量输出  可以发送st的地址也可以直接发送st的内容


	return 0;
}

void OutputStudent(struct Student* ost) //发送st的地址 利用 const 禁止传递时对内容更改
{
	printf("%d %c %s\n", ost->age, ost->sex, ost->name);
}

void InputStudent(struct Student* pstudent)  //pstudent 只占4个字节 //但 pstudent 指向 stuct Student 108个字节
{
	(*pstudent).age = 10;
	pstudent->sex = 'M';
	strcpy_s(pstudent->name, "张三");	
}

//void InputStudent(struct Student student)  
//{
//	student.age = 10;
//	student.sex = 'F';
//	strcpy_s(student.name, "张三"); 
//
//}
