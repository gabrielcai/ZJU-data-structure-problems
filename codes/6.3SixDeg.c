//06-ͼ3 ���ȿռ� ��30 �֣�
//�����ȿռ䡱�����ֳ��������ȷָ���Six Degrees of Separation�������ۡ�������ۿ���ͨ�׵ز���Ϊ��������κ�һ��İ����֮����������˲��ᳬ��������Ҳ����˵�����ͨ�����������ܹ���ʶ�κ�һ��İ���ˡ�����ͼ1��ʾ��
//
//
//ͼ1 ���ȿռ�ʾ��ͼ
//�����ȿռ䡱������Ȼ�õ��㷺����ͬ���������ڵõ�Խ��Խ���Ӧ�á�������ʮ��������ͼ��֤�������ʼ����������ѧ��Ŭ��׷���Ŀ�ꡣȻ��������ʷ��ԭ���������о�����̫��ľ����Ժ����ѡ����ŵ����˵�������Ҫ�����ڵ绰�����š�΢���Լ��������ϼ�ʱͨ�ŵȹ��ߣ��ܹ������罻�����ϵ��һ�������Ѿ���ʹ�á����ȿռ䡱���۵���֤��Ϊ���ܡ�
//
//�������һ���罻����ͼ�������ÿ���ڵ������ϡ����ȿռ䡱���۵Ľ��ռ��������İٷֱȡ�
//
//�����ʽ:
//�����1�и����������������ֱ��ʾ�罻����ͼ�Ľ����N��1<N��10
//?4
//?? ����ʾ������������M����33��N����ʾ�罻��ϵ����������M�ж�ӦM���ߣ�ÿ�и���һ�����������ֱ��Ǹ�����ֱ����ͨ���������ı�ţ��ڵ��1��N��ţ���
//
//�����ʽ:
//��ÿ����������ý����벻����6�Ľ����ռ��������İٷֱȣ���ȷ��С�����2λ��ÿ����ڵ����һ�У���ʽΪ�������:���ո񣩰ٷֱ�%����
//
//��������:
//10 9
//1 2
//2 3
//3 4
//4 5
//5 6
//6 7
//7 8
//8 9
//9 10
//�������:
//1: 70.00%
//2: 80.00%
//3: 90.00%
//4: 100.00%
//5: 100.00%
//6: 100.00%
//7: 100.00%
//8: 90.00%
//9: 80.00%
//10: 70.00%

#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
struct Node{
    int Vertex;
    PtrToNode Next;
};
PtrToNode CreateNode(int V);


typedef struct GraphRecord * GRAPH;
struct GraphRecord{
    int NumVertices;
    PtrToNode* AdjLists;
};
//create empty graph
GRAPH CreateGraph(int NV);
void AddEdge(GRAPH G, int src, int dest);
void PrintGraph(GRAPH G);
void BFS(GRAPH G, int v, int NV, int* Degrees, int DegLimit);


int SumDegLimit(int NV, int* Degrees, int DegLimit){
	int sum = 0;
	for( int i = 0; i < NV; i++){
		if(Degrees[i]>=0 && Degrees[i]<=DegLimit ) sum++;
	};
	return sum;
}




int main()
{   //freopen("6.3.txt","r",stdin);
	int NV,NE;
	scanf("%d %d\n",&NV,&NE);
    GRAPH G = CreateGraph(NV);
    int src,dest;
    for(int i = 0; i< NE;i++){
    	scanf("%d %d\n",&src,&dest);
    	AddEdge(G, src-1, dest-1);
	}
//    AddEdge(G, 0, 1);
//    AddEdge(G, 0, 2);
//    AddEdge(G, 1, 2);
//    AddEdge(G, 1, 4);
//    AddEdge(G, 1, 3);
//    AddEdge(G, 2, 4);
//    AddEdge(G, 3, 4);
//    AddEdge(G, 4, 6);
//    AddEdge(G, 5, 1);
//    AddEdge(G, 5, 6);
 
    //PrintGraph(G);

 	int Degrees[NV];
 	for(int v =0;v<NV;v++){
 		for(int i=0;i<NV;i++) Degrees[i]=-1;
	 	BFS(G, v, NV, Degrees, 6);
	// 	printf("\n");
	// 	for(int i=0;i<NV;i++) printf("%d %d ;",i,Degrees[i]);
		printf("%d: %.2f%%\n",v+1,(float)SumDegLimit(NV, Degrees, 6)/NV * 100);
	 }
    return 0;
}


 PtrToNode CreateNode(int V){
	PtrToNode NewNode = malloc(sizeof(struct Node));
	NewNode->Vertex = V;
	NewNode->Next   = NULL;
	return NewNode;
}

GRAPH CreateGraph(int NV){
	GRAPH G = malloc(sizeof(struct GraphRecord));
	G->NumVertices = NV;
	G->AdjLists = malloc(NV * sizeof(PtrToNode));
	
	for(int i = 0; i<NV;i++){
		G->AdjLists[i] = NULL;
	}
	return G;
}
 
void AddEdge(GRAPH G, int src, int dest){
	// Add edge from src to dest
	PtrToNode P1 =  CreateNode(src);
	P1->Next = G->AdjLists[dest];
	G->AdjLists[dest] = P1;
	// Add edge from dest to src
	PtrToNode P2 =  CreateNode(dest);
	P2->Next = G->AdjLists[src];
	G->AdjLists[src] = P2;
}

void PrintGraph(GRAPH G){
	for(int v=0;v < G->NumVertices; v++){
		PtrToNode tmp = G->AdjLists[v];
		printf("Adjacency list of vertex %d\n ", v);	
		while(tmp){
			printf("%d -> ", tmp->Vertex);
			tmp = tmp->Next;
		}
		printf("NULL");
		printf("\n");
	}
}

void BFS(GRAPH G, int v, int NV, int* Degrees, int DegLimit){
	int Queue[NV];
	int lo=0;
	int hi=0;
	Degrees[v] = 0;
	Queue[hi++] = v;//enqueue first vertex
	int u;
	while(lo!=hi){
		
		u = Queue[lo];//dequeue one vertex
		lo = lo +1;
		PtrToNode tmp = G->AdjLists[u];
		while(tmp){
			if( -1 == Degrees[tmp->Vertex]){
				//degree = degree of previous vertex + 1;
				Degrees[tmp->Vertex] = Degrees[u] + 1;
				//only traverse vertices with degree less than limit
				if(Degrees[tmp->Vertex]<= DegLimit - 1){
					Queue[hi] = tmp->Vertex;
					hi = hi +1;
				}
			}
			tmp = tmp->Next;
		}
	}
}
