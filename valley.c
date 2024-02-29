/**
 * CS1010 Semester 1 AY23/24
 * Exercise 6: Valley
 *
 * @file: valley.c
 * @author: Jodie (Group D03)
 */
#include "cs1010.h"

long search(long* arr, long i, long j)
{
  long mid = (i + j) / 2;
  if (mid == 0 || mid == j)
  {
    return arr[mid];
  }
  if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
  {
    return arr[mid];
  }
  if (arr[mid] > arr[mid + 1])
  {
    return search(arr, mid + 1, j);
  }
    return search(arr, i, mid - 1);
}

int main()
{
  size_t n = cs1010_read_size_t();
  long* arr = cs1010_read_long_array(n);
  cs1010_println_long(search(arr, 0, (long) n - 1));
  free(arr);
}
