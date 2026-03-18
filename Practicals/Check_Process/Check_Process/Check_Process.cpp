#include <mpi.h>
#include <stdio.h>
int main()
{
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	//printf("\n Hello world . . . \n My pid= %d \n No_of_process= %d", pid, np);

	/*if (pid == 0)
	{
		printf("\n Helllo World.... \n My Pid = %d \n  No_of_Process = %d", pid, np);
	}
	else if (pid == 1)
	{
		printf("\n Mr Manorooban \n My Pid = %d \n  No_of_Process = %d", pid, np);
	}
	else if (pid == 2)
	{
		printf("\n Start to Study Parallel \n My Pid = %d \n  No_of_Process = %d", pid, np);
	}
	else
	{
		printf("\n Computing. . . \n my pid= %d \n no_of_process= %d", pid, np);
	}
	*/
	MPI_Finalize();
	return 0;
}