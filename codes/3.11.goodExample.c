#include<stdio.h>
#include<stack>
#include<ctype.h>
using namespace std;
int p[300];
int Priority(char a,char b){//判断优先级 
    if(a=='(')return 0;
    if(p[a]<p[b])return 0;
    if(p[a]>=p[b])return 1;
}
int main(){
    char s[30],ans[60],tmp[60];
    int i;
    stack<char> st;//栈，用来存运算符 
    p['+']=p['-']=1;//设置优先级 
    p['*']=p['/']=2;
    while(scanf("%s",s)!=EOF){
        int j=0,k=0;//j：答案的指针；k：标记 
        for(i=0;s[i];i++){
            if(s[i]=='(')//左括号直接进栈 
                st.push(s[i]);
            else if(s[i]==')'){//将左括号后边的符号依次输出 
                if(k){
                    ans[j++]=' ';
                    k=0;
                }
                while(st.top()!='('){
                    ans[j++]=st.top();
                    ans[j++]=' ';
                    st.pop();
                }
                st.pop();//删除左括号 
            }
            else if(s[i]>='0'&&s[i]<='9'||s[i]=='.'){//数字，包括小数 
                ans[j++]=s[i];
                k=1;
            }
            else{// +-*/ 
                if(k){//如果k==1，说明前面有数字，添加一个空格，并重置k 
                    ans[j++]=' ';
                    k=0;
                }
                if((s[i]=='+'||s[i]=='-')&&i==0){//正负号 1
                    if(s[i]=='-')
                        ans[j++]=s[i];
                    continue;
                }
                if((s[i]=='+'||s[i]=='-')&&i!=0&&s[i-1]=='('){//正负号 2 
                    if(s[i]=='-')    ans[j++]=s[i];
                    st.pop();
                    while(s[++i]!=')'){//这里的右括号要特殊处理 
                        ans[j++]=s[i];
                    }
                    ans[j++]=' ';
                    continue;
                }
                while(!st.empty()&&Priority(st.top(),s[i])){//弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈 
                    ans[j++]=st.top();
                    ans[j++]=' ';
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        if(k){
            ans[j++]=' ';
            k=0;
        }
        while(!st.empty()){//最后弹出所有运算符 
            ans[j++]=st.top();
            ans[j++]=' ';
            st.pop();
        }
        ans[j-1]=0;//将最后一个空格去掉 
        puts(ans);
    }
    return 0;
}
