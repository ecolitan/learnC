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

        switch (letter) {
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'Y':
                if (i > 2) {
                    // its only sometimes y
                    printf("%d: 'Y'\n", i);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
