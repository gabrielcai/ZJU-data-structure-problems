#include <stdio.h>
#include <string.h>
#define ET int
#define ERROR 0
typedef struct StackRecord *Stack;
struct StackRecord{
	ET * Array;
	int TopOfStack;
	int Capacity;
} ;

Stack CreatStack(int C){
	Stack S = (Stack) malloc( sizeof(struct StackRecord ));
	S->TopOfStack = -1;
	S->Capacity = C;
	S->Array = malloc(sizeof( ET)*S->Capacity);
	return S;
}
int IsEmpty(Stack S){
	return S->TopOfStack == -1;
} 
int IsFull(Stack S){
	return S->TopOfStack == S->Capacity-1;
} 

ET Push(Stack S, ET X){
	if(IsFull( S))  return ERROR;
	else S->Array[++(S->TopOfStack)] = X;
	return X;
}

ET Pop(Stack S){
	if(IsEmpty(S)) return ERROR;	
	else 
		return S->Array[(S->TopOfStack)--]; 
}

ET Top(Stack S){
	if(IsEmpty(S)) return ERROR;	
	else 
		return S->Array[S->TopOfStack]; 
}

void Print(Stack S){
	if(IsEmpty(S)) {
		printf("Null Stack\n");
		return;
	}
	int i;
	for(i = 0; i<= S->TopOfStack;i++){
		printf("%d ", S->Array[i]);
	}
	printf("\n");
	return;
}

int main(){
	//freopen("3.9.txt","r",stdin);
	int N,Cap;
	int M;
	int i;
	int flag;
	char s[100];
	scanf("%d %d\n",&N,&Cap);
	while(N--){
		int flag = 1;
		Stack S = CreatStack(Cap);
		scanf("%s\n",&s);
		M = strlen(s);
		for(i=0;i<M;i++){
			if (s[i]=='S') flag *= Push(S,1);
			else flag *= Pop(S);
		}
		flag = flag* IsEmpty(S);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
