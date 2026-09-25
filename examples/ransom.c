#include <stdio.h>

int main() {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      if (i & 1) {
        c = c & 0x5f;
      } else {
        c = c | 0x20;
      }
    }

    putchar(c);
    i++;
  }

  return 0;
}
