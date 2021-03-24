#include <stdio.h>
#include <jcbc/pp/overload.h>

int foo(int a, int b, int c)
{
    return a + b + c;
}

#define FOO3(x,y,z) foo(x,y,z)
#define FOO2(x,y)   FOO3(x,y,2)
#define FOO1(x)     FOO2(x,2)
#define FOO0()      FOO1(2)

#define foo(...) JCBC_PP_OVERLOAD(FOO, __VA_ARGS__)

int goo(int x, int b, int h)
{
    return 2;
}

#define GOO3(x,y,z) goo(x,y,z)
#define GOO2(x,y)   GOO3(x,y,2)

#define goo(...) JCBC_PP_OVERLOAD(GOO, __VA_ARGS__)

int main()
{
    printf("%d\n", foo());
    printf("%d\n", foo(1));
    printf("%d\n", goo(1,1));
    printf("%d\n", foo(1,1,1));
    return 0;
}
