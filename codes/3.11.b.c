#include <stdio.h>
#include <stdlib.h>
#define MAX_SEQ_LEN 20
#define ERROR '!'
typedef char ElemType;
typedef enum{false, true} bool;
typedef struct{
    ElemType *data; /*˳��ջ*/
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
char Compare(char first, char second){ /*firstΪջ��Ԫ�أ�secondΪջ��Ԫ��*/
    if(first=='#'){
        if(second==')')
            return ERROR;
        else
            return '<'; /*ѹ��ջ�ף�Ϊջ�ձ�־�����ȼ����*/
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
    else if(first=='('){ /*�����ŵ����ȼ����������󣬵������ң�����������*/
        if(second==')')
            return '=';
        else
            return '<';
    }
    else{ /*�����ŵȲ�������ջ*/
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
    Push(S, '#'); /*ѹ��ջ����Ϊջ�ձ�־*/
    //seq[strlen(seq)] = '#'; /*�������н�����־*/
    i = 0;
    rstCnt = 0;
    while(seq[i]!='\0'){
        if(IsNumber(seq, i)){ /*Ϊ���֣����������������������Ƭ��*/
            while(IsNumber(seq, i)){
                if(seq[i]!='+') /*��������ǰ������*/
                    result[rstCnt++] = seq[i];
                i++; /*�˳�ʱiָ���������'\0'*/
            }
            i--; /*���while�����Լ�һ����*/
            result[rstCnt++] = '#'; /*׷�ӵ�λ�����*/
        }
        else{ /*Ϊ�����������ջ״̬������*/
            if( Compare(GetTop(S),seq[i]) == '<' ){ /*ջ�����ȼ��ߣ���ջ*/
                Push(S, seq[i]);
            }
            else if( Compare(GetTop(S),seq[i]) == '>' ){ /*ջ�����ȼ��ߣ��������*/
                while(Compare(GetTop(S),seq[i]) == '>'){
                    /*����������������ǰ���ȼ����ϵ�*/
                    result[rstCnt++] = Pop(S);
                    result[rstCnt++] = '#'; /*׷�ӵ�λ�����*/
                }
                if( Compare(GetTop(S),seq[i]) == '=' ){
                    Pop(S); /*���������ţ�����������*/
                }
                else
                    Push(S, seq[i]);
            }
            else{ /*ջ��ջ�����ȼ���ȣ�����������*/
                Pop(S);
            }
        }
        i++;
    }
    while(GetTop(S)!='#'){
        result[rstCnt++] = Pop(S);
        result[rstCnt++] = '#';
    }
    Pop(S); /*����ջ�׵ľ���*/
    result[--rstCnt] = '\0'; /*����ַ�����Ľ������*/
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
    //printf("111\n"); /*����ĩβ�Ƿ��ж���ո�*/

    return 0;
}
