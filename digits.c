/**
 * CS1010 Semester 1 AY22/23
 * Assignment 8: Digits
 *
 * @file: digits.c
 * @author: Jodie (Group D03)
 */

#include "cs1010.h"

#define NCOLS 28
#define NROWS 28
#define WHITE '.'
#define BLACK '#'
#define K 5

typedef struct {
  long label;
  char** image;
} digit;
typedef struct {
  long neigh_digit;
  long distance;
} neighbour;

long calculate_distance(char** d1, char** d2)
{
  long distance = 0;
  for (long i = 0; i < NROWS; i += 1)
  {
    for (long j = 0; j < NCOLS; j += 1)
    {
      if (d1[i][j] != d2[i][j])
      {
        distance += 1;
      }
    }
  }
  return distance;
}

long find_min_dist(long recognised_digit, long i, neighbour* neigh)
{
  for (long j = 0; j < K; j += 1)
  {
    if (neigh[j].neigh_digit == recognised_digit || neigh[j].neigh_digit == i)
    {
      return neigh[j].neigh_digit;
    }
  }
  return -1;
}



long recognise_digit(digit *train, char** test_image, long no_of_train, neighbour *neigh)
{
  for (long i = 0; i < no_of_train; i += 1)
  {
    neigh[i].neigh_digit = train[i].label;
    neigh[i].distance = calculate_distance(test_image, train[i].image);
  }
  //sort by distance
  for (long i = 0; i < no_of_train - 1; i += 1)
  {
    for (long j = i + 1; j < no_of_train; j += 1)
    {
      if (neigh[i].distance > neigh[j].distance)
      {
        neighbour temp = neigh[i];
        neigh[i] = neigh[j];
        neigh[j] = temp;
      }
    }
  }
  //sort by label
  for (long i = 0; i < no_of_train - 1; i += 1)
  {
    if (neigh[i].distance == neigh[i + 1].distance)
    {
      if (neigh[i].neigh_digit > neigh[i + 1].neigh_digit)
      {
        neighbour temp = neigh[i];
        neigh[i] = neigh[i + 1];
        neigh[i + 1] = temp;
      }
    }
  }

  long votes[10] = {0};
  for (long i = 0; i < K; i += 1)
  {
    votes[neigh[i].neigh_digit] += 1;
  }
  long max_vote = 0; 
  long recognised_digit = -1;
  for (long i = 0; i < 10; i += 1)
  {
    if (votes[i] > max_vote)
    {
      max_vote = votes[i];
      recognised_digit = i;
    }
    else if (votes[i] == max_vote)
    {
      recognised_digit = find_min_dist(recognised_digit, i, neigh);
    }
  }
  return recognised_digit;
}

int main()
{
  long no_of_train = cs1010_read_long();
  long correct = 0; 
  digit *train = calloc((size_t) no_of_train, sizeof(digit));
  for (long i = 0; i < no_of_train; i += 1)
  {
    train[i].label = cs1010_read_long();
    train[i].image = cs1010_read_word_array(NROWS);
  }
  long no_of_test = cs1010_read_long();
  neighbour *neigh = calloc((size_t) no_of_train, sizeof(neighbour));
  for (long i = 0; i < no_of_test; i += 1)
  {
    long test_label = cs1010_read_long();
    char** test_image = cs1010_read_word_array(NROWS);

    long result = recognise_digit(train, test_image, no_of_train, neigh);
    cs1010_print_long(test_label);
    cs1010_print_string(" ");
    cs1010_println_long(result);
    if (test_label == result)
    {
      correct += 1;
    }
    for (long j = 0; j < NROWS; j += 1)
    {
      free(test_image[j]);
    }
    free(test_image);
  } 

  double accuracy = (double) correct / (double) no_of_test * 100;
  cs1010_println_double(accuracy);
  for (long i = 0; i < no_of_train; i += 1)
  {
    for (long j = 0; j < NROWS; j += 1)
    {
      free(train[i].image[j]);
    }
    free(train[i].image);
  }
  free(train);
  free(neigh);
}


