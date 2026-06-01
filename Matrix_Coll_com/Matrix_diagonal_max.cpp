#include<string.h>
#include<mpi.h>
#include<stdio.h>
int main(){
    MPI_Init(NULL, NULL);
    
    int np;
    int pid;

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int primary_Element=0;
    int secondary_Element=0;

    int A[4][4];
    int row[4];

    a. Processor 0 initializes the following matrix A of size 4 × 4.
    if (pid == 0){
        int tempA[4][4]={2, 5, 8, 11},
                          {14, 17, 20, 23},
                          {26, 29, 32, 35},
                          {38, 41, 44, 47}};

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                A[i][j]=tempA[i][j];
            }
        }
    }



    b. Distribute rows among processors using MPI_Scatter
    MPI_Scatter(A, 4, MPI_INT, row, 4, MPI_INT, 0, MPI_COMM_WORLD);

    


    ii. Secondary diagonal element

    d. Use MPI_Reduce to determine:
    i. Maximum primary diagonal element
    ii. Maximum secondary diagonal element

    e. Processor 0 should print both maximum values.

    MPI_Finalize();
    return 0;
}