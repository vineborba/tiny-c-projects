#include <stdio.h>
int main() {
  char a = 'a';
  char aUpper = 'A';

  printf("%c %c %c %c\n", a, aUpper, (a | 0x20), (aUpper | 0x20));
  printf("%x %x %x %x\n", a, aUpper, (a | 0x20), (aUpper | 0x20));
}
