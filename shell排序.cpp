#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10
void insertsort(int * array,int low,int high,int len){ //len表示对间隔为len的元素进行直接插入排序 
	for(int i=low+len;i<high;i=i+len){
		int tem =array[i];
		int j=i-len;
		for(;j>=0&&tem<array[j];j=j-len)
			array[j+len]=array[j];
		if(j<i-len)
			array[j+len]=tem;			
	}
}
void onecesort(int *array,int len,int high){
	for(int i=0;i<=len;i++)
	insertsort(array,i,high,len);
}
void shellsort(int *array,int high){
	for(int i=5;i>=0;i=i-2)
	onecesort(array,i,high);
}
//49 38 65 97 76 13 27 49 55 04
int main(){
	srand(time(NULL));
	int array[max];
	for(int i = 0;i<max;i++)
		array[i] = rand();
	for(int i = 0;i<max;i++)
		printf("%d ",array[i]);
	printf("\n");	
	shellsort(array,max);
	for(int i = 0;i<max;i++)
		printf("%d ",array[i]);
return 0; 
} 
