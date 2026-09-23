#include <stdio.h>
#include <time.h>

#include "moon.h"

int main(int argc, char *argv[]) {
  time_t now;
  struct tm *clock;
  int hour;

  char time_string[64];

  time(&now);
  clock = localtime(&now);
  hour = clock->tm_hour;

  strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %H:%m%n", clock);

  int mp =
      moon_phase_calc(clock->tm_year + 1900, clock->tm_mon, clock->tm_mday);

  printf("Good ");
  if (hour < 12) {
    printf("morning");
  } else if (hour < 17) {
    printf("afternoon");
  } else {
    printf("evening");
  }

  if (argc > 1) {
    printf(", %s", argv[1]);
  }

  printf("!\n%s", time_string);

  printf("The moon is %s\n", moon_phase_str(mp));

  return 0;
}
