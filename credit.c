#include <cs50.h>
#include <stdio.h>

int main(void)
{
  //get card number
  long n;

    do
    {
      n = get_long("Credit Card Number: ");
    }
    while(n < 0);

    //check length of number
    int l = 0;
    long cc = n;
    while(cc > 0)
    {
      cc = cc / 10;
      l++;
    }

    //check if length is valid
    if(l != 13 && l != 15 && l != 16)
    {
      printf("INVALID\n");
      return 0;
    }


    //Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int dig1;
    int dig2;
    int num1;
    int num2;


    do
    {
      dig1 = x % 10;
      x = x / 10;
      sum1 += dig1;

      dig2 = x % 10;
      x = x / 10;

      dig2 = dig2 * 2;
      num1 = dig2 % 10;
      num2 = dig2 / 10;
      sum2 += num1 + num2;
    }
    while(x > 0);

    total = sum1 + sum2;

    //check checksum
    if(total % 10 != 0)
    {
      printf("INVALID\n");
      return 0;
    }

    //Get starting 2 digits
    long start = n;
    do
    {
      start = start / 10;
    }
    while(start > 100);

    //Check AMEX
    if((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
      printf("AMEX\n");
    }
    //Check MASTERCARD
    else if((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
      printf("MASTERCARD\n");
    }
    //Check VISA
    else if(start / 10 == 4)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }

}