/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *nome_terminal;
	nome_terminal = ttyname(STDIN_FILENO);
	if (nome_terminal)
		printf("O terminal associado à entrada padrão é: %s\n", nome_terminal);
	else
		perror("Erro ao obter o nome do terminal");
	return (0);
}
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *nome_terminal;
	nome_terminal = ttyname(STDOUT_FILENO);
	if (nome_terminal)
		printf("O terminal associado à saída padrão é: %s\n", nome_terminal);
	else
		perror("Erro ao obter o nome do terminal");
	return (0);
}

