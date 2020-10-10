#include <stdio.h>
#include <string.h>

int main() {
	char * Name = "Axel J. Solares";
	char * otherName = "Seko";

	printf("Los nombres son %s\n", strcmp(Name, otherName) == 0 ? "Iguales" : "Distintos");

	return 0;
}
