#include <stdio.h>
#include <stdlib.h>

void hanoi (int n, int source, int destination, int inter) // recursive algorithm
{
    //base case
    if(n == 1) // one disc
    {
        printf("Move disc from %d to %d \n", source, destination);

    }
    else // more than 1 disc
    {
        hanoi(n - 1, source, inter, destination);
        printf("Move disc from %d to %d \n", source, destination);
        hanoi(n - 1, inter, destination, source);
    }
}

int main() // main function contains solution for h discs
{
    int h;
    printf("Enter number of discs: \n");
    scanf("%d", &h);
    printf("Solution for %d discs \n", h);
    hanoi(h, 1, 3, 2);
    return 0;
}