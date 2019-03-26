#include <stdio.h>
int main(){
	int N;
	//freopen("3.4.txt","r",stdin);
	scanf("%d",&N);
	int i, A[N];
	for(i = 0; i<N;i++){
		scanf("%d",&A[i]);
	}
	int lo=0,hi=0,H =0,curLo=0,curHi=0,curH=0;
	for(i = 1; i<N;i++){
		if(A[i-1]<A[i]){//strictly increasing
			curHi = i;
			curH=curHi-curLo;
			//printf("%d %d %d\n",curLo,curHi,H);
			if(curH>H){
				lo = curLo;
				hi = curHi;
				H  = curH;
			}
		}
		else {
			curLo = curHi = i;
			//printf("%d %d %d\n",curLo,curHi,H);
			curH = 0;
		}
	}
	int flag = 0;
	for(i = lo; i<=hi;i++){
		if(!flag) {
				printf("%d",A[i]);
				flag =1;
			}
		else printf(" %d",A[i]);
	}
}
