#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[4] = {1,2,3,4};
    int B[8] = {1,2,2,4,4,5,5,6};

    const int nA = 4, nB = 8;

    const int nC = nA + nB;

    int *C = malloc(nC * sizeof(*C));

    int i = 0, j = 0, k = 0;

    while (k < nC) {
        if (A[i] <= B[j] && i < nA)
            C[k] = A[i++];
        else if (j < nB)
            C[k] = B[j++];
        printf("%d ", C[k++]);
    }

    return 0;
}
