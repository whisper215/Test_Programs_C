#include <stdlib.h>
#include <stdio.h>

int main()
{
    long i = 4461090;
    

    float f = *(float *)&i;

    printf("i = %ld\n", i);
    printf("f = %f\n", f);



    printf("&f = %f\n", *((float *)(&i)));
    printf("&f = %d\n", *((short *)(&i)));
}
