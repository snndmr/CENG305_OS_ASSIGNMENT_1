#include<stdio.h>

#define BUFFER 0x1000

void fileOperation(char sourcePath[], char targetPath[]) {
  FILE * source = fopen(sourcePath, "rb");

  if (source != NULL) {
    FILE * target = fopen(targetPath, "wb");

    if (target != NULL) {
      char buffer[BUFFER];

      while (!feof(source)) {
        fwrite(buffer, fread(buffer, 1, sizeof(buffer), source), 1, target);
      }
      fclose(target);
    } else {
      perror("Error on target file ");
    }
    fclose(source);
  } else {
    perror("Error on source file ");
  }
}

int main(int argc, char * args[]) {
  if (argc == 3) {
    fileOperation(args[1], args[2]);
  } else {
    printf("You must enter source and target files paths!");
  }

  return 0;
}
