#include <ctype.h>
#include <stdio.h>

const char *nato[] = {
    "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
    "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

char isterm(char *term) {
  int x;
  const char *n, *t;

  for (x = 0; x < 26; x++) {
    n = nato[x];
    t = term;
    while (*n != '\0') {

      // ascii magic, convert char to lowercase. A -> a
      if ((*n | 0x20) != (*t | 0x20))
        break;

      n++;
      t++;
    }

    if (*n == '\0') {
      return *nato[x];
    }
  }

  return '\0';
}

int main() {
  char phrase[64];
  char ch;
  int i;

  printf("Enter a word or prhase: ");
  fgets(phrase, 64, stdin);

  i = 0;
  while (phrase[i]) {
    ch = toupper(phrase[i]);

    if (isalpha(ch))
      printf("%s ", nato[ch - 'A']);

    i++;
    if (i == 64)
      break;
  }

  putchar('\n');

  return 0;
}
