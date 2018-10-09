#include <stdio.h>

char x = 'A';
char y[] = "BBC";

main() {
  printf("character:%c\n", *(&x + 3));
            printf("string:%s\n", *(&y + 3));
  return 0;
}
