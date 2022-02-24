
#include<stdio.h>
void swap (int , int) ;
int main()
{
    int a= 5 ;
     int b = 7 ;

 swap (a,b) ;

    return 0 ;

}
 void swap ( int a, int b ) {
     printf(" the value of a and b before swap : %d and %d\n " , a, b) ;
    int temp ;
    temp= a;
    a = b;
    b=temp ;
    printf(" the value of a and b after  swap : %d and %d\n " , a, b) ;


 }