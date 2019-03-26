#include<iostream>
using namespace std;
int visit[100];//用来判断这个数字是否被访问过 如 visit[2]=1;说明数字2被访问过 
int a[100];//0-(n-1)存放数字 
void dfs(int level,int n)//的确是 dfs 
{
    if(level==n)//终止条件 ,输出数组 
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
        if(visit[i]==0) //判断i是否被访问过 
        {
            visit[i]=1;//标识i为已用 
            a[level]=i;//i 放入数组的第level个元素中 
            dfs(level+1,n);//递归 
            visit[i]=0;//递归返回也就是说输出万数组后，需要将数字复原为可用 
        }
    }
}
int main()
{   int n;  
    cin>>n;
    dfs(0,n);//前者表示目前是填第几个数字，n则为所有数字数量 
    return 0;
}
