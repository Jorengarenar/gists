#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if __STDC_VERSION__ < 199901L
#   define restrict
#endif

int readValues(const char* restrict,
               const char* restrict,
               void (*)(),
               const char* restrict,
               ...);

int readValues(const char* restrict prompt,
               const char* restrict errMsg,
               void (*eofFunc)(),
               const char* restrict fmt,
               ...)
{
    int n = 0;
    va_list vars;
    va_start(vars, fmt);

    char p = 0;
    for (int i = 0; fmt[i]; ++i) {
        if (fmt[i] == '%' && p != '\\') {
            ++n;
        }
        p = fmt[i];
    }

    puts(prompt);

    int flag = vscanf(fmt, vars);
    while (flag != n && flag != EOF) {
        getchar();
        fputs(errMsg, stderr);
        flag = vscanf(fmt, vars);
    }

    va_end(vars);

    if (flag == EOF) {
        eofFunc();
        putchar('\n');
        exit(0);
    }

    return flag;
}