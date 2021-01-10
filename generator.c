// USAGE: >> a.exe X
// Where X is the number of characters in the generated string
// Highly adjustable!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int asciiBase = 0x21;
  const int asciiRange = 0x7A - asciiBase;
  int strLength = atoi(argv[1]);

  srand(time(NULL));
  const char notAllowed[] = "!\"\\$%&'()*+,-./@:;<=>?[]^_` ";
  printf("\nNot Using: %s\n", notAllowed);

  for (int j = 0; j < strLength; j++) {
    int blacklisted = 0;
    char tempchar = rand() % asciiRange + asciiBase;
    for (int k = 0; k < strlen(notAllowed); k++) {
      blacklisted += notAllowed[k] == tempchar;
    }
    if (blacklisted) {
      strLength++;
    } else {
      printf("%c", tempchar);
    }
  }
  return 0;
}
