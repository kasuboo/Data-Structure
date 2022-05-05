#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int Status;
#define error 0;
#define ok 1;
#define maxsize 100;
typedef int el;
typedef struct BiNode{
	int data; //数据域
	BiNode *Lchild,*Rchild; //左右孩子
}BiNode,*BiTree;
typedef BiTree ElementType;
typedef struct stack{
	ElementType *base,*top;
	int size;
}stack;
Status Inistack(stack &s) //初始化
{
	s.base=new ElementType[100];
	s.top=s.base;
	s.size=maxsize;
	return ok;
}
Status push(stack &s,ElementType e) //入栈
{
	if(s.top-s.base==s.size) //栈满
		return error;
	*s.top++=e;
	return ok;
}
Status pop(stack &s,ElementType &e) //出栈
{
	if(s.top==s.base) //空栈
		return error;
	e=*--s.top;
	return ok;
}
ElementType GetTop(stack s) //取栈顶元素
{
	if(s.top!=s.base)
		return *(s.top-1);
}
Status stackEmpty(stack &s)
{
	if(s.top-s.base==0)
		return ok;
	return error;
}
BiTree createTree() //创建树
{
	int data;
	BiTree tree;
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	else
	{
		tree=(BiTree)malloc(sizeof(BiNode));
		tree->data=data;
		printf("请输入%d的左子树:",data);
		tree->Lchild=createTree();
		printf("请输入%d的右子树:",data);
		tree->Rchild=createTree();
		return tree;
	}
}
void PreorderTraverse(BiTree T) //非递归前序遍历
{
	BiTree P=T;
	stack s;
	Inistack(s);
	while(P||!stackEmpty(s))
	{
		//向左走到尽头
		while(P)
		{
			printf("%d ",P->data);
			push(s,P);
			P=P->Lchild;
		}
		pop(s,P);
		P=P->Rchild;
	}

}
void InorderTraverse(BiTree T) //非递归中序遍历
{
	BiTree P=T;
	stack s;
	Inistack(s);
	while(P||!stackEmpty(s))
	{
		while(P)
		{
			push(s,P);
		    P=P->Lchild;
		}
		pop(s,P);
		printf("%d ",P->data);
		P=P->Rchild;
	}
}
void PostorderTraverse(BiTree T)
{
	BiTree P;
	stack s;
	BiTree b=new BiNode;
	Inistack(s);
	while(P||!stackEmpty(s))
	{
		//向左走到尽头
		while(P)
		{
			push(s,P);
			P=P->Lchild;
		}
		int flag=1;b=NULL;
		while(flag&&!stackEmpty(s))
		{
			GetTop(s);
			if(P->Rchild==b) //如果右子树为空或者刚刚处理过
			{
				pop(s,P);
				printf("%d ",P->data);
				b=P;
			}
			else
			{
				P=P->Rchild;
				flag=0;
			}
		}
		
	}
}
int main()
{
	BiTree T;
	printf("请输入第一个节点的数据:");
	createTree();
	printf("/n非递归的先序遍历结果为:");
	PreorderTraverse(T);
	printf("/n非递归的中序遍历结果为:");
	InorderTraverse(T);
	printf("/n非递归的后序遍历结果为:");
	PostorderTraverse(T);


	_getch();
	return 0;	
}



