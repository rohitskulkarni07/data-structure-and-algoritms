#include <stdio.h>
#include <stdlib.h>

void print_one_to_n(int N);

int main()
{
    static int N = 0;
    printf("Enter N: ");
    scanf("%d", &N);

    print_one_to_n(N);
}

void print_one_to_n(int N)
{
    if (N == 0)
    {
        return;
    }
    else
    {
        printf("%d\n", N);
        print_one_to_n(N-1);
    }
}