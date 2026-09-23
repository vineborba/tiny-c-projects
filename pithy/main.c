#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main() {
  const char filename[] = "resources/pithy.txt";
  FILE *fp;

  char buffer[BSIZE];
  char *r, *entry;
  int items, saying;
  char **list_start;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", filename);
    exit(1);
  }

  list_start = (char **)malloc(sizeof(char *) * 100);
  if (list_start == NULL) {
    fprintf(stderr, "Unable to allocate memory for list\n");
    exit(1);
  }

  items = 0;
  while (!feof(fp)) {
    r = fgets(buffer, BSIZE, fp);
    if (r == NULL) {
      break;
    }

    entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
    if (entry == NULL) {
      fprintf(stderr, "Unable to allocate memory for item %d\n", items);
      exit(1);
    }

    strcpy(entry, buffer);

    *(list_start + items) = entry;
    items++;
    if (items % 100 == 0) {
      list_start = (char **)realloc(list_start, sizeof(char *) * (items + 100));
      if (list_start == NULL) {
        fprintf(stderr, "Unable to reallocate list to bigger buffer\n");
      }
    }
  }

  fclose(fp);

  srand((unsigned)time(NULL));
  saying = rand() % (items - 1);
  printf("%s\n", list_start[saying]);

  for (int x = 0; x < items; x++)
    free(*(list_start + x));
  free(list_start);

  return 0;
}
