/**
 * CS1010 Semester 1 AY23/24
 * Exercise 7: Fill
 *
 * @file: fill.c
 * @author: Jodie (Group D03)
 */


#include "cs1010.h"


bool is_same_colour(long** image, long x, long y, long r, long g, long b)
{
  if (image[y][3 * x] == r && image[y][(3 * x) + 1] == g && image[y][(3 * x) + 2] == b)
  {
    return true;
  }
  return false;
}

bool out_of_image(size_t row, size_t col, long x, long y)
{
  if (x < 0 || x > (long) col - 1 || y < 0 || y > (long) row - 1)
  {
    return true;
  }
  return false;
}

void fill(long** image, size_t row, size_t col, long x, long y, long r0, long g0, long b0, long r, long g, long b)
{
  if (r0 == r && g0 == g && b0 == b)
  {
    return;
  }
  if (out_of_image(row, col, x, y) || !is_same_colour(image, x, y, r0, g0, b0))
  {
    return;
  }
  image[y][3 * x] = r;
  image[y][(3 * x) + 1] = g;
  image[y][(3 * x) + 2] = b;
  fill(image, row, col, x - 1, y, r0, g0, b0, r, g, b);
  fill(image, row, col, x + 1, y, r0, g0, b0, r, g, b);
  fill(image, row, col, x, y - 1, r0, g0, b0, r, g, b);
  fill(image, row, col, x, y + 1, r0, g0, b0, r, g, b);
}

void print(long** image, size_t row, size_t col)
{
  cs1010_print_string("P3 ");
  cs1010_print_size_t(col);
  cs1010_print_string(" ");
  cs1010_print_size_t(row);
  cs1010_println_string(" 255");
  for (size_t i = 0; i < row; i += 1)
  {
    for (size_t j = 0; j < col * 3; j += 3)
    {
      cs1010_print_long(image[i][j]);
      cs1010_print_string(" ");
      cs1010_print_long(image[i][j + 1]);
      cs1010_print_string(" ");
      cs1010_print_long(image[i][j + 2]);
      cs1010_println_string("");
    }
  }
}


int main()
{
  size_t row = cs1010_read_size_t();
  size_t col = cs1010_read_size_t();
  long** image = calloc(row, sizeof(long*));
  
  for (size_t i = 0; i < row; i += 1)
  {
    image[i] = cs1010_read_long_array(3 * col); 
  }
  size_t no_of_fills = cs1010_read_size_t();
  for (size_t i = 0; i < no_of_fills; i += 1)
  {
    long x = cs1010_read_long();
    long y = cs1010_read_long();
    long r = cs1010_read_long();
    long g = cs1010_read_long();
    long b = cs1010_read_long();
    long r0 = image[y][3 * x];
    long g0 = image[y][(3 * x) + 1];
    long b0 = image[y][(3 * x) + 2];
    fill(image, row, col, x, y, r0, g0, b0, r, g, b);
  }
  print(image, row, col);

  for (size_t i = 0; i < row; i += 1)
  {
    free(image[i]);
  }
  free(image);
}

