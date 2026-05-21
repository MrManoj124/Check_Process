
#include<mpi.h>
#include<stdio.h>
#include<string.h>
int main(){
    int pid;
    int np;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    // Initialize two 4x4 matrices in pid 0
    if(pid == 0){
        int MatA[4][4]={{25, 18, 12, 30},
                         {14, 28, 20, 16},
                         {35, 22, 10, 27},
                         {19, 24, 32, 15}};

        int MatB[4][4] = {{5, 8, 2, 10},
                           {4, 6, 12, 1},
                           {15, 7, 3, 9},
                           {8, 14, 11, 5}};

        // Distribute the one raw of both matrices to 4 processors Using MPI_Scatter
        int RowA[4], RowB[4];
        MPI_Scatter(MatA, 4, MPI_INT, RowA, 4, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(MatB, 4, MPI_INT, RowB, 4, MPI_INT, 0, MPI_COMM_WORLD);
        printf("My processor id is %d and I'm the master. \n", pid);
        printf("Received row from MatA : ");
        
    }

    MPI_Finalize();
    return 0;
}