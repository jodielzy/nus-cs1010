/**
 * CS1010 Semester 1 AY22/23
 * Assignment 5: Contact
 *
 * @file: contact.c
 * @author: Jodie (Group D03)
 */


#include "cs1010.h"

void print_contact(size_t n, char **contact, size_t j, size_t k)
{  
  if (contact[j][k] == '1')
  {
    cs1010_println_string("direct contact");
  }
  else
  {
    bool indirect_contact = false;
    long common_contact = -1;

    for (size_t i = 0; i < n; i += 1)
    {
      if (contact[j][i] == '1' && contact[k][i] == '1')
      {
        if (common_contact == -1 || (long) i < common_contact)
        {
          common_contact = (long) i;
        }
        indirect_contact = true;
      }
    }

    if (indirect_contact)
    {
      cs1010_print_string("contact through");
      cs1010_println_long(common_contact);
    }
    else
    {
      cs1010_println_string("no contact");
    }
  }
}



int main()
{
  size_t n = cs1010_read_size_t();
  char **contact = calloc(n, sizeof(char*));
  if (contact == NULL)
  {
    free(contact);
    return 1;
  }
  for (size_t i = 0; i < n; i += 1)
  {
    contact[i] = cs1010_read_word();
    if (contact[i] == NULL)
    {
      free(contact[i]);
      return 1;
    }
  }
  size_t j = cs1010_read_size_t();
  size_t k = cs1010_read_size_t();
  if (k <= j)
  {
    print_contact(n, contact, j, k);
  }
  else
  {
    print_contact(n, contact, k, j);
  }
  for (size_t i = 0; i < n; i += 1)
  {
    free(contact[i]);
  }
  free(contact);
  return 0;
}

