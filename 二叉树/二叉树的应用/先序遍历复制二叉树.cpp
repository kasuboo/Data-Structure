#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct BiNode{
	ElementType data; //数据域
	BiNode *Lchild,*Rchild; //左右孩子
}BiNode,*BiTree;
BiTree Create()
{
	int date;
	int temp;
	BiTree tree;
	scanf("%d",&date);
	if(date==-1) //停止输入
	{
		return NULL;
	}
	else
	{
		tree=(BiTree)malloc(sizeof(BiNode)); //分配内存空间
		tree->data=date; //当前数据存入当前节点
		//开始创建左右孩子
		printf("请输入%d的左子树: ",date);
		tree->Lchild=Create(); //递归创建
		printf("请输入%d的右子树: ",date);
		tree->Rchild=Create();
		return tree;
	}
}
void copyTree(BiTree T,BiTree &NewT) //先序遍历
{
	if(T==NULL)
	{
		NewT=NULL;
	}
	else
	{
		NewT=new BiNode; //创建新节点
		NewT->data=T->data;
		copyTree(T->Lchild,NewT->Lchild);
		copyTree(T->Rchild,NewT->Rchild);
	}
}
void XianXu(BiTree t)
{
	if(t==NULL)
		return;
	else
	{
		printf("%d ",t->data);
		XianXu(t->Lchild);
		XianXu(t->Rchild);
	}
}
int main()
{
	BiTree T;
	BiTree NewT;
	printf("请输入第一个节点的数据:");
	T=Create(); //创建二叉树
	copyTree(T,NewT); //复制
	printf("\n复制的新二叉树为:");
	XianXu(NewT);

	_getch();
	return 0;	
}



