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

    int data[6]={10,20,30,40,50,60};

    if(pid == 0){
        for(int i=1; i<=5; i++){
            MPI_send(&data[i], 1, MPI_INT, i, 20, MPI_COMM_WORLD);
        }
        int sum1, sum2;
        MPI_Recv(&sum1, 1, MPI_INT, 1, 40, MPI_COMM_WORLD, &sta);
        MPI_Recv(&sum2, 1, MPI_INT, 3, 40, MPI_COMM_WORLD, &sta);
        int total = data[0]+sum1+sum2;
        printf("Final dum %d \n", total);
    }
    
    MPI_Finalize();
}