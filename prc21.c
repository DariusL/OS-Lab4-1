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
	int pid = fork();

