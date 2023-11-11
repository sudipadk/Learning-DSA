//#include<stdio.h>
//	int sum(int n){
//		if(n==0){
//			return 0;		
//		}
//		else{
//			return n+ sum(n-1);
//		}
//}
//int main(){
//	int limit;
//	printf("Enter the value of n");
//	scanf("")
//}

#include <stdio.h>  
int sum(int n);
 
int main() { 
int n, result;  
printf("Enter a positive integer: ");  
scanf("%d", &n);  
result = sum(n);  
printf("Sum of natural numbers up to %d = %d\n", n, result); 
return 0; 
}
 
int sum(int n) { 
if (n == 1) { 
return 1; 
} 
else { 
return n + sum(n-1); 
} 
}
