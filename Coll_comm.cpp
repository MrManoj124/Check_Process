#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(){
    int np,pid;

    MPI_Comm_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    MPI_Status sta;
    int arr[4];

    if(pid == 0){
        for(int i=0; i<4; i++){
            arr[i]=(i+1)*2;
        }
        mul = 10;
    }
    int recv_val;

    MPI_Scatter(&arr, 1, MPI_INT, &recv_val, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Bcast(&mul, 1, MPI_INT, 0, MPI_COMM_WORLD);

    recv_val*=val;

    int result;
    MPI_Reduce(&recv_val, 1, MPI_INT, &result, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(pid == 0){
        printf("Results = %d \n", result);
    }


    MPI_Finalize();
}