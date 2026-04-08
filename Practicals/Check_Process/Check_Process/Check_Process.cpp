/*#include <mpi.h>
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
	else if (pid == 1)
	{
		printf("\n Parallel Computing is for Storage efficiency  \n From = %d \n No_Of_Process is = %d", pid, np);
	}
	else if (pid == 2)
	{
		printf("\n Let's crack it  \n From = %d \n No_Of_Process is = %d", pid, np);
	}
	else
	{

		printf("\n crack it with MPI  \n From = %d \n No_Of_Process is = %d", pid, np);
	}

	MPI_Finalize();
	return 0;
}
*/

#include <mpi.h>
#include <stdio.h>
int main() {
	int pid;
	int np;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	MPI_Status sta;
	if (pid == 0)
	{
		int nums[] = { 2,4,5,3,6,7,8 };
		int sum_result;

		//send Array01 to Process 01
		MPI_Send(nums, 4, MPI_INT, 1, 50, MPI_COMM_WORLD);
		printf("\n Process id %d send an Array", pid);

		//Receive sum back from process 01
		MPI_Recv(&sum_result, 1, MPI_INT, 1, 50, MPI_COMM_WORLD, &sta);
		printf("\n Process %d Received sum = %d \n", pid, sum_result);
	}
	else if (pid == 1)
	{

	}

	MPI_Finalize();
	return 0;
}