#include <stdio.h>
#include <stdlib.h>

void print_one_to_n(int n, int N);

int main()
{
    static int N = 0;
    printf("Enter N: ");
    scanf("%d", &N);

    print_one_to_n(1, N);
}

void print_one_to_n(int n, int N)
{

    if (n == N + 1)
    {
        return;
    }
    else
    {
        printf("%d\n", n);
        print_one_to_n(n + 1, N);
    }
}