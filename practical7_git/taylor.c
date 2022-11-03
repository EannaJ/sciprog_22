#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Finding e using Taylor Expansion

int factorial(int m); //declaring function

int main(void)
{
    int i, order; 
    double e, *terms; //pointer

    printf("Enter polynomial order: \n");
    if (scanf("%d", &order) !=1) // error checking
    {
        printf("ERROR: You did not enter a number!");
        return 1;

    }

    //Creating dynamic array for terms
    terms = malloc(order * sizeof(double));
    for(i = 0; i < order; i++)
    {
        terms[i] = 1.0 / (double)factorial(i+1);
        printf("e term for order %d is %1.14lf\n", order, terms[i]);
    }

    e = 1.0;
    for(i = 0; i < order; i++)
    {
        e = e +terms[i];
    }

    free(terms); //freeing terms from dynamic array to save memory 

    //printing estimation of e compared to actual value
    printf("\nEstimation of e is %.10lf, with difference %.10lf\n", e, e - exp(1.0)); 

    return 0;
}


int factorial(int n)
{
    if (n < 0)
    {
        printf("ERROR : n should be a positive integer!"); // error message if n is negative
        return (-1);
    }
    else if (n == 0)
    {
        return 1; // 0! = 1
    }
    else
    {
        return (n * factorial (n - 1));
    }

}