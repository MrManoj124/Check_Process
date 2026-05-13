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

	/*if (pid == 0)
	{
		int num = 3;
		for (int i = 1; i < np; i++) {
			MPI_Send(&num, 1, MPI_INT, i, 50, MPI_COMM_WORLD);
		}
		printf("\n Process %d sent the value = %d \n ", pid, num);
	}
	else {
		int DEC_NUM;
		MPI_Status status;

		MPI_Recv(&DEC_NUM, 1, MPI_INT, 0, 50, MPI_COMM_WORLD, &status);
		printf("\n Process %d Received the value = %d \n ", pid, DEC_NUM);
	}
	*/


	/*if (pid == 0)
	{
		int received_Number;
		MPI_Status status;
		for (int i = 1; i < np; i++) {
			MPI_Recv(&received_Number, 1, MPI_INT, i, 50, MPI_COMM_WORLD, &status);
			printf("\n Data Received %d from the process = %d \n", received_Number, i);
		}
	}
	else {
		int num = pid * 10; //each process send a different value 
		MPI_Send(&num, 1, MPI_INT, 1, 50, MPI_COMM_WORLD);
		printf("\n Process %d Sent the value = %d to process 0", pid, num);
	}*/

	MPI_Status sta;


	if (pid == 0)
	{
		int arr1[32] = { 45, 41, 92, 79, 11, 83, 97, 91, 98, 67, 53, 34, 68, 72, 76, 12, 78, 59, 64, 06, 89, 62, 26, 23, 17, 35, 36, 18, 25, 55, 43, 56 };
		int arr2[32] = { 05, 18, 96, 63, 23, 10, 42, 34, 58, 84, 35, 61, 51, 41, 01, 13,45, 22, 53, 44, 56, 96, 62, 71, 67, 72, 78, 46, 83, 91, 97, 98 };

		for (int i = 1; i < 4; i++)
			MPI_Send(&arr1, 32, MPI_INT, i, 50, MPI_COMM_WORLD);

		for (int i = 1; i < 4; i++) 
			MPI_Send(&arr2[i * 8], 8, MPI_INT, i, 55, MPI_COMM_WORLD);

		printf("\n Process %d Received : \n ", pid);

		for (int i = 0; i < 8; i++) {
			printf("%d", arr2[i]);
			printf("\n");
		}
		printf("\n");

		int master_count = 0;
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr2[j] == arr1[i])
				{
					master_count++;
					break;
				}
			}
		}

		printf("\n process %d , local_intersection=%d\n ", pid, master_count);
		printf("\n");

		int total_count = master_count, local_count;

		for (int i = 1; i < 4; i++)
		{
			MPI_Recv(&local_count, 1, MPI_INT, i, 60, MPI_COMM_WORLD, &sta);
			total_count = total_count + local_count;
		}

		float dice = (2.0 * total_count) / (32 / 32);
		printf("Dice Coefficeint = %3.f \n ", dice);
		printf("Similarity = %2.f%%\n", dice * 100);
		
	}
	else {

		int recv1[32];
		MPI_Recv(&recv1, 32, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);

		int recv2[8];
		MPI_Recv(&recv1, 8, MPI_INT, 0, 55, MPI_COMM_WORLD, &sta);

		printf("\n process %d Received : \n", pid);
		for (int i = 0; i < 8; i++)
		{
			printf("%d", recv2[i]);
			printf("\n");
		}

		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (recv2[j] == recv1[i]) {
					count++;
					break;
				}
			}
		}
		printf("Process %d localIntersection =%d \n ", pid, count);
		printf("\n");

		MPI_Send(&count, 1, MPI_INT, 0, 60, MPI_COMM_WORLD);

	}


	MPI_Finalize();
	return 0;

}