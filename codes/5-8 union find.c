/*05-Ê÷8 File Transfer £¨25 ·Ö£©
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:
Each input file contains one test case. For each test case, the first line contains N (2¡ÜN¡Ü10
?4
?? ), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

I c1 c2  
where I stands for inputting a connection between c1 and c2; or

C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:
For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:
no
no
yes
There are 2 components.
Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:
no
no
yes
yes
The network is connected.*/

#include <stdio.h>
int * Nodes;



void Union(int i, int j){
	int r1 = FindRoot(i);
	int r2 = FindRoot(j);
	if(r1!=r2){
			if (Nodes[r1] <= Nodes[r2]) {
			Nodes[r1] += Nodes[r2];
			Nodes[r2]= r1;
		}
		else if (Nodes[r1] > Nodes[r2]) {
			Nodes[r2] += Nodes[r1];
			Nodes[r1]= r2;
		}
	}
	//otherwise they already connected nothing to do 
} 

int FindRoot(int i){
	if(Nodes[i]<0) return i;
	else{
		int i0 = i;
		int j;
		while(i>0){
			j = i;
			i = Nodes[i];
		}
		Nodes[i0] = j;
		return j;
	}
}

void Check(int i, int j){
	if(FindRoot(i)==FindRoot(j)) printf("yes\n");
	else printf("no\n");
}

void Findcomponents(int N){
	int i;
	int count = 0;
	for (i = 1;i<=N;i++){
		if(Nodes[i]<0) count++;
	}
	if (count == 1) printf( "The network is connected.");
	else printf("There are %d components.", count);
}

int main(){
	//freopen("5.8.txt","r",stdin);
	int N;
	scanf("%d\n",&N);
	int Size = N +1;
	Nodes = (int *) malloc(sizeof(int)*Size);
	Size;
	while(Size--){
		Nodes[Size] = -1;
	}
	char input ;
	scanf("%c", &input );
	int i,j;
	while(input!='S'){
		scanf(" %d %d\n",&i,&j);
//		printf("%c %d %d\n",input,i,j);
//		printf("%d %d\n",FindRoot(i),FindRoot(j));
		if(input=='C') Check(i,j);
		else if(input=='I') Union(i,j);
		scanf("%c", &input);
	}
	Findcomponents(N);
	
	  
}
