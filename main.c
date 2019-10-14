#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isFileAlive(char source_path[]) {
	FILE *source = fopen(source_path, "rb");

	if (source != NULL) {
		fclose(source);
		return 1;
	} else {
		perror("Error on the source file");
		return 0;
	}
}

int main(int argc, char *args[]) {
	if (argc == 3) {
		if (isFileAlive(args[1])) {
			char *buffer = malloc(strlen("copy") + strlen(args[1]) + strlen(args[2]) + argc + 1);

			strcpy(buffer, "copy ");
			strcat(buffer, args[1]);
			strcat(buffer, " ");
			strcat(buffer, args[2]);
			strcat(buffer, "\0");

			system(buffer);
		}
	} else {
		printf("\n You must enter the paths of the source and target files, respectively!");
	}

}