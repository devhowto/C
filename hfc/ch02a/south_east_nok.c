#include <stdio.h>

/**
 * (origin)
 *     ·
 *       ·
 *         ·
 *           ·
 *             ·
 *        (destination)
 *
 * Moving south-east means:
 *  - latitude decreases
 *  - longitude increases
 */
void go_south_east (short lat, short lon)
{
  lat = lat - 1;
  lon = lon + 1;
}

int main ()
{
  short latitude = 0;
  short longitude =   0;

  //
  // We are passing a copy of the values (not references to their memory
  // addresses). When the function changes the values of the copies, the
  // original values remain the same.
  //
  go_south_east (latitude, longitude);

  fprintf (stdout,
           "Avast! Now at: [%i, %i]\n",
           latitude,
           longitude);

  return 0;
}

