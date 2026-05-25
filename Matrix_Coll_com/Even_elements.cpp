#include<string.h>
#include<mpi.h>
#include<stdio.h>

int main(){
    int pid;
    int np;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_Rank(MPI_COMM_WORLD, &pid);

    // Initializes the array in master process
    if(pid == 0){

    }

    MPI_Finalize();
    return 0;
}