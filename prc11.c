#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ( void ) {
	int i;
	pid_t pid;
	for(i = 0; i < 2; i++){
	printf("Kuriamas vaiko procesas...\n");
	pid = fork();			/* Kuria vaiko procesa  */
	if ( pid == -1 ) {
		perror("Nepavyko sukurti vaiko proceso!");
		exit(1);
	}
	if ( pid == 0 ) {
		/* Vaiko proceso PRADZIA */
		printf("Proceso ID: %d\n", getpid());
		printf("proceso tevo ID: %d\n", getppid());
		if(i == 0)
			printf("Vaikas\n\n");
		else
			printf("Vaikaitis\n\n");
	} else {				/* pid > 0 */
		printf("Proceso ID: %d\n", getpid());
		printf("proceso tevo ID: %d\n", getppid());
		printf("Tevas\n\n");
		break;
		}
	}

	int   status = 0;		/* Vaiko grazinta busena per exit() */
	pid_t pidwait = 0;
	pidwait = wait(&status);	/* Tevas laukia kol uzsibaigs jo vaiko procesas */
	return 0;
}
