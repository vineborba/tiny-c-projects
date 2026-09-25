
#include <ctype.h>
#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      if (toupper(c) >= 'A' || toupper(c) <= 'M') {
        c += 13;
      } else {
        c -= 13;
      }
    }

    putchar(c);
  }

  return 0;
}
