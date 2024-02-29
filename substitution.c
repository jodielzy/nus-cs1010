#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_alpha(string s);
bool repeated(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!only_alpha(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (repeated(argv[1]))
    {
        printf("Do not repeat letters.\n");
        return 1;
    }
    else
    {
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        string alpha = "abcdefghijklmopqrstuvwxyz";
        for (int i = 0; i < strlen(plain); i++)
        {
            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]))
                 {
                int j = plain[i] - 'A';
                printf("%c", toupper(argv[1][j]));
                 }
            else if (islower(plain[i]))
             {
                int j = plain[i] - 'a';
                printf("%c", tolower(argv[1][j]));
             }
            }
         else
             {
                printf("%c", plain[i]);
             }
        }
        printf("\n");
        return 0;
    }
}

bool only_alpha(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool repeated(string s)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j != i; j++)
        {
            if (s[i] == s[j])
            {
                return true;
            }
        }
    }
    return false;
}