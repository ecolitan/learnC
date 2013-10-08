#include <stdio.h>

int main(int argc, char *argv[])
{
    char lower = 'a';
    char *bits[7] = {};
    int i = 0;
    char *bit;

    // Print bits in char 'a'
    printf("Print bits in char 'a'\n");
    for (i = 0; i < 7; i++) {
        bit = lower & (1 << i);
        printf("bit %d: %d\n", i, bit);
    }
    printf("these bits print an '%c'\n", lower);

    // now set bit 5 to a zero
    printf("set bit 5\n");
    lower &= ~(1 << 5);

    // print bits in new char
    printf("Print bits in new char\n");
    for (i = 0; i < 7; i++) {
        bit = lower & (1 << i);
        printf("bit %d: %d\n", i, bit);
    }
    printf("these bits print an '%c'\n", lower);

    return 0;
}
