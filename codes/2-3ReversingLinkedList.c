#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 100000
int main(){

    int Data[MAXSIZE+1];// use array to simulate linked list
    int Next[MAXSIZE+1];
    int N; // total number of entry
    int K; // reverse period
	int headAdd = 0;

	int i, Add;

//    FILE *myFile;
//    myFile = fopen("somenumbers.txt", "r");
//	fscanf(myFile, "%d", &headAdd);
//	fscanf(myFile, "%d", &N);
//	fscanf(myFile, "%d", &K);
//
//
//	for( i = 0; i < N; i++){
//		int Curr = -1; // save current add
//		fscanf(myFile, "%d", &Curr); 
//		fscanf(myFile, "%d", &Data[Curr]);
//		fscanf(myFile, "%d", &Next[Curr]);
//	}
	scanf("%d", &headAdd);
	scanf("%d", &N);
	scanf("%d", &K);

	for( i = 0; i < N; i++){
		int Curr = -1; // save current add
		scanf("%d", &Curr); 
		scanf("%d", &Data[Curr]);
		scanf("%d", &Next[Curr]);
	}
	
	//有多余结点不在链表上	,处理的话，怎么办？需要重新便利链表，得到N？
	N = 1;
	int Curr = headAdd;
	while(Next[Curr] != -1){
		Curr = Next[Curr];
		N++;
	} 
	int currPHeadAdd,prevPTailAdd, prevAdd,currAdd,nextAdd;
	int numPeriods = N/K;
	int j;//initialize the pointers;
	prevPTailAdd = -1;//prevPAdd is the add before the period, headAdd is head of linkedlist
	
	prevAdd  = -1;
	currAdd  = headAdd;
	for(j = 0; j < numPeriods ; j++){//loop to reverse the lists
        prevPTailAdd = currPHeadAdd;
		currPHeadAdd = currAdd;
		for(i = 0; i < K; i++){
			nextAdd = Next[currAdd];
			//printf("%d :%05d %05d %05d\n",j*K+i+1, prevAdd, currAdd, nextAdd);
			
			Next[currAdd] =  prevAdd;
			prevAdd = currAdd;
			currAdd = nextAdd;			
		}
		Next[currPHeadAdd] = currAdd;
		if(0 == j) headAdd = prevAdd;
		else     Next[prevPTailAdd] =  prevAdd; 

	}

	
	//print loop
	Add = headAdd;
	for(i = 0; i<N; i++)
	{   if(-1 == Next[Add]) {
		printf("%05d %d %d\n", Add, Data[Add], Next[Add]);
		break;
		}
		
        printf("%05d %d %05d\n", Add, Data[Add], Next[Add]);
        Add = Next[Add];
    }		
    return 0;
}

