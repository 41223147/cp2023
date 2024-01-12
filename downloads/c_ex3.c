#include <stdio.h>
int main()
{
int a = 18, b = 6;
printf( " a == b is %d \n", a == b );
printf( " a > b is %d \n", a > b );
printf( " a < b is %d \n", a < b );
printf( " a >= b is %d \n", a >= b );
printf( " a <= b is %d \n", a <= b );
printf( " a != b is %d \n", a != b );
printf( "\n" );
b = 6;
printf( " a == b is %d \n", a == b );
printf( " a > b is %d \n", a > b );
printf( " a < b is %d \n", a < b );
printf( " a >= b is %d \n", a >= b );
printf( " a <= b is %d \n", a <= b );
printf( " a != b is %d \n", a != b );
return 0;
}