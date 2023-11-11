/**
 * C program to find nth Fibonacci term using recursion
 */

#include <stdio.h>

/* Function declaration */

void main(){

int fibo(int);
    int num;
    
    /* Input a number from user */
    printf("Enter any number to find nth fiboacci term: ");
    scanf("%d", &num); 
    
    printf("Fibonacci series up to %d number is : ", num);

int i;
    for ( i = 1; i <=num; i++)
    {
        printf("%d\t",fibo(i));
    }
    
}


/**
 * Recursive function to find nth Fibonacci term
 */
int fibo(int f) 
{
    if(f == 1 || f==2)      //Base condition
        return 1;

    else 
        return fibo(f-1) + fibo(f-2); 
}