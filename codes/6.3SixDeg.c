//06-图3 六度空间 （30 分）
//“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图1所示。
//
//
//图1 六度空间示意图
//“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。
//
//假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。
//
//输入格式:
//输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10
//?4
//?? ，表示人数）、边数M（≤33×N，表示社交关系数）。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。
//
//输出格式:
//对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。
//
//输入样例:
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
//输出样例:
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
