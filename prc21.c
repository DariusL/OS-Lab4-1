#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Per mazai argumentu\n");
		return 1;
	}
	char *s = malloc(128);
	int pid = fork();
	if(pid < 0){
		printf("fork sprogo\n");
		return 1;
	}
	if(pid > 0){
		system("chmod 775 pap1.sh");
		sprintf(s, "./pap1.sh %s %s", argv[1], argv[2]);
		system(s);
		wait(&pid);
	}else{
		usleep(10);
		sprintf(s, "./pap2.sh %s", argv[2]);
		system("chmod 775 pap2.sh");
		system(s);
	}
	free(s);
	return 0;
}
