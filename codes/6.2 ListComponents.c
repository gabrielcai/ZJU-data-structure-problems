//06-ͼ1 �г���ͨ�� ��25 �֣�
//����һ����N�������E���ߵ�����ͼ������DFS��BFS�ֱ��г������е���ͨ�������趥���0��N?1��š���������ʱ�������������Ǵӱ����С�Ķ������������ŵ�����˳������ڽӵ㡣
//
//�����ʽ:
//�����1�и���2������N(0<N��10)��E���ֱ���ͼ�Ķ������ͱ��������E�У�ÿ�и���һ���ߵ������˵㡣ÿ���е�����֮����1�ո�ָ���
//
//�����ʽ:
//����"{ v
//?1
//??  v
//?2
//??  ... v
//?k
//??  }"�ĸ�ʽ��ÿ�����һ����ͨ���������DFS�Ľ���������BFS�Ľ����
//
//��������:
//8 6
//0 7
//0 1
//2 0
//4 1
//2 4
//3 5
//�������:
//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }
//����: ��Խ
//��λ: �㽭��ѧ
//ʱ������: 400 ms
//�ڴ�����: 64 MB
//���볤������: 16 KB

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



