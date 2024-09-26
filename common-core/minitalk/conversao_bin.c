#include <unistd.h>
#include <stdio.h>

void putnbr(unsigned int nbr)
{
	nbr = nbr + 48;
	write (1, &nbr, 1);
}

void binario(int n)
{

	if (n == 0)
		write (1, "0", 1);
	else
	{
		binario(n / 2);
		putnbr(n % 2);
	}
}

int main(void)
{
	int number;
	printf("Escolha um número: ");
	scanf("%d", &number);

	binario(number);
	printf("\n");
	return (0);
}
