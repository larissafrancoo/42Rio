/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (isatty(STDIN_FILENO))
		printf("A entrada padrão é um terminal.\n");
	else
		printf("A entrada padrão não é um terminal.\n");
	return 0;
}
*/
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (isatty(STDOUT_FILENO))
	{
		printf("Saída padrão é um terminal.\n");
		printf("Executando modo interativo...\n");
	}
	else
	{
		printf("Saída padrão não é um terminal.\n");
		printf("Executando modo não interativo...\n");
	}
	return (0);
}
