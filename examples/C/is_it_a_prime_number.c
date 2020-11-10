// Is it a prime number?
//     ~ Jakub "Jorengarenar" Łukasiewicz

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a;

    if (argc < 2)
        scanf("%d", &a);
    else
        a = atoi(argv[1]);

    if (a == 0 || a == 1) {
        printf("Not prime");
    } else {
        int i = 2;

        while(a % i != 0)
            i++;

        if (i == a)
            printf("Prime");
        else
            printf("Not Prime");
    }

    return 0;
}
