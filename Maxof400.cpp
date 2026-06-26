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

    if(pid == 0){
        int global_max = local_max;
        for(int i=1; i<np; i++){
            int temp;
            MPI Status sta;
            MPI_Recv(&temp, 1, MPI_INT, i, 60, MPI_COMM_WORLD, &sta);

            if(temp > global_max){
                global_max = temp;
            }
        }
        printf("Maximum Number is %d \n", global_max);
    }
        else{
            MPI_Send(&local_max, 1, MPI_INT, 0, 60, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
}