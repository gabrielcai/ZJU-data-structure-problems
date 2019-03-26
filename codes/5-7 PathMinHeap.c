/*05-��7 ���е�·�� ��25 �֣�
��һϵ�и������ֲ���һ����ʼΪ�յ�С����H[]����������������±�i����ӡ��H[i]��������·����
�����ʽ:
ÿ����Ե�1�а���2��������N��M(��1000)���ֱ��ǲ���Ԫ�صĸ������Լ���Ҫ��ӡ��·����������һ�и�������[-10000, 10000]�ڵ�N��Ҫ������һ����ʼΪ�յ�С���ѵ����������һ�и���M���±ꡣ

�����ʽ:
�������и�����ÿ���±�i����һ���������H[i]��������·���ϵ����ݡ����ּ���1���ո�ָ�����ĩ�����ж���ո�

��������:
5 3
46 23 26 24 10
5 4 3
�������:
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
		printf("��С������\n");
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
