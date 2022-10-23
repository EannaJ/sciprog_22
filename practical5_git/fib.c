#include <stdio.h>
#include <stdlib.h>

// input arguments (a = f(n-1) and b = f(n-2))
void fibonacci(int *a, int *b);

int main()
{
    int n, i;
    int fib_1 = 1, fib_0 = 0;

    printf("Enter a positive integer n\n");
    scanf("%d", &n);

    if (n<1)
    {
        printf("This number is not positive\n");
        exit(1); // won't execute the rest of the statements
    }

    printf("The Fibonacci sequence is: \n");
    printf("%d, %d", fib_0, fib_1); // prints first two values

    for (i = 2; i <= n; i++) //increment for loop
    {
        fibonacci(&fib_1, &fib_0);
        printf("%d, ", fib_1);

        if (((i+1)%10) == 0) printf("\n");
    }

    

    return 0;
}

void fibonacci(int *a, int *b) // "*"" declares pointer
{
    int next; // next: f(n)
    next = *a + *b;

    // on exit, a and b are updated
    *b = *a;
    *a = next;
}