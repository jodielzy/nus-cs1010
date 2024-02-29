/**
 * CS1010 Semester 1 AY22/23
 * Exercise 9: Line
 *
 * @file: line.c
 * @author: Jodie (Group D03)
 */
#include "cs1010.h"
#include <math.h>

#define BLACK 0
#define WHITE 255


void draw_line(long rows, long col, long x1, long y1, long x2, long y2)
{
  long **image = calloc((size_t) rows, sizeof(long*));
  if (image == NULL)
  {
    free(image);
    return;
  }
  for (long i = 0; i < rows; i += 1)
  {
    image[i] = calloc((size_t) col, sizeof(long));
    if (image[i] == NULL)
    {
      for (long j = 0; j <= i; j += 1)
      {
        free(image[i]);
      }
      free(image);
      return;
    }
  }
  for (long i = 0; i < rows; i += 1)
  {
    for (long j = 0; j < col; j += 1)
    {
      image[i][j] = 0;
    }
  }

  double m = (double) (y2 - y1) / (double) (x2 - x1);
  double y = (double)y1;
  for (long x = x1; x <= x2; x += 1)
  {
    double temp = round(y);
    if (temp >= 0.0 && temp < (double) rows)
    {
      image[(long) temp][x] = 255;
    }
    y += m;
  }

  cs1010_println_string("P2");
  cs1010_print_long(col);
  cs1010_print_string(" ");
  cs1010_println_long(rows);
  cs1010_println_long(255);

  for (long i = 0; i < rows; i += 1)
  {
    for (long j = 0; j < col; j += 1)
    {
      cs1010_print_long(image[i][j]);
      if (j != col - 1)
      {
        cs1010_print_string(" ");
      }
    }
    cs1010_println_string("");
  }

  for (long i = 0; i < rows; i += 1)
  {
    free(image[i]);
  }
  free(image);
}


int main()
{
  long col = cs1010_read_long();
  long rows = cs1010_read_long();
  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();

  draw_line(rows, col, x1, y1, x2, y2);
}
