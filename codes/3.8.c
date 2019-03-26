#include <stdio.h>
#include <string.h>
//************* table of symbols
//"/*" = 1
//"*/" = -1
//(	 = 2
//)	 = -2
//[	 = 3
//]	 = -3
//{	 = 4
//}	 = -4
//*************
#define MAXSIZE 105
#define ET int
#define ERROR 0
typedef struct StackRecord *Stack;
struct StackRecord{
	ET * Array;
	int TopOfStack;
} ;

Stack CreatStack(){
	Stack S = (Stack) malloc( sizeof(struct StackRecord ));
	S->TopOfStack = -1;
	S->Array = malloc(sizeof( ET)*MAXSIZE);
	return S;
}
int IsEmpty(Stack S){
	return S->TopOfStack == -1;
} 

void Push(Stack S, ET X){
	S->Array[++(S->TopOfStack)] = X;
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

int PushOp(char s[], Stack S){
	int Op;
	int N = strlen(s);
	int i;
	for(i=0;i<N;i++){
		if (s[i] 	  == '/'){
			if((i+1<N)&&(s[i+1]=='*')) {
			Push(S, 1);
			i++;
			} 
		} 
		else if (s[i] == '*'){
			if ((i+1<N)&&(s[i+1]=='/')) {
			Push(S, -1);
			i++;
			}
		} 
		else if (s[i] == '(') Push(S, 2);
		else if (s[i] == ')') Push(S, -2);
		else if (s[i] == '[') Push(S, 3);
		else if (s[i] == ']') Push(S, -3);
		else if (s[i] == '{') Push(S, 4);
		else if (s[i] == '}') Push(S, -4);
	}            
}

int CheckOp(Stack S){
	if(IsEmpty(S)) {
		printf("Null Stack\n");
		return 0;
	}
	int i;
	Stack T = CreatStack();
	for(i = 0; i<= S->TopOfStack;i++){
		if(S->Array[i]>0) Push(T,S->Array[i]);
		else  if (Top(T)== -1*S->Array[i]) {
			Pop(T);
		} else {
			if (IsEmpty(T)) return S->Array[i];
			else return Top(T);
		} 
	}
	if (!IsEmpty(T)) return S->Array[0];
	//if (!IsEmpty(T)) return S->Array[i];
	//printf("\n");
	return 0;
}

void PrintWarning(int i){
	switch(i){
	
	case 1 :    printf("NO\n/*-?\n" ); break;
	case 2 :    printf("NO\n(-?\n"   ); break;
	case 3 :    printf("NO\n[-?\n"   ); break;
	case 4 :    printf("NO\n{-?\n"   ); break;
	case 0 :    printf("YES"   ); 	    break;
	case -1:     printf("NO\n?-*/" ) ; break;
	case -2:     printf("NO\n?-)"	) ; break;
	case -3:     printf("NO\n?-]"	) ; break;
	case -4:     printf("NO\n?-}"	) ; break;
	}
}
int main(){
	char s[1000+5];
	//freopen("3.8.txt","r",stdin);
	int i = 0;
	Stack S = CreatStack();
	for(scanf("%s",&s),getchar(); s[0]!='.'; scanf("%s",&s)){
		PushOp(s, S);
		//printf("%s",s);
		
	}
	//Print(S);
	PrintWarning(CheckOp(S) );
	return 0;
}
