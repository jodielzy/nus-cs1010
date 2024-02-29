/**
 * CS1010 Semester 1 AY23/24
 * Exercise 6: Sort
 *
 * @file: sort.c
 * @author: Jodie (Group D03)
 */
#include "cs1010.h"

long find_min_pos(long* v_array, size_t n)
{
  long min = v_array[0];
  long min_pos = 0;
  for (size_t i = 1; i < n; i += 1)
  {
    if (v_array[i] < min)
    {
      min = v_array[i];
      min_pos = (long) i;
    }
  }
  return min_pos;
}

void insert(long* v_array, size_t n, size_t curr)
{
  size_t i = curr;
  long temp = v_array[i - 1];
  while (i < n && temp > v_array[i])
  {
    v_array[i - 1] = v_array[i];
    i += 1;
  }
  v_array[i - 1] = temp;
}
    
void insertion_sort(long* v_array, size_t n, long min_pos)
{
  for (size_t curr = (size_t) min_pos; curr > 0; curr -= 1)
  {
    insert(v_array, n, curr);
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  long* v_array = cs1010_read_long_array(n);
  long min_pos = find_min_pos(v_array, n);
  insertion_sort(v_array, n, min_pos);
  for (size_t i = 0; i < n; i += 1)
  {
    cs1010_println_long(v_array[i]);
  }
  free(v_array);
}

