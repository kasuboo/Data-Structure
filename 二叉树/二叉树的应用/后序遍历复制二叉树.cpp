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
BiNode *GetNode(ElementType data,BiNode *L,BiNode *R) //指针函数，返回指针
{
	BiTree node=new BiNode;
	node->data=data;
	node->Lchild=L;
	node->Rchild=R;
	return node;
}
BiNode *HcopyTree(BiTree T) //后序遍历
{
	BiTree NewT;
	BiTree NewL=new BiNode,NewR=new BiNode;
	if(!T)
		return NULL;
	else
	{
		if(T->Lchild)
			NewL=HcopyTree(T->Lchild);
		else
			NewL=NULL;
		if(T->Rchild)
			NewR=HcopyTree(T->Rchild);
		else
			NewR=NULL;
	}
	NewT=GetNode(T->data,NewL,NewR);
	return NewT;
}
void HouXu(BiTree t)
{
	if(t==NULL)
		return;
	else
	{
		HouXu(t->Lchild);
		HouXu(t->Rchild);
	}
	printf("%d ",t->data);
}
int main()
{
	BiTree T;
	BiTree NewT;
	printf("请输入第一个节点的数据:");
	T=Create(); //创建二叉树
	//后序遍历复制二叉树
	NewT=HcopyTree(T);
	HouXu(NewT);

	_getch();
	return 0;	
}



