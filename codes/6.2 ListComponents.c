//06-图1 列出连通集 （25 分）
//给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N?1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
//
//输入格式:
//输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。
//
//输出格式:
//按照"{ v
//?1
//??  v
//?2
//??  ... v
//?k
//??  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。
//
//输入样例:
//8 6
//0 7
//0 1
//2 0
//4 1
//2 4
//3 5
//输出样例:
//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }
//作者: 陈越
//单位: 浙江大学
//时间限制: 400 ms
//内存限制: 64 MB
//代码长度限制: 16 KB

#include <stdio.h>
#include  <stdlib.h>

#define  MAXSIZE 11

void DFS(int n, int N, int** Edges, int* IsVisited){
	IsVisited[n] = 1;
	printf(" %d",n);
	for(int i=0;i<N;i++){
			if(Edges[n][i]==1 && !IsVisited[i])
				DFS(i,N,Edges,IsVisited);
	} 
}

void BFS(int n,  int N,int** Edges, int* IsVisited){
	int Queue[MAXSIZE],lo=0,hi=0;
	IsVisited[n] = 1;
	printf(" %d",n);
	Queue[hi++] = n;//enqueue
	while(lo!=hi){
		int V = Queue[lo++];
		for(int i=0;i<N;i++){
			if(Edges[V][i]==1 && !IsVisited[i]){
				IsVisited[i] = 1;
				printf(" %d",i);
				Queue[hi++] = i;
			}	
		} 
	}
}

int main(){
	freopen("6.2.txt","r",stdin);
	int N,E;
	scanf("%d %d\n",&N,&E);
	int** Edges= (int **)malloc((N)*sizeof(int *));
	for(int i = 0;i<N;i++){
		Edges[i]= (int *)malloc((N)*sizeof(int ));
	}
	for(int i = 0;i<N;i++){
		for(int j = 0; j<N;j++) Edges[i][j]=0;
	} 

	int IsVisited[N];
	for(int i = 0;i<N;i++) IsVisited[i]=0;
	int V1,V2;
	for(int i = 0;i<E;i++){
		scanf("%d %d\n",&V1,&V2);
		Edges[V1][V2]=1;
		Edges[V2][V1]=1;
	}
	//dfs
//	for(int i = 0;i<(N+1)*(N+1);i++){
//		printf("%d",*(&Edges[0][0]+i));
//		if((i)%(N+1)==N) printf("\n");
//	}
	//printf("DFS\n");
	for(int i = 0;i<(N);i++){
		if(!IsVisited[i]) {
			printf("{"); 
			DFS(i,N,Edges,IsVisited);
			printf(" }\n");
		}
	}
	//printf("BFS\n");
	//bfs
	for(int i = 0;i<N;i++) IsVisited[i]=0;
	for(int i = 0;i<(N);i++){
		if(!IsVisited[i]) {
			printf("{"); 
			BFS (i,N,Edges,IsVisited);
			printf(" }\n");
		}
	}
	
	return 0;
}



