#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(){
    int np,pid;

    MPI_Comm_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    MPI_Status sta;
    int value;

    if(pid == 0){
        value = 100 ;
        MPI_Send(&value, 1, MPI_INT, 0, 50, MPI_COMM_WORLD);
        MPI_Recv(&value, 1, MPI_INT, np-1, 50, MPI_COMM_WORLD, &sta);
        printf("Process %d Received final value : %d \n ", pid, value);
    }
    else{
        MPI_Recv(&value, 1, MPI_INT, pid-1, 50, MPI_COMM_WORLD, &sta);
        prinf("Process %d received value : %d \n", pid, value);
        MPI_Send(&value, 1, MPI_INT, (pid+1)%np, 50, MPI_COMM_WORLD);
    }


    MPI_Finalize();
}