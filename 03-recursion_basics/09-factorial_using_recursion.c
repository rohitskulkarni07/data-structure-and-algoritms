#include <stdio.h>
#include <stdlib.h>

unsigned long long int fact(unsigned long long int);

int main(void)
{

    unsigned long long int N = 0;
    printf("Enter the number to find the factorial: ");
    scanf("%llu", &N);
    unsigned long long int result = fact(N);
    printf("%llu\n", result);

    return (0);

}

unsigned long long int fact(unsigned long long int N)
{
    return (N == 0) ? 1 : (N * fact(N - 1));
}