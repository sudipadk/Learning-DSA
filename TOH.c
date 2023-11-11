#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

    void TOH (int,char,char,char);
        void main(){
            int n;
            printf("Enter the number of disks: ");
            scanf("%d",&n);
        
        TOH(n,'A','B','C');
    getch();

}

    void TOH (int n,char A,char B,char C){
        if(n>0){
            TOH(n-1,A,C,B);
            printf("Move disks %d from %c to %c\n",n,A,B);

            TOH(n-1,C,A,B);
        }
    }