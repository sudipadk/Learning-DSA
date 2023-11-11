/*

// Fibonacci in simple method.
#include<stdio.h>
void fibo();
void main(){
fibo();
}
void fibo(){
int i,a=0,b=1,c=1,n;
	printf("enter the number of terms to be displayed :");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		printf("%d\t",c);	
		c=a+b;
		a=b;
		b=c;
	}
	
}
*/

// Using Recursion

#include<stdio.h>    
void fibonacci(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         fibonacci(n-1);    
    }    
}    
int main(){    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("%d %d ",0,1);    
    fibonacci(n-2); //n-2 because 2 numbers are already printed    
  return 0;  
 }
