#include<string.h>
#include<mpi.h>
#include<stdio.h>
int main(){
    MPI_Init(NULL, NULL);
    
    int np;
    int pid;

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    


    MPI_Finalize();
    return 0;
}