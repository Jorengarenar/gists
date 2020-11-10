#include <stdio.h>

/* It's not truly a deletion, as it isn't dynamic array.
   True deletion will be covered in another example */

/* In this example, the word 'iterator' is used in
   the meaning 'the index variable used to iterate' */

int main()
{
    int arr[] = { 1,1,2,2,4,4,5,5,6,6 };

    /* simple trick to get the length of an array, when declaration is in the same scope */
    int n = sizeof(arr)/sizeof(*arr);

    int i = 0; /* iterator throigh "original" */
    int j = 0; /* iterator throigh "filtered" */

    while (i < n) { /* will iterate through "original" */
        if (arr[i] != arr[i-1]) { /* if current value is different from previous */
            arr[j] = arr[i]; /* value was different, so it get's set at the last position of "filtered" array */
            ++j; /* increment "filtered's" iterator */
        } /* If value was the same, it gets skipped over */
        ++i; /* increment "orginal's" iterator */
    }

    n = j; /* set "new size" of array */

    /* print "filtered" */
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
