#include<stdio.h>
#include<math.h>
double myround(double x);

int main(void)
{
	printf("myround(-3.49) = %.1f\n", myround(-3.49));
	printf("myround(4.51) = %.1f\n", myround(4.51));
	return 0;
}

double myround(double x)
{
	if(x >= 0)
		if(x - floor(x) < 0.5)
			return floor(x);
		else
			return ceil(x);
	else
		if(x - ceil(x) > -0.5)
			return ceil(x);
		else
			return floor(x);
}
