#include <string.h>

int count_unique(const char* str)
{
    int count = 0;
    while (*str != '\0') {
        if (!strchr(str + 1, *str)) {
            count++;
        }
        str++;
    }
    return count;
}