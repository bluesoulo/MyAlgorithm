### 棋盘覆盖问题

#### 问题描述

将n个数字划分为m组，输出划分的数目

![棋盘问题](https://github.com/bluesoulo/myalgorithm/blob/master/image/Stirling.png?raw=true "棋盘问题")

情况一：将其与将n-1个数据划分m组，

情况二：n-1个数据划分为m-1组，第n个数字单独一组的情况；

```
#include<stdio.h>

/*
实现思路：将n个数字划分为m组，尝试将其与将n-1个数据划分m组，和n-1个数据划分为m-1组，第n个数字单独一组的情况； 
*/ 
long Stirling(int n , int m){
	if (m == n||m ==1){
		return 1;
	}
	else if(n < m || m <= 0){
		return 0;
	}
	else{
		return Stirling(n-1, m-1) +  m * Stirling(n-1, m);
	}
}
int main(void){
	int n,m = 0;
	printf("请输入n,m:");
	scanf("%d %d", &n, &m);
	long num = 0;
	num = Stirling(n,m);
	printf("将n个数字划分为m组有%ld中可能性\n", num);
}
```
