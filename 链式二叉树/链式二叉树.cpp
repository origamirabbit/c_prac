// 链式二叉树.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct BTNode
{
	int data;
	struct BTNode* pLchild; //p指针变量 L左 R右 child是孩子
	struct BTNode* pRchild;
}BT;

//函数声明！
BT* CreateBTree(void);

void PreTraverseBTree(BT*);
void InTraverseBTree(BT*);
void PostTraverseBTree(BT*);

int main(void)
{
	
	BT* pT = CreateBTree();
	
	//PreTraverseBTree(pT);
	
	//InTraverseBTree(pT);
	
	PostTraverseBTree(pT);

	return 0;
}

//先序遍历！！！！////////////////////////////////////////////////////////
void PreTraverseBTree(BT* pT)  
{
	if (NULL != pT)  //如果 左子树 和 右子树 都为空 当 空 发给 pT时 并没有对应 指向的 pt->data 的值 所以会报错 需要添加 当pt不等于NULL时才可以执行如下程序 
	{
		//先访问根节点 再先序访问左子树 再先序访问右子树
		printf("%c\n", pT->data);

		if (NULL != pT->pLchild) //节省时间 空间 内存？？？
		{
			PreTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild) //节省空间 空间 内从？？？
		{
			PreTraverseBTree(pT->pRchild);
		}		
		//pT->pLchild 可以代表真个左子树 递归思想
	}	

}

//中序遍历！！！////////////////////////////////////////////////////////
void InTraverseBTree(BT* pT)
{
	if (NULL != pT)  //如果 左子树 和 右子树 都为空 当 空 发给 pT时 并没有对应 指向的 pt->data 的值 所以会报错 需要添加 当pt不等于NULL时才可以执行如下程序 
	{
		//先访问左子树 再中序访问根节点 再中序访问右子树

		if (NULL != pT->pLchild) //节省时间 空间 内存？？？
		{
			InTraverseBTree(pT->pLchild);
		}

		printf("%c\n", pT->data);

		if (NULL != pT->pRchild) //节省空间 空间 内从？？？
		{
			InTraverseBTree(pT->pRchild);
		}
		//pT->pLchild 可以代表真个左子树 递归思想
	}

}

//后序遍历！！！////////////////////////////////////////////////////////
void PostTraverseBTree(BT* pT)
{
	if (NULL != pT)  //如果 左子树 和 右子树 都为空 当 空 发给 pT时 并没有对应 指向的 pt->data 的值 所以会报错 需要添加 当pt不等于NULL时才可以执行如下程序 
	{
		//先访问左子树 再后序访问右子树 再后序访问根节点

		if (NULL != pT->pLchild) //节省时间 空间 内存？？？
		{
			PostTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild) //节省空间 空间 内从？？？
		{
			PostTraverseBTree(pT->pRchild);
		}

		printf("%c\n", pT->data);
		//pT->pLchild 可以代表真个左子树 递归思想
	}

}


BT* CreateBTree(void)
{
	BT* pA = (BT*)malloc(sizeof(BT));
	BT* pB = (BT*)malloc(sizeof(BT));
	BT* pC = (BT*)malloc(sizeof(BT));
	BT* pD = (BT*)malloc(sizeof(BT));
	BT* pE = (BT*)malloc(sizeof(BT));
	BT* pF = (BT*)malloc(sizeof(BT));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pF->data = 'F';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = pE;

	pE->pLchild = pE->pRchild = NULL;

	pD->pRchild = pF;
	
	pF->pLchild = pF->pRchild = NULL;

	return pA;
}