#include<stdio.h>
int Fibonacci(int n);
int main(void)
{
	printf("Fib(10)=%d.\n", Fibonacci(10));
	return 0;
}
int Fibonacci(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}
