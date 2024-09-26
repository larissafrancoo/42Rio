#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	char	*input;
	char	*rev_input;
	int		i;
	int		input_len;

	printf("Bem-vindo ao programa de exemplo readline!\n");
	printf("Digite 'sair' para sair.\n");

	while (1)
	{
		// Abre um prompt para ler o que o usuário digitar
		input = readline("\nDigite uma sequência de caracteres: ");

		// Adiciona o input em um histórico de comandos
		add_history(input);

		// Verifica se o usuário deseja sair. Caso sim, libera a memória e interrompe o loop
		if (strcmp(input, "sair") == 0)
		{
			free(input);
			break ;
		}

		// Calcula o tamanho da string de entrada
		input_len = strlen(input);
		rev_input = (char *) malloc((input_len + 1) * sizeof(char));

		// Inverte a sequência de caracteres
		i = -1;
		while (++i < input_len)
			rev_input[i] = input[input_len - i - 1];
		rev_input[input_len] = '\0';
		
		// Troca a linha de entrada pela string invertida
		rl_on_new_line();
		rl_replace_line(rev_input, 0);
		rl_redisplay();

		// Libera memória
		free(rev_input);
		free(input);
	}

	// Limpa o histórico de inputs
	rl_clear_history();
	printf("\nPrograma encerrado.\n");

	return (0);
}
/*
int main(int argc, char **argv, char **envp)
{
	int i = -1;
	int o = -1;
	int u = 0;

	while (envp[++i])
	{
		printf("%d. %s|\n", i, envp[i]);
		printf("\n");
	}
	return (0);
}
*/
