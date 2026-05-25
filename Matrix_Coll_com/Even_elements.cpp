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
        int Arr[4][4]={{2, 5, 8, 11},
                        {14, 17, 20, 23},
                        {26, 29, 32, 35},
                        {38, 41, 44, 47}};

    MPI_Finalize();
    return 0;
}