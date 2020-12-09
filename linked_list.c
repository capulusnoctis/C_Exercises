#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

NODE * createNode( int number ) {
	NODE * newNode;

	newNode = malloc( sizeof(NODE) );
	newNode->next = NULL;
	newNode->number = number;

	return newNode;
}
void printNode(NODE * node) {
	NODE *current = node;

	while (current) {
		printf("%d", current->number);
		printf(current->next ? ", " : "\n");
		current = current->next;
	}
}
int main(int argc, const char * argv[]) {
	NODE * start = NULL, * current, *next, *prev;
	char goOn;
	int listSize = 0, number, numberToDelete;

	do {
		printf("La lista tiene %d nodos. Ingrese el siguiente numero (0 para finalizar)", listSize);
		scanf("%d", &number);
		if (number) {
			if (!start) {
				start = createNode(number);
				listSize++;
			} else {
				current = start;
				while (current->next) {
					current = current->next;
				}
				current->next = createNode(number);
				listSize++;
			}
			goOn = 1;
		} else {
			goOn = 0;
		}
	} while(goOn);

	//current = start;
	printf("La lista contiene los numeros: \n");
	printNode(start);
	
	printf("Desea eliminar algun numero?(1 = si, 0 = no) \n");
	scanf("%d", &goOn);
	
	while (goOn) {
		printf("Ingrese el numero que desea eliminar: $ ");
		scanf("%d", &numberToDelete);
		
		current = start;
		prev = current;
		while (current) {
			next = current->next;
			if (current->number == numberToDelete && start->number != numberToDelete) {
				free(current);
				prev->next = next;
				break;
			} else if (current->number == numberToDelete && start->number == numberToDelete) {
				free(current);
				start = next;
				break;
			}
			prev = current;
			current = next;
		}
		
		printf("Se elimino el elemento. Quedando la lista: \n");
		printNode(start);
		
		printf("Desea eliminar otro numero?(1 = si, 0 = no) \n");
		scanf("%d", &goOn);
	}
	
	current = start;
	while (current) {
		next = current->next;
		free( current );
		current = next;
	}

	return 0;
}
