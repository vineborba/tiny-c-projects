#include "isterm.h"

char isterm(char *term, char *list[]) {
  int x;
  const char *n, *t;

  for (x = 0; x < 26; x++) {
    n = list[x];
    t = term;
    while (*n != '\0') {

      // ascii magic, convert char to lowercase. A -> a
      if ((*n | 0x20) != (*t | 0x20))
        break;

      n++;
      t++;
    }

    if (*n == '\0') {
      return *list[x];
    }
  }

  return '\0';
}
