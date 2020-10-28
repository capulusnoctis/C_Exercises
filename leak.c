#include <stdio.h>
#include <stdlib.h>

int main() {
	char * p = NULL;

	for (int i = 0; i < 10; ++i) {
		printf("%d - Alocando 50 bytes de mememoria\n", (i + 1) );
		if (p) {
			free(p);
		}
		p = malloc( sizeof(char) * 50 );
	}

	free(p);
	printf("Terminado\n");

	return 0;

}
