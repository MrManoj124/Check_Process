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

/*#include <mpi.h>
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
		int rec_nums[4];
		int sum = 0;

		//Receive Array from process 0
		MPI_Recv(rec_nums, 1, MPI_INT, 1, 50, MPI_COMM_WORLD, &sta);
		printf("\n Process %d received from : \n ", pid);
		for (int i = 1; i < 4; i++)
		{
			printf("%d", rec_nums[i]);
			sum += rec_nums[i];
		}
		printf("\n Process %d Computed sum = %d", pid, sum);

		//Send sum back to Process 0
		MPI_Send(&sum, 1, MPI_INT, 1, 50, MPI_COMM_WORLD);
		printf("\n Process %d Calculated sum is = %d", pid, sum);
	}

	MPI_Finalize();
	return 0;
}
*/


//Start to practice with OnetoMany Operation
#include <mpi.h>
#include <stdio.h>

int main() {
	int np;
	int pid;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	if (pid == 0)
	{
		int num = 3;
		for (int i = 1; i < np; i++) {
			MPI_Send(&num, 1, MPI_INT, i, 50, MPI_COMM_WORLD);
		}
		printf("\n ")
	}

}