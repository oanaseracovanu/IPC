#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, delta, x1, x2;
	printf("ax^2 + bx + c = 0\n");
	printf("a = "); scanf("%f", &a);
	printf("b = "); scanf("%f", &b);
	printf("c = "); scanf("%f", &c);

	delta = b * b - 4.0f * a * c;

	if (delta > 0.0f)
	{
		delta = (float)sqrt(delta);
		x1 = (-b + delta) / (2 * a);
		x2 = (-b - delta) / (2 * a);
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
	}
	else if (delta == 0.0f)
	{
		x1 = -b / (2 * a);
		printf("x1 = x2 = %f\n", x1);
	}
	else printf("Nu exista solutii reale");

	return 0;
}