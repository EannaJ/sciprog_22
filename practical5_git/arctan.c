#include <stdio.h>
#include <math.h>

double arctanh1(const double x, const double delta);

double arctanh2(const double x);

int main()
{
    double delta, x;

    printf("Enter the precision for the MacLaurin series \n");
    scanf("%lf", &delta);

    //setting up array to store results of arctanh1 and arctanh2 for each x
    int length1 = 1000;
    double tan1[length1];
    double tan2[length1];

    int j = 0; //array index
    x = -0.9;
    while (x<= 0.9 && j < length1)   //while loop to calculate difference between two formulae
    {
        tan1[j] = arctanh1(x, delta);
        tan2[j] = arctanh2(x);
        printf("The difference at x = %lf between them is %.10lf\n", x, fabs(tan1[j] - tan2[j]));
        j++;
        x = x + 0.01;
    }


    return 0;
}

double arctanh1(const double x, const double delta)
{

    double arctan = 0; //approximate result
    double elemt, val;
    int n = 0; //some parameter
    do 
    {
        val = 2 * n + 1; //shortcut to reduce typing and make it modular
        elemt = pow(x, val)/ val;
        arctan +=elemt; //sum formula
        n++; //incrementing n

    } while(fabs(elemt) >= delta);
    
    return arctan;
    
    
}

double arctanh2(const double x)
{
    return(log(1 + x) - log(1 - x)/2);
}