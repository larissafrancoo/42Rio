#include <unistd.h>
#include <stdio.h>

int main(void)
{
	const char *file = "funcoes.txt";

	if (access(file, F_OK) == 0)
	{
		printf("O arquivo existe.\n");
		if (access(file, R_OK) == 0)
			printf("O arquivo pode ser lido.\n");
		else
			printf("O arquivo não pode ser lido.\n");

		if (access(file, W_OK) == 0)
			printf("O arquivo pode ser escrito.\n");
		else
			printf("O arquivo não pode ser escrito.\n");

		if (access(file, X_OK) == 0)
			printf("O arquivo pode ser executado.\n");
		else
			printf("O arquivo não pode ser executado.\n");
	}
	else
		printf("O arquivo não existe.\n");
	return (0);
}
