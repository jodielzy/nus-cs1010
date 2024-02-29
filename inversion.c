/**
 * CS1010 Semester 1 AY23/24
 * Exercise 6: Inversion
 *
 * @file: inversion.c
 * @author: Jodie (Group D03)
 */
#include "cs1010.h"

size_t find_max_pos(long *arr, size_t n)
{
  for (size_t i = 0; i < n - 1; i += 1)
  {
    if (arr[i + 1] < arr[i])
    {
      return i;
    }
  }
  return 1;
}

long insert(long* arr, size_t curr)
{
  long counter = 0;
  size_t i = curr;
  long temp = arr[curr];
  while (i >= 1 && temp < arr[i - 1])
  {
    arr[i] = arr[i - 1];
    i -= 1;
    counter += 1;
  }
  return counter;
}

long insertion_sort(long* arr, size_t n, size_t max_pos)
{
  long counter = 0;
  for (size_t curr = max_pos + 1; curr < n; curr += 1)
  {
    counter += insert(arr, curr);
  }
  return counter;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long* arr = cs1010_read_long_array(n);
  size_t max_pos = find_max_pos(arr, n);
  cs1010_println_long(insertion_sort(arr, n, max_pos));
  free(arr);
}
