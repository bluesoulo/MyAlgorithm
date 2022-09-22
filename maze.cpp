#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define L 1
#define R 2
#define U 3
#define D 4

//初始化的迷宫
//入口坐标是（1，0），出口坐标是（7，8）
int maze[9][9] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {3, 0, 1, 0, 0, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 1, 1, 1},
            {1, 1, 0, 1, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 0, 0, 1},
            {1, 1, 2, 0, 0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1}
            };
void printChar(char * ch, int len){
	for(int i = 0; i<len; i++)
		printf("%c",ch[i]);
	printf("\n");
}

//问题的主要原因是因为是数组在调用的过程之中被修改之后永远会被修改！所以需要被修改为原状！ 
void seek(int x, int y, char *s, int step, int ** a){
    if(maze[x][y] == 2){
    	printChar(s, step);
    }   
     if( (x - 1) >= 0 && maze[x-1][y]!=1&& a[x-1][y]!= 1){
            s[step] = 'U';
            a[x-1][y] = 1;
            seek(x-1, y, s, step + 1, a);
            a[x-1][y] = 0;
        }
        if((x+1) <=8 && maze[x+1][y]!=1 && a[x+1][y] != 1){
            s[step] = 'D';
            a[x+1][y] = 1;
            seek(x+1, y, s, step + 1, a);
            a[x+1][y] = 0;
        }
        if( (y-1)>=0 && maze[x][y-1]!=1 && a[x][y-1] != 1){
            s[step] = 'L';
            a[x][y-1] = 1;
            seek(x, y-1, s, step + 1, a);
            a[x][y-1] = 0;
        }
        if( (y+1)<=8 && maze[x][y+1]!=1 && a[x][y+1] != 1 && a[x][y+1] != 1){
            s[step] = 'R';
            a[x][y+1] = 1;
//            printChar(s, step+1);
            seek(x, y+1, s, step + 1, a);
			a[x][y+1] = 0;
        }

}


int main(){
	//使用非malloc的情况创建的数组存在的问题 
	int ** a = new int*[9]; //使用数组a记录行走的路线，防止深度优先时出现环路的问题！ 
	for(int i = 0; i<9; i++){
		a[i] = new int[9];
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j< 9; j++)
		a[i][j] = 0;
	} 
    char s[100];  //存放路径 
    int step = 0; //这里没做回溯的原因是设置了step变量自动就可以回溯！ 
    seek(1, 0, s, step, a);
    return 0;

}
