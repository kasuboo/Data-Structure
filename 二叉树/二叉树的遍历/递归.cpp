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
void XianXu(BiTree T) //先序遍历
{
	if(T==NULL) //如果没有,返回上一节点
	{
		return;
	}
	printf("%d ",T->data);
	XianXu(T->Lchild);
	XianXu(T->Rchild);
}
void ZhongXu(BiTree T) //中序遍历
{
	if(T==NULL)
	{
		return;
	}
	ZhongXu(T->Lchild);
	printf("%d ",T->data);
	ZhongXu(T->Rchild);
}
void HouXu(BiTree T)
{
	if(T==NULL)
	{
		return;
	}
	HouXu(T->Lchild);
	HouXu(T->Rchild);
	printf("%d ",T->data);
}
int main()
{
	BiTree T;
	printf("请输入第一个节点的数据:");
	T=Create(); //创建二叉树
	printf("\n先序遍历的结果是:");
	XianXu(T);
	printf("\n中序遍历的结果是:");
	ZhongXu(T);
	printf("\n后序遍历的结果是:");
	HouXu(T);

	_getch();
	return 0;	
}



