#include <stdio.h>

int main()
{
    long counter = 63;
    int n = 63;
    int i = 0;

    for (i=1; counter<65535; i++)
    {
        counter = i * n;
        if ((0 == (counter%9)) &&
            (1 == (counter%8)) && 
            (0 == (counter%7)) && 
            (3 == (counter%6)) && 
            (4 == (counter%5)) && 
            (1 == (counter%4))
           ){
            printf("%d\n", counter);
            break;
        } else {
            continue;
        }
    }

    return 0;
}
