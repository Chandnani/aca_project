#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Rfib(long long int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return (Rfib(n-1)+Rfib(n-2))%2017;	 
}

int main(){
    	
    	long long int n=1;
	clock_t tStart = clock();
	scanf("%lld",&n);
        Rfib(n);
	double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
	printf("%lld %.10f\n",n,temp/1);

	return 0;
}
