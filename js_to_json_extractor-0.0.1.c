#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    const char* field = "data";

    if (argc > 1) {
        FILE* in  = fopen(argv[1], "r");
        FILE* out = fopen("out.json", "w");
        char c;
        char buf[BUFSIZ];
        int i = 0;

        while (!feof(in)) {
            c = fgetc(in);
            if (c == ' ' || c == '\t' || c == '\n') {
                i = 0;
            } else if (c == ':') {
                buf[i] = '\0';
                if (strcmp(buf, field) == 0) {
                    break;
                }
            } else {
                buf[i] = c;
                ++i;
            }
        }

        int opened = 0;
        while (!feof(in)) {
            c = fgetc(in);
            if (c == '[' || c == '{') {
                ++opened;
            } else if (c == ']' || c == '}') {
                --opened;
                if (opened == 0) {
                    fputc(c, out);
                    break;
                }
            }
            fputc(c, out);
        }

    }
    return 0;
}
