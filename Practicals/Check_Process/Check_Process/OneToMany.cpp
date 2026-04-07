#include <mpi.h>
#include <stdio.h>
int main()
{
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_Size(MPI_COMM_WORLD, &np);
	MPI_Comm_Rank(MPI_COMM_WORLD, &pid);
	printf("\n My name is Mr.Manorooban \n My pid is=%d, N0_Of _Process is =%d , pid, np");

	MPI_Finalize();
	return 0;
}