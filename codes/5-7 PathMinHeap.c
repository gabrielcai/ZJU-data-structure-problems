/*05-树7 堆中的路径 （25 分）
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
输出样例:
24 23 10
46 23 10
26 10
*/
#include <stdio.h>
#include <limits.h>
#define ET int
#define ERROR INT_MIN
typedef struct HeapRecord *MinHeap;
struct HeapRecord{
	ET *Elements;
	int Size;
	int Capacity;
};

MinHeap Create(int MaxSize){
	MinHeap H = (MinHeap) malloc( sizeof(struct HeapRecord));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements = (ET *) malloc((MaxSize+1) * sizeof(ET));
	H->Elements[0] = INT_MIN;//sentienel
	return H;
}

int IsFull(MinHeap H){
	return (H->Size == H->Capacity)	;
}
int IsEmpty(MinHeap H){
	return (H->Size  == 0)	;
}

void Insert(MinHeap H, ET X){
	if(IsFull(H)) {
		printf("最小堆已满\n");
		return;
	}
	int i =  ++ H->Size;
	for( ;H->Elements[i/2]>X ; i/=2){
		H->Elements[i] = H->Elements[i/2];
	}
	H->Elements[i] = X;
}

ET Pop(MinHeap H){
	if(IsEmpty(H)) return ERROR;
	ET Min = H->Elements[1];
	int i = 1;
	ET tmp = H->Elements[H->Size--];//last element need to move up and percolate down
	int Parent, Child;
	for( Parent = 1; Parent * 2 <= H->Size; Parent = Child){
		Child = Parent * 2;
		if ((Child!= H->Size)&&(H->Elements[Child] > H->Elements[Child+1])) 
			Child ++;//child point to the child with smaller value
		if ( tmp <= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = tmp;
	return Min;
}


ET Top(MinHeap H){
	if(!IsEmpty(H)) return H->Elements[1];
	else return ERROR;
}

void Print(MinHeap H){
	int N = H->Size;
	int i = 1;
	while(N--) printf("%d ",H->Elements[i++]);
	printf("\n");
}
int flag = 1;

void PrintPta(ET X){
	if(flag){
		printf("%d",X);
		flag = 0;
	}
	else printf(" %d",X);
}

void PrintPath(MinHeap H, int i){
	while( i >= 1) {
		PrintPta(H->Elements[i]);
		i /= 2;
	} 
}
int main(){
	freopen("5.7.txt","r",stdin);
	int N,M;
	scanf("%d %d\n",&N,&M);
	MinHeap H = Create(N);
	int i ;
	ET X;
	for(i = 0;i<N;i++){
		scanf("%d",&X);
		//printf("%d ",X);
		Insert(H,X);	
	}
	int Index[M];
	for(i = 0;i<M;i++){
		scanf("%d",Index+i);
			PrintPath(H,Index[i]);
		printf("\n");
		flag = 1;	
	}
	
}
