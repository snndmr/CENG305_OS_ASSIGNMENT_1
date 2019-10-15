
//	----------------------------------
//	 +		Author : Sinan Demir    +
//	 +	Student ID : 16050111046	+
//	----------------------------------

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

int main() {
  char sourcePath[BUFFER];
  char targetPath[BUFFER];
  
  printf("Enter source file path : ");
  scanf("%s", sourcePath);
  printf("Enter target file path : ");
  scanf("%s", targetPath);

  fileOperation(sourcePath, targetPath);
  return 0;
}
