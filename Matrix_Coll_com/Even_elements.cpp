#include<string.h>
#include<mpi.h>
#include<stdio.h>

int main(){
    int pid;
    int np;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_Rank(MPI_COMM_WORLD, &pid);

     /*
    2 5 8 11
    14 17 20 23
    26 29 32 35
    38 41 44 47
    */
   int RowA[4][4];

   int RowB[4];
   int localCount = 0;

   int gatheredcount[4];
   int totaleven = 0;

    // a. Processor 0 initializes the following matrix A of size 4 × 4
    if(pid == 0){
        int Arr[4][4]={{2, 5, 8, 11},
                        {14, 17, 20, 23},
                        {26, 29, 32, 35},
                        {38, 41, 44, 47}};

   // b. Distribute rows among processors using MPI_Scatter
        MPI_Scatter(Arr, 4, MPI_INT, RowA, 4, MPI_INT, 0, MPI_COMM_WORLD);



   // c. Each processor should count the number of even elements in its
       // row.
        for(int i=0; i<4; i++){
            if(RowA[i] % 2 == 0){
                localCount++;
            }
        }

   // d. Use MPI_Gather to collect local even counts.
        MPI_Gather(&localCount, 1, MPI_INT, gatheredCount, 1, MPI_INT, 0, MPI_COMM_WORLD);
  //  e. Use MPI_Reduce to calculate the total number of even elements
        MPI_Reduce(&localCount, &totaleven, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        
    // f. Processor 0 should display:
       // i. Local even counts
       // ii. Total even count
        if(pid == 0){
            printf("Local even counts from each processor : ");
            for(int i=0; i<np; i++){
                printf("%d ", gatheredCount[i]);
            }
            printf("\n Total even count : %d\n", totaleven);
        }
    MPI_Finalize();
    return 0;
}