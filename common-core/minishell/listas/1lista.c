#include <stdio.h>
#include <stdlib.h>

typedef struct s_no
{
	int value;
	struct s_no *next;
}	t_no;

/* procedimento para inserir no início. */
void head_insert(t_no **list, int num)
{
	t_no *new = malloc(sizeof(t_no));

	if (!new)
		printf("Erro ao alocar memória!\n");
	new->value = num;
	new->next = *list;
	*list = new;
}

/* procedimento para inrerir no fim. */
void tail_insert(t_no **list, int num)
{
	t_no *aux, *new = malloc(sizeof(t_no));
	aux = *list;

	if (!new)
		printf("Erro ao alocar memória!\n");
	new->value = num;
	new->next = NULL;

	/* Esse nó é o primeiro da lista? */
	if (*list == NULL)
		*list = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

/* procedimento para inserir no meio. */
void middle_insert(t_no **list, int num, int ref)
{
	t_no *aux, *new = malloc(sizeof(t_no));
	aux = *list;

	if (!new)
		printf("Erro ao alocar memória!\n");
	new->value = num;

	/* Esse nó é o primeiro da lista? */
	if (*list == NULL)
	{
		new->next = NULL;
		*list = new;
	}
	else
	{
		if (aux->next && (aux->value != ref))
			aux = aux->next;
		new->next = aux->next;
		aux->next = new;
	}
}

void imprimir(t_no *no)
{
	printf("\n\tLista: ");
	while (no)
	{
		printf("%d ", no->value);
		no = no->next;
	}
	printf("\n\n");
}

int main(void)
{
	int option;
	int value;
	int before;
	t_no *list = NULL;
	do {
		printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &value);
				head_insert(&list, value);
				break ;
			case 2:
				printf("Digite um valor: ");
				scanf("%d", &value);
				tail_insert(&list, value);
				break ;
			case 3:
				printf("Digite o valor que voce que inserir: ");
				scanf("%d", &value);
				printf("Digite o valor de referência: ");
				scanf("%d", &before);
				middle_insert(&list, value, before);
				break ;
			case 4:
				imprimir(list);
				break ;
			default:
				if (option != 0)
					printf("Opção Invalida!\n");
		}
	} while (option != 0);
	return (0);
}
