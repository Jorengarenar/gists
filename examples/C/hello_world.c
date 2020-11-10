#include <stdio.h>
// Directive #include tells compiler where to search for "external" code
// Library stdio.h contains standard Input-Output (IO), e.g. printf(), scanf()

int main() // Function which contains, nomen omen, the main code of program
{ // The start of the new block of code (the body of function in this case)

    printf("Hello World!\n"); /* Writes on the screen the string Hello World!
                                 The \n means "write new line" */

    return 0; /* Functions usually, just like in math, return something
                 If main() returns 0, then program finished correctly */

} // The end of the block of code (Attention! Curly brackets can be nested!)

/* Comment on comments
   In C there are two types of comments:
        * oneline - starts with //, ends with the end of line
        * multiline - like this one
*/
