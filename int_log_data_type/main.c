#include <stdio.h>

int main()
{
    printf("AKM Test %%u  0xFFFFFFFF = %u\n",  (0xFFFFFFFF));
    printf("AKM Test %%d  0xFFFFFFFF = %d\n",  (0xFFFFFFFF));
    printf("AKM Test %%ld 0xFFFFFFFF = %ld\n", (0xFFFFFFFF));
    printf("AKM Test %%lu 0xFFFFFFFF = %lu\n", (0xFFFFFFFF));
    printf("AKM Test %%lld 0xFFFFFFFF = %lld\n", (0xFFFFFFFF));
    printf("AKM Test %%llu 0xFFFFFFFF = %llu\n", (0xFFFFFFFF));

    printf("AKM Test %%u  0xFFFFFFFF + 1 = %u\n",  (0xFFFFFFFF + 1));
    printf("AKM Test %%d  0xFFFFFFFF + 1 = %d\n",  (0xFFFFFFFF + 1));
    printf("AKM Test %%ld 0xFFFFFFFF + 1 = %ld\n", (0xFFFFFFFF + 1));
    printf("AKM Test %%lu 0xFFFFFFFF + 1 = %lu\n", (0xFFFFFFFF + 1));
    printf("AKM Test %%lld 0xFFFFFFFF + 1 = %lld\n", (0xFFFFFFFF + 1));
    printf("AKM Test %%llu 0xFFFFFFFF + 1 = %llu\n", (0xFFFFFFFF + 1));

    printf("AKM Test %%u  0xFFFFFFFF + 1 = %u\n",  (0xFFFFFFFF + (int64_t)1));
    printf("AKM Test %%d  0xFFFFFFFF + 1 = %d\n",  (0xFFFFFFFF + (int64_t)1));
    printf("AKM Test %%ld 0xFFFFFFFF + 1 = %ld\n", (0xFFFFFFFF + (int64_t)1));
    printf("AKM Test %%lu 0xFFFFFFFF + 1 = %lu\n", (0xFFFFFFFF + (int64_t)1));
    printf("AKM Test %%lld 0xFFFFFFFF + 1 = %lld\n", (0xFFFFFFFFFF));
    printf("AKM Test %%llu 0xFFFFFFFF + 1 = %llu\n", (0xFFFFFFFFFF));


    printf("AKM Test %%lu 0xFFFFFFFF + 1 = %lu\n", 68719476735);
    printf("AKM Test %%lu 0xFFFFFFFF + 1 = %llu\n", 68719476735);

    printf("AKM Test %%llu 0xFFFFFFFFFFFFFFF = %llu\n", (0xFFFFFFFFFFFFFFF0));
    printf("AKM Test %%lld 0xFFFFFFFFFFFFFFF = %llu\n", (0xFFFFFFFFFFFFFFF0));
    
    printf("AKM Test %u\n", (sizeof(int32_t)));
    printf("AKM Test %u\n", (sizeof(int64_t)));
    printf("AKM Test %u\n", (sizeof(uint32_t)));
    printf("AKM Test %u\n", (sizeof(uint64_t)));


    uint32_t h_8_bytes = 0;
    uint32_t l_8_bytes = 0;

    h_8_bytes = (20000000000 & 0xFFFFFFFF00000000) >> 32;
    l_8_bytes = (20000000000 & 0x00000000FFFFFFFF);
    printf("AKM Test h_8_bytes = 0x%lx\n", h_8_bytes);
    printf("AKM Test l_8_bytes = 0x%lx\n", l_8_bytes);

    int64_t time_1 = 70004311298;
    int64_t time_2 = 70004311627;
    printf("%f, %f\n", (float)time_1, (float)time_2);



    return 0;
}
