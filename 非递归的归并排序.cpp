#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 7 
//归并排序
void Merge(int *source,int *target,int i,int m,int n){ //将两个有序数组归并 
	int s=i,j=m+1,k=i;     //0,1,3
	for(;k<=m&&j<=n;s++)
		if(source[j]<source[k])
		target[s] = source[j++];  //38,65,49,97
		else
		target[s] = source[k++];
	if(k<=m)
	for(;k<=m;k++,s++)
	target[s] = source[k];
	if(j<=n)
	for(;j<=n;j++,s++){
	target[s] = source[j];
	}
}
void Mergepass(int* source,int* target,int n,int len){ //n为总长度，数组下标从0开始 
	int i =0;
	while(i<=n-len*2){
		Merge(source,target,i,i+len-1,i+len*2-1);
		i=i+2*len;
	}
	if(i<n-len)
		Merge(source,target,i,i+len-1,n-1);
	else
		for(int j=i;j<n;j++)
			target[j]=source[j];
}
int * Mergesort(int *source,int *target,int n){
	int j=1;
	for(int i =1;i<n;i=i*2,j++)
	if(j%2==1)	
	Mergepass(source,target,n,i);
	else
	Mergepass(target,source,n,i);	
    if(j%2==0)
    return target;
    else
    return source;
}
int main(){
	srand(time(NULL));
	int array[max];
	for(int i = 0;i<max;i++)
		array[i] = rand();
	for(int i =0;i<max;i++)
	printf("%d ",array[i]);
	printf("\n");
	int array2[max];
	int* result=Mergesort(array,array2,max);
	for(int i=0;i<7;i++)
	printf("%d ",result[i]);
return 0; 
} 
