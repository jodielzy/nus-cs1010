/**
 * CS1010 Semester 1 AY22/23
 * Exercise 4: Search
 *
 * @file: search.c
 * @author: Jodie (Group D03)
 */
#include "cs1010.h"

long check_word(char* string, char* word)
{
  long i = 0;
  while (string[i] != '\0')
  {
    long j = 0;
    long k = 0;
    if (string[i] == word[j]) {
      k = i;
    }
    while (string[i] == word[j])
    {
      j += 1;
      i += 1;
      if (word[j] == '\0')
      {
        return k;
      }
    }
    if (k!=0) {
      i = k;
    }
    i +=1;
  }
  return -1;
}

int main()
{
  char* string = cs1010_read_line();
  long k = cs1010_read_long();
  long arr[k];
  for (long i = 0; i < k; i += 1)
  {
    char* word =  cs1010_read_word();
    long temp = check_word(string,word);
    arr[i] = temp;
    free(word);
  }
  for (long j = 0; j < k; j += 1)
  {
  if (arr[j] < 0)
  {
    cs1010_println_string("not found");
  }
  else
  {
    cs1010_println_long(arr[j]);
  }
  }
  free(string);
}
