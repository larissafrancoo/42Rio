#include <string.h>
#include <stdio.h>

int main(void)
{
	int c = -1;
	while (c++ < 133)
		printf("%d - %s \n", c, strerror(c));
	return (0);
}
