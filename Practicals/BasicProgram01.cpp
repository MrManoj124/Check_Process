#include <mpi.h>
#include <stdio.h>

int main() {
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status sta;



	MPI_Finalize();
	return 0;

}