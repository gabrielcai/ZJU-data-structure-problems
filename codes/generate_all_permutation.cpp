#include<iostream>
using namespace std;
int visit[100];//�����ж���������Ƿ񱻷��ʹ� �� visit[2]=1;˵������2�����ʹ� 
int a[100];//0-(n-1)������� 
void dfs(int level,int n)//��ȷ�� dfs 
{
    if(level==n)//��ֹ���� ,������� 
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0) //�ж�i�Ƿ񱻷��ʹ� 
        {
            visit[i]=1;//��ʶiΪ���� 
            a[level]=i;//i ��������ĵ�level��Ԫ���� 
            dfs(level+1,n);//�ݹ� 
            visit[i]=0;//�ݹ鷵��Ҳ����˵������������Ҫ�����ָ�ԭΪ���� 
        }
    }
}
int main()
{   int n;  
    cin>>n;
    dfs(0,n);//ǰ�߱�ʾĿǰ����ڼ������֣�n��Ϊ������������ 
    return 0;
}
