#include <stdio.h>

void multiply(long long int F[2][2], long long int M[2][2]);

void power(long long int F[2][2], long long int n);

/* function that returns nth Fibonacci number */
long long int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  ((F[0][0]*M[0][0])%2017 + (F[0][1]*M[1][0])%2017)%2017;
  long long int y =  ((F[0][0]*M[0][1])%2017 + (F[0][1]*M[1][1])%2017)%2017;
  long long int z =  ((F[1][0]*M[0][0])%2017 + (F[1][1]*M[1][0])%2017)%2017;
  long long int w =  ((F[1][0]*M[0][1])%2017 + (F[1][1]*M[1][1])%2017)%2017;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main()
{
  long long int n;
  scanf("%lld",&n);
  printf("%lld", fib(n)%2017);
  getchar();
  return 0;
}