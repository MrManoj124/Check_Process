#include<mpi.h>
#include<stdio.h>
#include<string>
int main(){
    int np;
    int pid;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int A[4][4];
    int row[4];

    a.Processor 0 initializes the following matrix A of size 4 x 4.
    if (pid ==0){
        int tempA[4][4] = {{12, 5, 18, 9},
                           {27, 14, 3, 20},
                           {8, 31, 16, 11},
                           {25, 7, 22, 4}};
        
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                A[i][j]=tempA[i][j];
            }
        }
    }

   b. Distribute rows equally among processors using MPI_Scatter.
   MPI_Scatter(A, 4, MPI_INT, row, 4, MPI_INT, 0, MPI_COMM_WORLD);

   c. Each processor should sort its assigned row in ascending order.
   int temp;
   for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if(row[j] > row[j+1]){
                temp = row[j];
                row[j]=row[j+1];
                row[j+1]=temp;
            }
        }
   }



   d. Use MPI_Gather to collect the sorted rows into Matrix B.


   e. Use MPI_Reduce to determine the maximum element in the sorted matrix.


   f. Processor 0 should display:
        i. Sorted matrix
        ii. Maximum matrix element


    MPI_Finalize();
    return 0;
}