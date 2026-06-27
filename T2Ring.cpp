#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(){
    int np,pid;

    MPI_Comm_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    if(pid == 0){

    }


    MPI_Finalize();
}