// Program 03 Execution

// =====Marks Distribution and Total Marks Calculation using MPI====

// master can store main 5 subject marks of 5 students and send the marks to worker(pid == 1) and worker can calculate the total marks of each student and send it back to master.
// and master can print and store the total marks of each student with another array.
#include<mpi.h>
#include<string.h>
#include<stdio.h>
int main(){
    int pid;
    int np;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    if(pid  == 0){
        int marks[5][5]={{84,50,95,60,84},
                        {84,95,67,84,67},
                        {74,84,65,94,81},
                        {84,80,90,76,82},
                        {84,64,87,95,80}};
        
    MPI_Send(&marks, 25, MPI_INT, 1, 50, MPI_COMM_WORLD);
    printf("My Processor id is %d and I'm the master. \n", pid);
           
    int total_marks[5];
    MPI_Recv(total_marks, 5, MPI_INT, 1, 55, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Total marks of each student are, \n");
    for(int i=0; i<5; i++){
        printf("Student %d : %d \n", i+1, total_marks[i]);
    }

    if(pid == 1){
        int recv_marks[5][5];
        MPI_Recv(&recv_marks, 25, MPI_INT, 0, 50, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("My Processor id is %d and I'm the worker. \n", pid);

        int total_marks[5];
        for(int i=0; i<5; i++){
            total_marks[i]=0;
            for(int j=0; j<5; j++){
                total_marks[i] += recv_marks[i][j];
            }
        }
        MPI_Send();
    }

}
                    
    MPI_Finalize();
    return 0;
}






/* PID 0 has an array of integer values, It should send the array to pid 1 and 
pid 1 should receive the values and find the sum
*/
/* 
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
        MPI_Send(&sum, 1, MPI_INT, 0, 55, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
*/