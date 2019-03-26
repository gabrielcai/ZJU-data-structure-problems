//习题4.5 顺序存储的二叉树的最近的公共祖先问题 （25 分）
//设顺序存储的二叉树中有编号为i和j的两个结点，请设计算法求出它们最近的公共祖先结点的编号和值。
//
//输入格式:
//输入第1行给出正整数n（≤1000），即顺序存储的最大容量；第2行给出n个非负整数，其间以空格分隔。其中0代表二叉树中的空结点（如果第1个结点为0，则代表一棵空树）；第3行给出一对结点编号i和j。
//
//题目保证输入正确对应一棵二叉树，且1≤i,j≤n。
//
//输出格式:
//如果i或j对应的是空结点，则输出ERROR: T[x] is NULL，其中x是i或j中先发现错误的那个编号；否则在一行中输出编号为i和j的两个结点最近的公共祖先结点的编号和值，其间以1个空格分隔。
//
//输入样例1：
//15
//4 3 5 1 10 0 7 0 2 0 9 0 0 6 8
//11 4
//输出样例1：
//2 3
//输入样例2：
//15
//4 3 5 1 0 0 7 0 2 0 9 0 0 6 8
//12 8
//输出样例2：
//ERROR: T[12] is NULL
//作者: DS课程组
//单位: 浙江大学
//时间限制: 400 ms
//内存限制: 64 MB
//代码长度限制: 16 KB

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

int main(){
	//freopen("4.5.txt","r",stdin);
	int Data[MAXSIZE+1];
	int i,N;
	scanf("%d\n",&N);
	for(i=0;i<N;i++){
		if(i==N-1) scanf("%d\n",&Data[i+1]);
		else scanf("%d ",&Data[i+1]);
	}
	int k,l;
	scanf("%d %d\n",&k,&l);
	if(Data[k]==0) {
		printf("ERROR: T[%d] is NULL",k);
		return 0;
	}
	else if (Data[l]==0) {
		printf("ERROR: T[%d] is NULL",l);
		return 0;
	}
	else {
		while(l!=k) {
			if(l<k) k = k/2;
			else l = l/2;
		}
	    printf("%d %d",l,Data[l]);	
		}
	}

