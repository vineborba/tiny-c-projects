#include "isterm.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void textToNato();
void natoToText();

const char *nato[] = {
    "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
    "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

int main(int argc, char *argv[]) {
  int mode;

  if (argc < 2) {
    puts("Mode not passed, using default text -> NATO");
    mode = 1;
  } else if (strlen(argv[1]) == 1 && isdigit(*argv[1])) {
    mode = atoi(argv[1]);
  }

  // text -> NATO
  if (mode == 1) {
    textToNato();
  } else if (mode == 2) {
    natoToText();
  } else {
    fprintf(stderr, "Invalid argument passed to mode.\n");
    exit(1);
  }

  return 0;
}

void natoToText() {
  char phrase[64];
  char *match;
  char ch;

  printf("Entrer a NATO word or phrase: ");
  fgets(phrase, 64, stdin);

  match = strtok(phrase, " ");
  while (match) {
    ch = isterm(match, (char **)nato);
    if (ch != '\0') {
      putchar(ch);
    }

    match = strtok(NULL, " ");
  }

  putchar('\n');
}

void textToNato() {
  char phrase[64];
  int i;
  char ch;

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
}
