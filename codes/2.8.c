#include <stdio.h>
#define MAXN 100 


void permute(int B[],int IsUsed[],int lv, int N){
	int i;
	if(lv==N) 
		{for(i=0;i<N;i++)  printf("%d",B[i]);
		 printf("\n");
		 return;
		}
	else{
		for(i=0;i<N;i++){
			if(!IsUsed[i]) {
				B[lv]=i+1;
				IsUsed[i]=1;
				permute(B,IsUsed,lv+1,N);
				IsUsed[i]=0;
			}
		}	
	} 
}

int main(){
	int N;
	scanf("%d",&N);
	int i;
	int B[N],IsUsed[N];
	for(i=0;i<N;i++) 
			IsUsed[i]=B[i]=0;
	permute(B,IsUsed,0,N);
	return 0;
}
