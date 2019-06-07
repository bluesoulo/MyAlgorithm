#include<stdio.h>
#include<malloc.h>
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
int * select(HuffmanTree HT,int len){
	HuffmanTree p =HT;
	int min2[2]={-1,-1};
	int i = 0,tem = 0;
	for(;i<len;i++)
		if(HT[i].parent==0){
			if(min2[0]==-1)
			min2[0]=i;		
			else if(min2[1]=-1){
			min2[1]=i;
			break;	
			}
		}	
	if(HT[min2[0]].weight>HT[min2[1]].weight){
		tem = min2[0];
		min2[0]=min2[1];
		min2[1] =tem;
	}
	int j=i+1;
	for(;j<len;j++){
		if(HT[j].parent==0){
			if(HT[j].weight<HT[min2[0]].weight){
				min2[1] = min2[0];
				min2[0] = j;
			}else if(HT[j].weight<HT[min2[1]].weight)
					min2[1] = j;
		}
	}
	return min2;
}
HuffmanTree Huffmancodimg(int *w,int n){	
	int m = 2*n-1;
	HuffmanTree HT=(HuffmanTree)malloc(sizeof(HTNode)*(m));
	HuffmanTree p = HT;
	int i=0;
	for(;i<n;p++,i++){
		p->weight = w[i];
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}		 
	for(i=n;i<m;i++,p++){
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}//节点的初始化
	for(i=n;i<m;i++){
		int *s=select(HT,i);
		HT[s[0]].parent=i;
		HT[s[1]].parent=i;
		HT[i].weight=HT[s[0]].weight+HT[s[1]].weight;
		HT[i].lchild= s[0];
		HT[i].rchild= s[1];
	}
	return HT;
}
int main(){
	int n=0;
	scanf("%d",&n);
	int * array =(int *) malloc(sizeof(int)*n);
	int j=0;
	for(;j<n;j++)
	scanf("%d",&array[j]);
	HuffmanTree HT =Huffmancodimg(array,n);
	int sum=0,i=0;
	for(;i<n;i++)
	{
		int high=0;
		int j=i;
		while(HT[j].parent!=0){
			high++;
			j=HT[j].parent;
		}
		sum=sum+high*HT[i].weight;
	}
	printf("%d",sum);
	return 0;
}

