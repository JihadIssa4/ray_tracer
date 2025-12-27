#include <stdio.h>

char	*itoa(int n)
{
	int div;
	
	while (div = n %10)
	{
		printf("%d\n", div);
		n = div;
		break;
	}
}

int main()
{
	printf("%d", 165 % 10);
	//itoa(165);
}
