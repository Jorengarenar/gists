// "Sorting" three variables
//     ~ Jakub "Jorengarenar" Łukasiewicz

// It isn't really sorting. It's just printing them in sorted way

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double a, b, c;

    if (argc < 2) {
        scanf("%lf %lf %lf", &a, &b, &c);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }

    if (a <= b && a <= c) {
        printf("%lf ", a);
        if (b <= c)
            printf("%lf %lf\n", b, c);
        else
            printf("%lf %lf\n", c, b);
    } else if (b <= a && b <= c) {
        printf("%lf ", b);
        if (a <= c)
            printf("%lf %lf\n", a, c);
        else
            printf("%lf %lf\n", c, a);
    } else {
        printf("%lf ", c);
        if (a <= b)
            printf("%lf %lf\n", a, b);
        else
            printf("%lf %lf\n", b, a);
    }

    return 0;
}
