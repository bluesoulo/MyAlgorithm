#include<stdio.h>
long mergeArray(int array[], int array2[], int low, int mid, int high){
	long num = 0;
	for(int i = low; i <= high; i++){
		array2[i] = array[i];
	}
	//{3,7,9}��{1��2}�ϲ�ʱ��˼�� 
	int i = low, j = mid+1, k = low;
	while(i <= mid && j <= high){
		if(array2[i] <= array2[j]){ //ÿ����a[i]<a[j]ʱ����ô����Ը����ͷ������� 
			num = num + j - mid - 1;
			array[k++] = array2[i++];	
		}
		else{
		array[k++] = array2[j++];
		}
	}
	if(i <= mid){
		while(i <= mid){
		array[k++] = array2[i++];
		num  = num + (high - mid);
		}
	}
	
	while(j <= high){
		array[k++] = array2[j++];
	}
	return num;
}
long getReverse(int array[], int low, int high){
	if (low == high)
		return 0;
	else{
		int array2[high+1];
		int mid = (int)((low+high)/2);
		long c1 = getReverse(array, low, mid);
		long c2 = getReverse(array, mid+1, high);
		long c3 = mergeArray(array, array2, low, mid, high);
		return c1 + c2 + c3;
	}
}


int main(void){
//	int array[9] = {9,3,7,1,2,8,5,4,6};
	int n = 0;
	printf("����������Ԫ�ظ�����");
	scanf("%d",&n);
	int array[n];
	printf("��������������Ԫ�أ�");
	for(int i = 0;i < n;i++){
		scanf("%d",&array[i]);
	}
	long num = getReverse(array, 0, n-1);
	printf("��������Եĸ���Ϊ��%ld",num); 
	return 0;
}
