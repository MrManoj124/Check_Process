#include <mpi.h>
#include <stdio.h>

int main()
{
	int np;
	int pid;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	//printf("\n Mr Manorooban.... \n My pid = %d  \n No_Of_Process=%d", pid, np );

	if (pid == 0)
	{
		printf("\n Hey Guys let's study Parallal Computing  \n From = %d \n No_Of_Process is = %d", pid, np);
	}
	

	MPI_Finalize();
	return 0;
}