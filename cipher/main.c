
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int c;

  int shift = 13;
  if (argc > 2 && isalpha(*argv[1]) && isalpha(*argv[2])) {
    shift = *argv[1] - *argv[2];
  }

  while ((c = getchar()) != EOF) {
    if (isupper(c)) {
      c += shift;
      if (c > 'Z')
        c -= 26;
      if (c < 'A')
        c += 26;
    } else if (islower(c)) {
      c += shift;
      if (c > 'z')
        c -= 26;
      if (c < 'a')
        c += 26;
    }

    putchar(c);
  }

  return 0;
}
