#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float avg = 0;
float old_avg = 0;

void expression(float k, int n)
{
	avg = (((n - 1) * old_avg )/n)+(k / n);
	old_avg = avg;
}


int main()
{
	float a;
	int b = 1;
	while (1)
	{
		printf("수를 입력하세요  :	");
		scanf("%f", &a);
		expression(a, b);
		b++;
		printf("%lf	\n", avg);
	}
}