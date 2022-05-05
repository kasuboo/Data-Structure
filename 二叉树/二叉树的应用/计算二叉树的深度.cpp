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
int Depth(BiTree T) //返回深度
{
	int countL=0,countR=0;
	int depth=0;
	if(!T)
		return 0;
	else
	{
		countL=Depth(T->Lchild);
		countR=Depth(T->Rchild);
		depth=1+(countL>countR?countL:countR);
	}
	return depth;
}
int main()
{
	BiTree T;
	printf("请输入第一个节点的数据:");
	T=Create(); //创建二叉树
	printf("\n该二叉树的深度为:");
	printf("%d",Depth(T));

	_getch();
	return 0;	
}



