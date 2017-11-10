#include <stdlib.h>
#include <stdio.h>

int main()
{
    int32_t o  = -38425;
    uint32_t i = 0;
    int32_t j_1 = 0;
    int32_t j_2 = 0;
    float f_1 = 0;
    float f_2 = 0;

    i = o;

    f_1 = (float)i;
    f_2 = (float)o;

    j_1 = *((int32_t *)(&i));
    j_2 = (int32_t)i;

    printf("f_1 = %f\n", f_1);
    printf("f_2 = %f\n", f_2);
    printf("i = %d\n", i);
    printf("i = %u\n", i);
    printf("j_1 = %u\n", j_1);
    printf("j_2 = %u\n", j_2);

    return 0;
}
