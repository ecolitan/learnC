#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "ERROR: You need one argument.\n");
        // THis is how you abort a program
        return 1;
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        letter &= ~(1 << 5);

        if (letter == 'A') {
            printf("%d: 'A'\n", i);
        } else if (letter == 'E') {
            printf("%d: 'E'\n", i);
        } else if (letter == 'I') {
            printf("%d: 'I'\n", i);
        } else if (letter == 'O') {
            printf("%d: 'O'\n", i);
        } else if (letter == 'U') {
            printf("%d: 'U'\n", i);
        } else if (letter == 'Y') {
            if (i > 2) {
                // its only sometimes y
                printf("%d: 'Y'\n", i);
            }
        } else {
            printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
