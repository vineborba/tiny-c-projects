#include "moon.h"

const char *MOON_PHASES_STR[8] = {
    "waxing crescent", "at first quarter", "waxing gibbous",  "full",
    "waning gibbous",  "at last quarter",  "waning crescent", "new",
};

// wtf
int moon_phase_calc(int year, int month, int day) {
  int d, g, e;
  d = day;
  if (month == 2)
    d += 31;
  else if (month > 2)
    d += 59 + (month - 3) * 30.6 + 0.5;
  g = (year - 1900) % 19;
  e = (11 * g + 29) % 30;
  if (e == 25 || e == 24)
    ++e;
  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

const char *moon_phase_str(int mp) { return MOON_PHASES_STR[mp]; }
