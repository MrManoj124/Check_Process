#include<mpi.h>
#include<stdio.h>

int main(){
    int np, pid;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Status sta;

    // check the master process and 
    // send the prime numbers to the slave
    if(pid == 0){
        int Prime_numbers[10];
        int count = 0;
        for(int i=2; count<10; i++){
            bool isPrime = true;
            for(int j=2; j<=i/2; j++){
                if(i % j == 0){
                    isPrime = false;
                    break;
                }
            }
        }

        MPI_Send(Prime_numbers, 10, MPI_INT, 1, 50, MPI_COMM_WORLD);
        printf("Process %d send prime numbers to process 1 \n ", pid);
    }
    // get the Prime numbers from the master process and print it
    else if(pid == 1){
        int Prime_numbers[10];
        MPI_Recv(Prime_numbers, 10, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
        printf("Process %d receive prime numbers from process 0 and the prime numbers are : %d \n ", pid, Prime_numbers);
        
    }
    MPI_finalize();
    return 0;
}



/* 

if (pid == 0)
	{
		int Send_Num[5] = { 10,20,30,40,50 };
		MPI_Send(&Send_Num, 5, MPI_INT, 1, 50, MPI_COMM_WORLD);
		printf("My processor id is %d and I'm the sender. \n", pid);
	}
    if(pid == 1){
        int Recv_msg[5];
		int sum = 0;
        MPI_Recv(&Recv_msg, 5, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
        printf("My processor id is %d and I'm the receiver. \n", pid);
		printf("Received Messages are,");
		for(int i=0;i<5;i++)
		{
			printf("%d \n",Recv_msg[i]);
		}

*/