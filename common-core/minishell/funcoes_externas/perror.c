#include <stdio.h>
#include <errno.h>

int main(void)
{
	FILE *file = fopen("text.txt", "r");
	if (!file)
		perror("Erro ao abrir arquivo");
	return (0);
}
