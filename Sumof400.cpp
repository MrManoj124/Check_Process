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
        // printf("Hey Mano Let's Break it the whole Structure of Parallalism ...., Process id is  : %d \n ", pid);
   
        // Fill the array data on process 0 with meaningful values, for example: data[i] = i + 1 (so values 1, 2, 3, ..., N)
        // Initialise the data 
        for(int i=0; i<n; i++){
            data[i]=i+1;
        } 

        // send chunks to other process // Distribute the array evenly among all P processes using only MPI_Send
        for(int i=1; i<np; i++){
            MPI_Send(&data [i*local_n],local_n, MPI_INT,  i, 50, MPI_COMM_WORLD);
        }


        // Copy it's own chunk
        for(int i=0; i<local_n; i++){
            local_data[i] = data[i];
        }
    }
        else {
            MPI_Status sta;
            MPI_Recv(local_data, local_n, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
        }

        // Calculate the local sum 
        for(int i=0; i< local_n; i++) {
            local_sum += local_data[i];
        }


    // 2. Only process 0 (the root) creates a large 1D array of integers called data of size N, where N is perfectly divisible by P (N = 400)
    if(pid == 0){
         // Each process (including root) computes the sum of its local chunk (local_sum)
        int global_sum = local_sum;
        for(int i=1; i<np; i++){
            int temp;
            MPI_Status sta;

            //Process 0 receives all P local sums using MPI_Recv, adds them together to get the global sum, and prints
            MPI_Recv(&temp, 1, MPI_INT, i, 60, MPI_COMM_WORLD, &sta);
            global_sum += temp;
        }

        printf("Global sum %d \n ", global_sum);
    }
    else{
        // Every process sends its local_sum back to process 0 using MPI_Send (many-to-one pattern).
        MPI_send(&local_sum, 1, MPI_INT, 0, 60, MPI_COMM_WORLD);
    }


    MPI_Finalize();
}