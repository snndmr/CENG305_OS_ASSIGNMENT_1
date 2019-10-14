#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *args[]) {
	if (argc == 3) {
		char *buffer = malloc(strlen("copy") + strlen(args[1]) + strlen(args[2]) + argc + 1);

		strcpy(buffer, "copy ");
		strcat(buffer, args[1]);
		strcat(buffer, " ");
		strcat(buffer, args[2]);
		strcat(buffer, "\0");

		system(buffer);
	} else {
		printf("\n You must enter the paths of the source and target files, respectively!");
	}
}
