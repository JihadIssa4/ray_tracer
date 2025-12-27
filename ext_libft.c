#include <stdio.h>
#include <unistd.h>

char	*foo(int n)
{
	char	digit;

	if (n / 10)
		foo(n / 10);
	digit = '0' + n % 10;
	write(1, &digit, 1);
}

int	fractionFactor(double n)
{
	int	factor;

	factor = 10;
	n *= factor;
	while (((int)n) % 10)
	{
		factor *= 10;
		n *= factor;
	}
	return (factor);
}
	
char	*dtoi(double n)
{
	double fractional;


	fractional = ((int)n) - n;
	if (fractional < 0)
		fractional *= -1;
	
}
int main()
{
	printf("%d\n", fractionFactor(1987.3993));
	printf("%d\n", fractionFactor(1987.399));
}
