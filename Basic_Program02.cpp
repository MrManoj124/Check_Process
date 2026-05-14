#include<mpi.h>
#include<stdio.h>

int main(){
    int np, pid;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status sta;

    if (pid == 0)
	{
		int Send_Num[5] = { 10,20,30,40,50 };
	}
    MPI_finalize();
    return 0;
}