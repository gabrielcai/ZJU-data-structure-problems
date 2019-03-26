#include <stdio.h>
int main(){
	int N,M;
	//freopen("2.2.txt","r",stdin);
	scanf("%d%d",&N,&M);
	M = M %N;
	int i,Buffer[M];
	int tmp;
	int flag = 0;
	for(i = 0; i<N;i++){
		if (i<M) scanf("%d",&Buffer[i]);
		else  {
			scanf("%d",&tmp);
			if(!flag) {
				printf("%d",tmp);
				flag =1;
			}
			else printf(" %d",tmp);
		}
	}
	for(i = 0; i<M;i++){
		printf(" %d",Buffer[i]);
	}
	return 0;
}
