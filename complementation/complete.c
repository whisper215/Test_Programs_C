
#include <stdio.h>

void main(int argc, char** argv)
{
    int i = 0;

    int sz = 9;

    for (i=0; i<sz*sz; i++)
    {
        printf("i = %d, quotient = %d, compelement = %d\n", i, i/sz, i%sz);
    }

    return;
}
