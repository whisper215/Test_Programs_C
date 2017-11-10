#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //printf("input arguments number = %d.\n", argn);
    if (argc == 2) {
        //printf("%s\n", argv[1]);

        printf("\nstring length = %d\n", strlen(argv[1]));
    }

    return 0;
}
