// Program 03 Execution
/* PID 0 has an array of integer values, It should send the array to pid 1 and 
pid 1 should receive the values and find the sum
*/

#include<mpi.h>
#include<stdio.h>
#include<string.h>
int main(){
    int np;
    int pid;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status sta;
    if(pid == 0){
        int Send_Num[5] = {10,20,30,40,50};
        MPI_Send(Send_Num, 5, MPI_INT, 1, 50, MPI_COMM_WORLD);
        printf("My processor id is %d and I'm the sender. \n", pid);
        int recv;
        MPI_Recv(&recv, 1, MPI_INT, 1, 55, MPI_COMM_WORLD, &sta);
        printf("My processor id is %d and I receive the num from %d \n", pid, recv);  
    }
    if(pid == 1){
        int Recv_msg[5];
        int sum = 0;
        MPI_Recv(&Recv_msg, 5, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
        printf("My processor id is %d and I'm the receiver. \n", pid);
        printf("Received Messages are,");
        for(int i=0; i<5; i++){
            sum += Recv_msg[i];
        }
        MPI_Send(&sum, 1, _MPI_INT, 0, 55, MPI_COMM_WORLD);
    }
    
}