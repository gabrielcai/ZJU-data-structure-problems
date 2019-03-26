//06-Í¼2 Saving James Bond - Easy Version £¨25 ·Ö£©
//This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).
//
//Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the diameter of 15. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.
//
//Input Specification:
//Each input file contains one test case. Each case starts with a line containing two positive integers N (¡Ü100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.
//
//Output Specification:
//For each test case, print in a line "Yes" if James can escape, or "No" if not.
//
//Sample Input 1:
//14 20
//25 -15
//-25 28
//8 49
//29 15
//-35 -2
//5 28
//27 -29
//-8 -28
//-20 -35
//-25 -20
//-13 29
//-30 15
//-35 40
//12 12
//Sample Output 1:
//Yes
//Sample Input 2:
//4 13
//-12 12
//12 12
//-12 -12
//12 -12
//Sample Output 2:
//No

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100
#define RIsland 15

//test whether Node N is connected to Node N+1?
//0....N-1  is N crocdiles, Node N is JB,Node N+1 is the bank
void DFS(int n, int N, int** Edges, int* IsVisited){
	IsVisited[n] = 1;
	for(int i=0;i<N+2;i++){
			if(Edges[n][i]==1 && !IsVisited[i])
				DFS(i,N,Edges,IsVisited);
	} 
}

double Dist(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

int main(){
	freopen("6.2JB.txt","r",stdin);
	int N,Jump;
	scanf("%d %d\n",&N,&Jump);
	if(Jump>=35) {
		printf("Yes");
		return 0; 
	}
	int** Edges= (int **)malloc((N+2)*sizeof(int *));
	for(int i = 0;i<N+2;i++){
		Edges[i]= (int *)malloc((N+2)*sizeof(int ));
	}//0....N-1  is N crocdiles, Node N is JB,Node N+1 is the bank
	int XArray[N];//the bank has no coordinates
	int YArray[N];
	for(int i=0; i<N; i++){  
		scanf("%d %d\n",&XArray[i],&YArray[i]);
	}
	for(int i = 0;i<N+2;i++){
		for(int j = 0; j<N+2;j++) Edges[i][j]=0;
	} 
	for(int i=0; i<N; i++){
		if (Dist(XArray[i],YArray[i],0,0) <= (Jump+RIsland)){
			Edges[i][N]=1;
			Edges[N][i]=1;
			}
		if( XArray[i]>=(50-Jump)  || XArray[i]<=(-50+Jump) ||YArray[i]>=(50-Jump)||YArray[i]<=(-50+Jump)
		   || Dist(XArray[i],YArray[i],50,50)<=Jump|| Dist(XArray[i],YArray[i],-50,50)<=Jump|| Dist(XArray[i],YArray[i],50,-50)<=Jump
		   || Dist(XArray[i],YArray[i],-50,-50)<=Jump){
		   	Edges[i][N+1]=1;
			Edges[N+1][i]=1;
		   }
		for(int j=i+1;j<N;j++){
			if(Dist(XArray[i],YArray[i],XArray[j],YArray[j])<=Jump){
				Edges[i][j]=Edges[j][i]=1;
			}
		}
	}
	int IsVisited[N+2]; 
	for(int i = 0;i<N+2;i++) IsVisited[i]=0;
	DFS(N,N+2,Edges,IsVisited);
	
	if (IsVisited[N+1]) printf("Yes");
	else printf("No");
	return 0;
}
