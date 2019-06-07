#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 7
int Partition(int * array,int low,int high){
	int pivokey = array[low];
	while(low<high){
		while(low<high&&pivokey<=array[high]) high--;
		array[low] = array[high];
		while(low<high&&pivokey>=array[low]) low++;
		array[high] = array[low];
	}
	array[low] = pivokey;
	return low;
}
void Qsort(int * array,int low, int high){
	if(low<high){
		int pivotloc = Partition(array,low,high);
		Qsort(array,low,pivotloc-1);
		Qsort(array,pivotloc+1,high);
	}	
}
int Quicktime(int * array,int low, int high){
	int starttime = time(NULL);
	Qsort(array,low,high);
	int endtime = time(NULL);
	return starttime-endtime;
}
int main(){
	srand(time(NULL));
	int array[max];
	for(int i = 0;i<max;i++)
		array[i] = rand();
	int Qtime=Quicktime(array,0,max-1);
	for(int i=0;i<max;i++)
	printf(" %d",array[i]);
	return 0;
}

