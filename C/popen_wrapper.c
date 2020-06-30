// gets only ONE line!
char* popen_wrapper(const char* restrict cmd)
{
    static char* output;
    FILE* temp = popen(cmd, "r");
    fscanf(temp, "%m[^\n]", &output);
    pclose(temp);
    return output;
}