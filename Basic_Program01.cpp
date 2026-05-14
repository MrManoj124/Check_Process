#include<mpi.h>
#include<stdio.h>

int main(){
    int np, pid;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status sta;
    
    // Send and receive messages through MPI_Send and MPI_Recv
    

    MPI_finalize();
    return 0;
}

//printf("Hello world from process %d of %d \n", pid, np);