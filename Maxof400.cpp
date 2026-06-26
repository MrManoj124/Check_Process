#include<mpi.h>;
#include<sting.h>;
#include<stdio.h>;

#define n = 400;
int main(){

    int np, pid;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    

    MPI_Finalize();
}