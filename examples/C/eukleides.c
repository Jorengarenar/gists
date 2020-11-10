// Euclidean algorithm
//     ~ Jakub "Jorengarenar" Łukasiewicz

#include <stdio.h>

int eukleides(int, int); // A prototype of function euklides()

int main()
{
    int a, b;
    printf("First number: ");
    scanf("%d", &a);
    printf("Second number: ");
    scanf("%d", &b);
    printf("gcd(%d, %d) = %d\n", a, b, eukleides(a, b)); /* If function returns
        some value, then we can use it as argument for other function as well */
    return 0;
}

// The actual function definition is after the main() function

int eukleides(int a, int b)
{
    int temp;
    while (b) { // As long as `b` doesn't equal 0
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// SLOWER VERSION
/*
int euklides(int a, int b)
{
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
*/
