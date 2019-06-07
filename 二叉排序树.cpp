#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree construct_tree(int n,int * array){
	if(n<=0)
	exit(0);
	BiTree T =(BiTree)malloc(sizeof(BiTNode));
	T->data = array[0];
	T->lchild = NULL;
	T->rchild = NULL;
	for(int i=1;i<n;i++){
		BiTree tem = (BiTree)malloc(sizeof(BiTNode));
		tem->data = array[i];
		tem->lchild = NULL;
		tem->rchild = NULL;
		bool b =true;
		BiTree p = T,q = T;
		while(p){
			q=p;
			if(p->data>tem->data){
				p = p->lchild;
				b =	true;
			}
			else{
				p = p->rchild;
				b = false;
			}	
		}
		if(b)
		q->lchild=tem;
		else
		q->rchild=tem;		
	}
	return T;
}
void traverse(BiTree T){
	if(T){
		traverse(T->lchild);
		printf("%d ",T->data); 
		traverse(T->rchild);
	}
}
int main(){
	int n=0;
	scanf("%d",&n);
	int * array=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	scanf("%d",&array[i]);
	BiTree T =construct_tree(n,array);
	traverse(T);
	return 0;
} 
