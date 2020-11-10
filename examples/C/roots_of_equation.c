// Roots of the equation
//     ~ Jakub "Jorengarenar" Łukasiewicz

// ax^2 + bx + c = 0

#include <stdio.h>
#include <stdlib.h> // Standard library (cointains i.a. malloc() function)
#include <math.h>   // Library with math functions (and "variables")
                    //    ATTENTION: Remember to compile with `-lm` flag!
                    //               (gcc -o example exmaple.c -lm)


/* With the main() function header writter this way
      argc - variable that stores the number of arguments entered in the console
             (it is always >= 1, because the first argument is the path to program)
      argv - two-dimensional char array (C type string). Its size equals `argc`.
             Contains arguments entered in the console, where argv[0] is the
             path to the executable file being run */
int main(int argc, char *argv[])
{
    double a, b, c; // Coefficients of the equation

    if (argc < 4) { /* There are to be three factors, we check if the number
                       of arguments that the user has entered in the console
                       is less than 3+1 ("+1" because argv[0] is the path
                       to the binary file) */

        // If yes, we read the parameters using the scanf() function
        scanf("%lf %lf %lf", &a, &b, &c);
    } else {
        /* If not (ergo user provided all coefficients during the start
           of the program), we "copy" them from the argv[] */
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
        /* The atof() function converts a string literal to a (floating point) number.
           There is also atoi(), atol(), atoll()
             For details, I recommend going to https://cppreference.com */
    }

    if ( a != 0 ) { // If a != 0, then we have quadratic equation
        double d = (b * b) - (4 * a * c); // we calculate the delta
        if (d >= 0) { // Assumption: real numbers are the domain
            d = sqrt(d); /* We overwrite the value of the variable that stores
                            the delta with the value of the root of the delta */
            double x1 = (-b - d) / (2 * a);
            double x2 = (-b + d) / (2 * a);
            printf("%lf %lf\n", x1, x2); /* Even if delta equals 0,
                                            even if x1 == x2,
                                            we still have two roots! */
        } else {
            printf("None\n"); // Delta lesser than zero - no real roots
        }
    } else if ( b != 0 ) { // Linear equation
        int x0 = -b / a;
        printf("%d\n", x0);
    } else if ( c != 0 ) { // No equation
        printf("None\n");
    } else { // Tożsamość
        printf("All real numbers\n");
    }

    return 0;
}
