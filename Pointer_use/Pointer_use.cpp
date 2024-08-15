// Pointer_use.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>

int main(void)
{
	int* p;
	int* q;
	int i = 5;
	
	//*p = i; //虽然 *p 和 i 都是同类型变量 但这样写是错误的  *p没有取地址 所以会随机选取变量地址 会造成系统崩溃
    
	p = &i; //正确写法 变量地址p 取 变量i的地址 *p指向i 
	
	//*p = *q; //错误写法

	//p = q; //q是垃圾值， q赋予p, p也变成垃圾值
	  
	printf("%d\n %d\n", * p, * q); //20行
	//q的空间是属于本程序的, 所以本程序可以读写q的内容, 
	//但是如果q的内部是垃圾值 这本程序不能读写* q的内容 
	//因为此时 * q 所代表的内存单元的控制权限并没有分配给本程序 所以本程序运行至20行会出错

	return 0;
}