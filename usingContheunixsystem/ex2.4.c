#include <stdio.h>

int fact(int n);

int main(void)
{
    int n, m;
    printf("Enter a number: ");
    scanf("%d", &n);

    m = fact(n);

    printf("The factorial of %d is %d.\n", n, m);
    return 0;
}

int fact(int n) 
{
    if (n == 0) {
        return 1;
    }

    return (n * fact(n -1));
}
