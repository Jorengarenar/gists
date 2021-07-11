#include <stdio.h>

struct foo_ { int x; int y; float z; };
void foo(struct foo_* args)
{
    int x   = args->x;
    float z = args->z;

    printf("%d %d %f\n", x, args->y, z);
}
#define foo(...) foo(&(struct foo_){ __VA_ARGS__ })

int main()
{
    foo(.y = 12, .x = -2, .z = 0.2);
    foo(12, -2, 0.2);
    return 0;
}
