#include<mpi.h>;
#include<sting.h>;
#include<stdio.h>;
int main(){
    int np, pid;

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int data[n];
    int local_data[n];
    int local_sum=0;

    int local_n = n/np;

    // 1. The program is run with P processes (P ≥ 2).
    if(pid == 0){
        printf("Hey Mano Let's Break it the whole Structure of Parallalism ...., Process id is  : %d \n ", pid);
    }

    // 2. Only process 0 (the root) creates a large 1D array of integers called data of size N, where N is perfectly divisible by P (N = 400)
    if(pid == 0){
        printf("Hey Mano Let's Break it the whole Structure of Parallalism ...., Process id is  : %d \n ", pid);
    }


    MPI_Finalise();
}