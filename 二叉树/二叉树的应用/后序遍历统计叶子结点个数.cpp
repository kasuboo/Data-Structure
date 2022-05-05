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
int CountLeaf_2(BiTree T) 
{
	int countL=0,countR=0;
	if(T)
	{
		if((!T->Lchild)&&(!T->Rchild))
	    {
			return 1;
	    }
	    countL=CountLeaf_2(T->Lchild);
	    countR=CountLeaf_2(T->Rchild);
		return countR+countL;
	}
	return 0;
}
int main()
{
	BiTree T;
	printf("请输入第一个节点的数据:");
	T=Create(); //创建二叉树
	printf("\n该二叉树的叶子结点数量为:");
	printf("%d",CountLeaf_2(T));

	_getch();
	return 0;	
}



