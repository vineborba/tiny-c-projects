#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      c = c & 0x5f;
    }

    putchar(c);
  }

  return 0;
}
