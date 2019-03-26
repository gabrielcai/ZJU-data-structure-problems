/*
99999
 9999
  999
   99
    9
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int item[100001];
int main()
{
    int A,N;
    int i;
    int sum_cur;
    int sum_prev;
    scanf("%d %d",&A,&N);
    if(N==0)
        printf("0\n");
    else{
    	sum_cur  = N*A;//last digit
    	sum_prev = 0;
        for(i=0;i<N;i++){
            item[i]= (sum_cur + sum_prev) % 10 ;
            //printf("%d",item[i]);
            sum_prev = (sum_cur + sum_prev - item[i])/10;
            sum_cur  = sum_cur -A;
        }  
      	if(sum_prev == 0){
      		for(i=N-1;i>=0;i--) printf("%d",item[i]);
		  }
		else{
			item[N]= sum_prev;
			for(i=N;i>=0;i--) printf("%d",item[i]);
		}
		
	 }
 
    return 0;
}

