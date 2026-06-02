// One To Many Communication 01 .
/*Master should send a message to all other inter-connected processes*/
#include<mpi.h> // MPI header file
#include<stdio.h> // Standard I/O header file
#include<string.h> // String header file for string manipulation functions

int main(){

    MPI_Init(NULL, NULL); // Initialize the MPI environment
    int np; // Variable to store the number of processes
    int pid; // Variable to store the rank of the process

    MPI_Comm_size(MPI_COMM_WORLD, &np); // Get the total number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &pid); // Get the rank of the process
    MPI_Status sta;  // Variable to store the status of MPI operations 

    




    MPI_Finalize();  // Finalize the MPI environment
    return 0; // Return 0 to indicate successful execution
}