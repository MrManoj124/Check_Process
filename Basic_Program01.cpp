#include<mpi.h>
#include<stdio.h>

int main(){
    int np, pid;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status sta;
    
    // Check the even numbers from the master process and send it to slave 
    if(pid == 0){
        int Even_numbers[10];
        for(int i=0; i<10; i++){
            Even_numbers[i] = 2*i;
        }
        MPI_Send(Even_numbers, 10, MPI_INT, 1, 50, MPI_COMM_WORLD);
        printf("Process %d send even numbers to process 1 \n", pid);
       
    }

    MPI_finalize();
    return 0;
}

//printf("Hello world from process %d of %d \n", pid, np);

// 
/*Send and receive messages through MPI_Send and MPI_Recv
    if(pid == 0){
        int data = 100;
        MPI_Send(&data, 1, MPI_INT, 1, 50, MPI_COMM_WORLD);
        printf("Process %d send data %d to process 1 \n", pid, data);
    }
    else if(pid ==1){
        MPI_Recv(&data, 1, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
        printf("Process %d receive data %d from process 0 \n", pid, data);
    }
    */