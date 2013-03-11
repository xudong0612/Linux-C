/* Author: Xudong
 * Date: 2013.3.4
 * Description: Find the Greatest Common Divison between a and b
 */
#include<stdio.h>
int GCD(int a, int b);
int main(void)
{
	printf("The greatest common division between 21 and 14 is %d.\n", GCD(21		, 14));
	return 0;
}
int GCD(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return GCD(b, a%b);
}
