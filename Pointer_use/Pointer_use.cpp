// Pointer_use.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>

int main(void)
{
	int* p;
	int* q;
	int i = 5;
	
	//*p = i; //��Ȼ *p �� i ����ͬ���ͱ��� ������д�Ǵ����  *pû��ȡ��ַ ���Ի����ѡȡ������ַ �����ϵͳ����
    
	p = &i; //��ȷд�� ������ַp ȡ ����i�ĵ�ַ *pָ��i 
	
	//*p = *q; //����д��

	//p = q; //q������ֵ�� q����p, pҲ�������ֵ
	  
	printf("%d\n %d\n", * p, * q); //20��
	//q�Ŀռ������ڱ������, ���Ա�������Զ�дq������, 
	//�������q���ڲ�������ֵ �Ȿ�����ܶ�д* q������ 
	//��Ϊ��ʱ * q ��������ڴ浥Ԫ�Ŀ���Ȩ�޲�û�з���������� ���Ա�����������20�л����

	return 0;
}