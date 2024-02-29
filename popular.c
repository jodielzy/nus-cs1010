/**
 * CS1010 Semester 1 AY22/23
 * Assignment 5: Popular
 *
 * @file: popular.c
 * @author: Jodie (Group D03)
 */

#include "cs1010.h"


int main()
{
  size_t n = cs1010_read_size_t();

  char **network = calloc(n, sizeof(char *));
  if (network == NULL)
  {
    free(network);
    return 1;
  }

  for (size_t i = 0; i < n ; i += 1)
  {
    network[i] = cs1010_read_word(); 
    if (network[i] == NULL)
    {
      free(network[i]);
      return 1;
    }
  }
  size_t most_popular_id = 0;
  size_t most_friends = 0;
  size_t *friends = calloc(n, sizeof(size_t));

  for (size_t i = 0; i < n; i += 1)
  {
    friends[i] = 0;
    for (size_t j = 0; j < i; j += 1)
    {
      if (network[i][j] == '1')
      {
        friends[i] += 1;
        friends[j] += 1;
      }
    }  
  }
  for (size_t i = 0; i < n; i += 1)
  {
    if (friends[i] > most_friends)
    {
      most_friends = friends[i];
      most_popular_id = i;
    }
  }
  cs1010_println_size_t(most_popular_id);
  cs1010_println_size_t(most_friends);

  for (size_t i = 0; i < n; i += 1)
  {
    free(network[i]);
  }
  free(network);
  free(friends);
  return 0;
}


