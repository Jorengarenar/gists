#include <iostream>
// Directive #include tells compiler where to search for "external" code
// Library iostream contains standard Input-Output (IO), e.g. cout, cin

/*
using namespace std; // Bad practice, don't even learn
*/

/*
using std::cout;
using std::endl;

This is way better, but still not recommended
*/

// Just type std::cout, std::cin, std::endl, std::...

int main() // Function which contains, nomen omen, the main code of program
{ // The start of the new block of code (the body of function in this case)

    std::cout << "Hello World" << std::endl;
    /* Writes on the screen the string Hello World!
       std::endl means, more or less "write new line" */

    return 0; /* Functions usually, just like in math, return something
                 If main() returns 0, then program finished correctly */

} // The end of the block of code (Attention! Curly brackets can be nested!)

/* Comment on comments
   In C++ there are two types of comments:
        * oneline - starts with //, ends with the end of line
        * multiline - like this one
*/
