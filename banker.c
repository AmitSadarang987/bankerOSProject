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


void accept(int A[][10],int N[][10],int M[10][10],int W[1][10],int *n,int *m)
{
	int i,j;
	printf("\n Enter total no. of processes in Multithread  : ");
	scanf("%d",n);
	printf("\n Enter total no. of resources : ");
	scanf("%d",m);
	for(i=0;i<*n;i++)
	{
		printf("\n Process %d\n",i+1);
		for(j=0;j<*m;j++){
			printf(" Allocation for resource %d : ",j+1);
			scanf("%d",&A[i][j]);
			printf(" Maximum for resource %d : ",j+1);
			scanf("%d",&M[i][j]);
		}
	}
	printf("\n Available resources : \n");
	for(i=0;i<*m;i++)
	{
		printf(" Resource %d : ",i+1);
		scanf("%d",&W[0][i]);
	}

	// CALCULATE NeeD of Process 
	for(i=0;i<*n;i++)
	{
		for(j=0;j<*m;j++)
		{
			N[i][j]=M[i][j]-A[i][j];
		}
	}

	//calling my function to print	
	printf("\n Allocation Matrix");
	Mprint(A,*n,*m);

	printf("\n\n Maximum Requirement Matrix");
	Mprint(M,*n,*m);

	printf("\n\n Need Matrix");
	Mprint(N,*n,*m);

}



int main()
{
	
	printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
	
	// ACCepting -> to taken the Argument value
	accept(A,N,M,W,&n,&m);



}
