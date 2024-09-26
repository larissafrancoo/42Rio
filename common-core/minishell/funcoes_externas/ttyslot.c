#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int slot = ttyslot();
	if (slot > 0)
		printf("O slot do terminal é: %d\n", slot);
	else
		printf("Não foi possível determinar o slot do terminal.\n");
	return 0;
}
