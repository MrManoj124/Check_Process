#include <mpi.h> 
#include <stdio.h> 
int main()
{
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);


	if (pid == 0)
	{
		int num = 400;
		MPI_Send(&num, 1, MPI_INT, 1, 50, MPI_COMM_WORLD);

		printf("\n Hello world 1 . . . \n My pid= %d \n No_of_process= %d", pid, np);
	}
	else
	{
		int rec_num;
		MPI_Recv(&rec_num,  1, MPI_INT, 0, 50,MPI_COMM_WORLD, &sta);
		printf("\n Hello world 2. . . \n My pid= %d \n No_of_process= %d \n Recieved Number is %d", pid, np, rec_num);
	}

	MPI_Finalize();
	return 0;
}
