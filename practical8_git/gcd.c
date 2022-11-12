//Euclid's Algorithm

#include <stdio.h>

// initialising functions
int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main()
{
    int a, b, ierror; // including error handling

    printf("Enter two postiive integers \n");
    ierror = scanf("%d %d", &a, &b);
    if(ierror != 2)
    {
        printf("ERROR: Enter two integers!\n");
        return 1;
    }

    if(a<=0 || b<=0) // '||' means 'or'
    {
        printf("ERROR: These numbers are not positive!");
        return 1;
    }

    //Call functions
    printf("Greatest Common Divisor (Iterative)(%d, %d) = %d\n", a, b, iterativeGCD(a, b));
    printf("Greatest Common Divisor (Recursive)(%d, %d) = %d\n", a, b, recursiveGCD(a, b));
    return 0;
}

int iterativeGCD(int a, int b)
{
int temp;
while (b != 0)
{
    temp = b;
    b = a%b;
    a = temp;
    
}
return a;
}

int recursiveGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return(recursiveGCD(b, a%b));
    }
}
