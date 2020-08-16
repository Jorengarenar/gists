// Multi command macro
#define TEST(/* variables */) do { /* code */ } while(0)

// Remove '\n' after `fgets()`
#define REMOVE_NL(buffer) \
    buffer[strcspn(buffer, "\n")] = '\0'

// Max of two
#define MAX(a, b)           \
    ({ typeof(a) _a = a;    \
       typeof(b) _b = b;    \
       _a > _b ? _a : _b; })

// Min of two
#define MIN(a, b)           \
    ({ typeof(a) _a = a;    \
       typeof(b) _b = b;    \
       _a < _b ? _a : _b; })
