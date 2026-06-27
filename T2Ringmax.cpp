#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(){
    int np,pid;

    MPI_Comm_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    MPI_Status sta;
    int sum;

    if(pid == 0){
        sum = 0;
        MPI_Send(&sum, 1, MPI_INT, 1, 20, MPI_COMM_WORLD);
        MPI_Recv(&sum, 1, MPI_INT, np-1, 20, MPI_COMM_WORLD, &sta);
        printf("Process %d Final Ring sum %d \n", pid, sum);
    }
    else{

        MPI_Recv(&sum, 1, MPI_INT, pid - 1, 20, MPI_COMM_WORLD, &sta);
        sum += pid;
        printf("Process %d send the sum %d \n", pid, sum);
        MPI_Send(&sum, 1, MPI_INT, (pid+1)%np, 20, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}