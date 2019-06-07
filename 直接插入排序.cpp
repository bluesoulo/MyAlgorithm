#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 7
void insertsort(int * array,int low,int high){
	for(int i=high-1;i>=0;i--){
		int tem =array[i];
		int j=i+1;
		for(;j<=high&&tem>array[j];j++)
			array[j-1]=array[j];
		if(j>i+1)
			array[j-1]=tem;			
	}
}
int main(){
	srand(time(NULL));
	int array[max];
	for(int i = 0;i<max;i++)
		array[i] = rand();
	insertsort(array,0,max-1); 
	for(int i = 0;i<max;i++)
		printf("%d ",array[i]);
return 0; 
} 
