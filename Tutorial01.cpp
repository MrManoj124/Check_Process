#include<mpi.h>;
#include<sting.h>;
#include<stdio.h>;
int main(){
    int np, pid;

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    if(pid == 0){
        printf("Hey Mano Let's Break it the whole Structure of Parallalism ...., Process id is  : %d \n ", pid);
    }


    MPI_Finalise();
}