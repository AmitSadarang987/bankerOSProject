#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdbool.h>

//N  -> need matrix
//M  -> MAx matrix
//A  -> Allocation Matrix
//AV -> Available  Matrix
// W - work martix

pthread_t Ttid[10];

int ps;//process rank
int dc=0;
int ret;
int A[10][10];
int M[10][10];
int N[10][10];
int W[1][10];
int n,m,pid,ch;
int F[10],W[1][10];
int Pseq[10];

int counter=0;
int Tret;
int tA[10][10];
int tM[10][10];
int tN[10][10];
int tW[1][10];
int tn,tm,tpid,tch;
int tF[10],tW[1][10];
pthread_mutex_t lock;


void Mprint(int x[][10],int n,int m)
{
	int i,j;
	printf("\n");	
	
	for(i=0;i<m;i++)
	{
			printf("\tR%d",i);

	}
	
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",i); //P[i]
		for(j=0;j<m;j++)
		{
			printf("%d\t",x[i][j]);
		}
	}	
}

int main()
{
	printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
}
