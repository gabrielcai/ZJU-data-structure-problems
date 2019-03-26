#include <stdio.h>
#include <stdlib.h>
#define MAX_SEQ_LEN 20
#define ERROR '!'
typedef char ElemType;
typedef enum{false, true} bool;
typedef struct{
    ElemType *data; /*顺序栈*/
    int top;
    int size;
}SNode, *Stack;

bool InitStack(Stack S){
    S->data = (ElemType *)malloc(MAX_SEQ_LEN*sizeof(ElemType));
    S->top = 0;
    S->size = MAX_SEQ_LEN;
    if(S->data!=NULL)
        return true;
    else
        return false;
}
bool Push(Stack S, ElemType e){
    if(S->top==S->size){
        printf("ERROR: fail to push!");
        return false;
    }
    else{
        S->data[S->top++] = e;
        return true;
    }
}
ElemType Pop(Stack S){
    if(S->top==0){
        printf("ERROR: fail to pop!");
        return ERROR;
    }
    else{
        return (S->data[--S->top]);
    }
}
ElemType GetTop(Stack S){
    if(S->top==0){
        printf("ERROR: fail to getTop!");
        return ERROR;
    }
    else{
        return (S->data[S->top-1]);
    }

}
char Compare(char first, char second){ /*first为栈顶元素，second为栈外元素*/
    if(first=='#'){
        if(second==')')
            return ERROR;
        else
            return '<'; /*压在栈底，为栈空标志，优先级最低*/
    }
    else if(first=='+' || first=='-'){
        if(second=='+' || second=='-' || second==')')
            return '>';
        else
            return '<';
    }
    else if(first=='*' || first=='/'){
        if(second=='+' || second=='-' || second=='*' || second=='/' || second==')')
            return '>';
        else
            return '<';
    }
    else if(first=='('){ /*左括号的优先级：高于其左，低于其右，等于右括号*/
        if(second==')')
            return '=';
        else
            return '<';
    }
    else{ /*右括号等不可能入栈*/
        printf("ERROR: invalid oprator!");
        return ERROR;
    }

}
bool IsNumber(char seq[], int i){
    if( (seq[i]>='0' && seq[i]<='9') || seq[i]=='.'){
        return true;
    }
    else if( (seq[i]=='+' || seq[i]=='-') && (seq[i-1]=='(' || i==0) ){
        return true;
    }
    else
        return false;
}
ElemType *inToSuf(char seq[]){
    int i, rstCnt;
    ElemType *result = (ElemType *)malloc( (2*MAX_SEQ_LEN+1)*sizeof(ElemType) );
    Stack S = (Stack)malloc(sizeof(SNode));
    InitStack(S);
    Push(S, '#'); /*压入栈底作为栈空标志*/
    //seq[strlen(seq)] = '#'; /*输入序列结束标志*/
    i = 0;
    rstCnt = 0;
    while(seq[i]!='\0'){
        if(IsNumber(seq, i)){ /*为数字，输出完整的连续数字数列片段*/
            while(IsNumber(seq, i)){
                if(seq[i]!='+') /*忽略数字前的正号*/
                    result[rstCnt++] = seq[i];
                i++; /*退出时i指向运算符或'\0'*/
            }
            i--; /*外层while已有自加一操作*/
            result[rstCnt++] = '#'; /*追加单位间隔符*/
        }
        else{ /*为运算符，依据栈状态而操作*/
            if( Compare(GetTop(S),seq[i]) == '<' ){ /*栈外优先级高，入栈*/
                Push(S, seq[i]);
            }
            else if( Compare(GetTop(S),seq[i]) == '>' ){ /*栈内优先级高，连续输出*/
                while(Compare(GetTop(S),seq[i]) == '>'){
                    /*右括号遇到左括号前优先级均较低*/
                    result[rstCnt++] = Pop(S);
                    result[rstCnt++] = '#'; /*追加单位间隔符*/
                }
                if( Compare(GetTop(S),seq[i]) == '=' ){
                    Pop(S); /*弹出左括号，忽视右括号*/
                }
                else
                    Push(S, seq[i]);
            }
            else{ /*栈内栈外优先级相等，弹出左括号*/
                Pop(S);
            }
        }
        i++;
    }
    while(GetTop(S)!='#'){
        result[rstCnt++] = Pop(S);
        result[rstCnt++] = '#';
    }
    Pop(S); /*弹出栈底的井号*/
    result[--rstCnt] = '\0'; /*结果字符数组的结束标记*/
    return result;
}
void prntSeq(ElemType result[]){
    int i=0;
    while(result[i]){
        if(result[i]!='#')
            printf("%c", result[i]);
        else
            printf(" ");
        i++;
    }
}
int main(void){
	freopen("3.11.txt","r",stdin);
//	freopen("3.11.out.txt","w",stdout);
    ElemType seq[MAX_SEQ_LEN+1], *result;
    gets(seq);
    int i = 0;
    char  inputs[MAX_SEQ_LEN+1];
    int j = 0;
    while(seq[i]!='\0'){
    	if(seq[i]=='+'&&seq[i+1]=='-') {
    		//printf("%c\n",seq[i]);
    		inputs[j++] = '-';
    		i +=2;
		}
    	else if(seq[i]=='-'&&seq[i+1]=='+') {
    		printf("%c\n",seq[i]);
    		inputs[j++] = '-';
    		i +=2;
		}
    	else inputs[j++] = seq[i++];
	}
	inputs[j]= '\0';

    result = inToSuf(inputs);
    prntSeq(result);
    //printf("111\n"); /*测试末尾是否有多余空格*/

    return 0;
}
