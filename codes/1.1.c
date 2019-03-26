#include <stdio.h> 
int main(){
	int Max=0;
	int CurSum=0;
	int N;
	//freopen("1.1.txt","r",stdin);
	scanf("%d\n",&N);
	//printf("%d",N);
	int i, A[N];
	for(i = 0; i<N;i++){
		scanf("%d",&A[i]);
		if (CurSum < 0) CurSum = 0;
		CurSum += A[i];
		if  (CurSum> Max) Max = CurSum;
	}
	
	printf("%d",Max);
	return 0;
}
