#include<stdio.h>
int is_leap_year(int year);
int main(void)
{
	if(is_leap_year(2000))
    	printf("2000 is leap year.\n");
    else
    	printf("2000 is not leap year.\n");
	if(is_leap_year(2012))
		printf("2012 is leap year.\n");
	else
		printf("2012 is not leap year.\n");
	if(is_leap_year(2013))
		printf("2013 is leap year.\n");
	else
		printf("2013 is not leap year.\n");
	return 0;
}

int is_leap_year(int year)
{
	if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0; 
}
