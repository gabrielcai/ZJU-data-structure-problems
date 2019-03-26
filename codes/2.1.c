#include<stdio.h>
int  main()//四种运算符的优先级相同!!!
{
    int  a,b;
    char  c;
    scanf("%d",&a);
    scanf("%c",&c);
    while(c!='=')
  {
    scanf("%d",&b);
    if(c=='+')  a=a+b;
    else  if(c=='-')  a=a-b;
    else  if(c=='*')  a=a*b;
    else  if(c=='/')
    {
      if(b==0)
      {
        printf("ERROR");
        return  0;
      }
      else
      a=a/b;
    }
    else
    {
      printf("ERROR");
      return  0;
    }
    scanf("%c",&c);
  }
  printf("%d",a);
  return  0;
}

