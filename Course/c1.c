#include<stdio.h>
#include<time.h>

int main() 
{
	long long int i;
	double total_time;
	clock_t start, end;

	start = clock();//time count starts 

	// srand(time(NULL));
	for (i = 0; i < 	500000; i++) 
	{
		printf("random_number[%lld]= %lld\n", i + 1, i+1);
	}
	end = clock();//time count stops 
	total_time = ((double) (end - start))/CLOCKS_PER_SEC;//calulate total time
	printf("\nTime taken to print 25000 random number is: %f\n", total_time);
	return 0;
}