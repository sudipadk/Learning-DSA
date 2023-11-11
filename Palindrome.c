
/*

// in normal way

#include <stdio.h>
#include <string.h>
int main()
{
  char a[100], b[100];

  printf("Enter a string to check if it's a palindrome\n");
  gets(a);

  strcpy(b, a);  // Copying input string
  strrev(b);  // Reversing the string

  if (strcmp(a, b) == 0)  // Comparing input string with the reverse string
    printf("The string is a palindrome.\n");
  else
    printf("The string isn't a palindrome.\n");

  return 0;
}
*/

// Using recursion

#include <stdio.h>
#include <string.h>
 
void palindrome(char [], int);
 
int main()
{
    char string[15];
 
    printf("Enter A String: ");
    scanf("%s", string);
    palindrome(string, 0);
 
    return 0;
}
 
void palindrome(char string[], int index)
{
    int len = strlen(string) - (index + 1);
    if (string[index] == string[len])
    {
        if (index + 1 == len || index == len)
        {
            printf("The Given String Is A Palindrome\n");
            return;
        }
        palindrome(string, index + 1);
    }
    else
    {
        printf("The Given String Is Not A Palindrome\n");
    }
}
