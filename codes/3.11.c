#include <stdio.h>
#include <string.h>
#define ET char
#define ERROR 'E'
#define MAXSIZE (50+1)
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
	S->Array = malloc(sizeof( ET)* S->Capacity);
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
	//printf("Push %c\n",X);
	return X;
}

ET Pop(Stack S){
	if(IsEmpty(S)) return ERROR;	
	else {
		ET X = S->Array[(S->TopOfStack)--];
		//printf("Pop %c\n",X);
		return X;
	}
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
		printf("%c ", S->Array[i]);
	}
	printf("\n");
	return;
}

//A summary of the rules follows:
//1.	Print operands as they arrive.
//2.	If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
//3.	If the incoming symbol is a left parenthesis, push it on the stack.
//4.	If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
//5.	If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
//6.	If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
//7.	If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
//8.	At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
int GetOrder(char c){
	switch(c){
			case '+' : return 1 ;break; 
			case '-' : return 1 ;break;
			case '*' : return 3 ;break;
			case '/' : return 3 ;break;
			case '(' : return 0 ;break;
			case ')' : return 0 ;break;
	}
}

int IsOp( char c){//is operation except (; 
	switch(c){
			case '+' : 
			case '-' : 
			case '*' : 
			case '/' : 
			case '(' : return 1 ;break;
			default  : return 0;
	}
}
int flag = 1;

void printPta(char c){
		if(flag) {
			printf("%c",c);
			flag = 0;
		}
		else  {
			printf(" ");	printf("%c",c);
		}
}
int main(){
//freopen("3.11.txt","r",stdin);
//	freopen("3.11.out.txt","w",stdout);
	Stack S = CreatStack(MAXSIZE);
	char *Input = malloc(sizeof(char)*MAXSIZE);
	
	gets(Input);
//	char  Input[MAXSIZE+1];
//	int i = 0;
//    int j = 0;
//    while(Input2[i]!='\0'){
//    	if(Input2[i]=='+'&&Input2[i+1]=='-') {
//    		//printf("%c\n",seq[i]);
//    		 Input[j++] = '-';
//    		i +=2;
//		}
//    	else if(Input2[i]=='-'&&Input2[i+1]=='+') {
//    		 Input[j++] = '-';
//    		i +=2;
//		}
//    	else  Input[j++] = Input2[i++];
//	}
//	 Input[j]= '\0';
int i;
	int N = strlen(Input);
	char *Output = malloc(sizeof(char)*N);
	for(i = 0;i<N;i++){
		char tmp = Input[i];
		switch(tmp){
			case '+' : if(i==0||(i>0&&IsOp(Input[i-1]))) break; 
			case '-' : if(i==0||(i>0&&IsOp(Input[i-1]))) {
							printf("%c",tmp) ; 
							break;
						}
			case '*' : 
			case '/' :
					if (IsEmpty(S)) Push(S,tmp);
					else {
						while (GetOrder(Top(S))>=GetOrder(tmp) &&!IsEmpty(S)&& Top(S)!='('){
							//弹出所有优先级大于或者等于该运算符的栈顶元素,直到'('或栈为空，
							//然后将该运算符入栈 
							printPta(Pop(S)) ; 
						}
						Push(S,tmp);
					};
						break;
			case '(' : Push(S,tmp);break;
			case ')' : while (!IsEmpty(S) && Top(S)!='(') 
							printPta(Pop(S)); 
					   Pop(S);
					   break;
			default  :// printf("%d :\n",i);
					   printPta(tmp);
						while(Input[i+1]=='.'||(Input[i+1]>='0'&&Input[i+1]<='9')){//print floats
						tmp = Input[++i];
						printf("%c",tmp);	
						}		
		}
		
	}
	while(!IsEmpty(S)) printPta(Pop(S)); 
	return 0;	
}





