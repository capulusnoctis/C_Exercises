#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
	int shared = 2;
	int pid = fork();
	
	if (pid) {
		shared = 1;
		printf("Luke soy tu padre! Mi pid es %d y tu pid es %d. Shared = %d\n", getpid(), pid, shared);
		
		wait( NULL );
		printf("Soy tu padre... De nuevo. Shared = %d\n", shared);
	} else {
		shared = 0;
		printf("Soy Luke! Mi pid es %d. Shared = %d\n", getpid(), shared);
		sleep(2);
	}
	
	while(1);
	
	return 0;
}
