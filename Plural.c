#include<stdio.h>
#include<math.h>

/*
 *2 ways of making a plural
 */

//plural by real and img
struct complex_struct {
	double x, y;
};

double real_part(struct complex_struct z)
{
	return z.x;
}
double img_part(struct complex_struct z)
{
	return z.y;
}
double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}
double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}

//plural by magnitude and angle
/*
struct complex_struct {
	double r, A;
};

double real_part(struct complex_struct z)
{
	return z.r * cos(z.A);
}

double img_part(struct complex_struct z)
{	
	return z.r * sin(z.A);
}

double magnitude(struct complex_struct z)
{
	retrun z.r;
}

double angle(struct complex_struct z)
{
	return z.A;
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.A = atan2(y, x);
	z.r = sqrt(x * x + y * y);
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct;
	z.r = r;
	z.A = A;
	return z;
}
*/

//plural computing, include add, sub, mul and div
struct complex_struct add_complex(struct complex_struct z1,
								struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
								img_part(z1) + img_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1,
								struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
								img_part(z1) - img_part(z2));
}
struct complex_struct mul_complex(struct complex_struct z1,
								struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1)*magnitude(z2),
								angle(z1) + angle(z2));
}
struct complex_struct div_complex(struct complex_struct z1,
								struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
								angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
	if(real_part(z) == 0 && img_part(z) == 0)
		printf("0\n");
	else if(real_part(z) == 0)
		printf("%.1fi\n", img_part(z));
	else if(img_part(z) == 0)
		printf("%.1f\n", real_part(z));
	else
		//if(img_part(z) > 0)
		//	printf("%.1f+%.1fi\n", real_part(z), img_part(z));
		printf("%.1f%+.1fi\n", real_part(z), img_part(z));
}


int main(void)
{
	struct complex_struct z1 = {3.0, 4.0};
	struct complex_struct z2 = {2.0, 5.0};
	//print_complex(z2);
	printf("%.1f\n", real_part(z1));
	printf("%.1f\n", img_part(z1));
	print_complex(add_complex(z1, z2));
	print_complex(sub_complex(z1, z2));
	print_complex(mul_complex(z1, z2));
	print_complex(div_complex(z1, z2));
	return 0;
}
