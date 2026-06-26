#include<mpi.h>;
#include<sting.h>;
#include<stdio.h>;

#define n = 400;
int main(){

    int np, pid;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int local_max;
    int data[n];
    int local_data[n];

    int local_n = n/np;
    if(pid == 0){
        for(int i=0; i<n; i++){
            data[i]=rand() % 1000;
        }

        for(int i=1; i<np; i++){
            MPI_Send(&data[i*local_n], local_n, MPI_INT, i, 50, MPI_COMM_WORLD);
        }

        for(int i=0; i<local_n; i++){
            local_data[i] = data[i];
        }
    }

    else{
        MPI_status sta;
        MPI_Recv(&local_data, local_n, 0, 50, MPI_INT, MPI_COMM_WORLD, &sta);
    }

    local_max = local_data[0];
    for(int i=1; i<local_n; i++){
        if(local_data[i]>local_max[i]);
    }

    

    MPI_Finalize();
}