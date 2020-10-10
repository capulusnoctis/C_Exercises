#include <stdio.h>
#include <string.h>

int main() {
	char * src = "Seko";
	char dst[20] = "Esto no se vera";

	strcpy( dst, src );
	printf("Destino (dst) =  %s\n", dst);

	return 0;
}
