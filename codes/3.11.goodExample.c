#include<stdio.h>
#include<stack>
#include<ctype.h>
using namespace std;
int p[300];
int Priority(char a,char b){//�ж����ȼ� 
    if(a=='(')return 0;
    if(p[a]<p[b])return 0;
    if(p[a]>=p[b])return 1;
}
int main(){
    char s[30],ans[60],tmp[60];
    int i;
    stack<char> st;//ջ������������� 
    p['+']=p['-']=1;//�������ȼ� 
    p['*']=p['/']=2;
    while(scanf("%s",s)!=EOF){
        int j=0,k=0;//j���𰸵�ָ�룻k����� 
        for(i=0;s[i];i++){
            if(s[i]=='(')//������ֱ�ӽ�ջ 
                st.push(s[i]);
            else if(s[i]==')'){//�������ź�ߵķ���������� 
                if(k){
                    ans[j++]=' ';
                    k=0;
                }
                while(st.top()!='('){
                    ans[j++]=st.top();
                    ans[j++]=' ';
                    st.pop();
                }
                st.pop();//ɾ�������� 
            }
            else if(s[i]>='0'&&s[i]<='9'||s[i]=='.'){//���֣�����С�� 
                ans[j++]=s[i];
                k=1;
            }
            else{// +-*/ 
                if(k){//���k==1��˵��ǰ�������֣����һ���ո񣬲�����k 
                    ans[j++]=' ';
                    k=0;
                }
                if((s[i]=='+'||s[i]=='-')&&i==0){//������ 1
                    if(s[i]=='-')
                        ans[j++]=s[i];
                    continue;
                }
                if((s[i]=='+'||s[i]=='-')&&i!=0&&s[i-1]=='('){//������ 2 
                    if(s[i]=='-')    ans[j++]=s[i];
                    st.pop();
                    while(s[++i]!=')'){//�����������Ҫ���⴦�� 
                        ans[j++]=s[i];
                    }
                    ans[j++]=' ';
                    continue;
                }
                while(!st.empty()&&Priority(st.top(),s[i])){//�����������ȼ����ڻ��ߵ��ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ 
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
        while(!st.empty()){//��󵯳���������� 
            ans[j++]=st.top();
            ans[j++]=' ';
            st.pop();
        }
        ans[j-1]=0;//�����һ���ո�ȥ�� 
        puts(ans);
    }
    return 0;
}
