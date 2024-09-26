#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t w_count(const char *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			i += w_len(s, c, i);
		}
	}
	return (count);
}

void	print_input(char **ret)
{
	size_t i = 0;
	size_t o = w_count(
}

void	input_prompt(void)
{
	char	*input;
	char	**ret;
	int		i;
	int		input_len;

	printf("Bem-vindo ao programa de exemplo readline!\n");
	printf("Digite 'sair' para sair.\n");

	while (1)
	{
		input = readline("\nPegar o endereço: ");
		add_history(input);

		if (strcmp(input, "sair") == 0)
		{
			free(input);
			break ;
		}
		ret = ft_split(input, ' ');
		free(input);
	}
	rl_clear_history();
	printf("\nPrograma encerrado.\n");
}

int main(void)
{
	input_prompt();
	return (0);
}
