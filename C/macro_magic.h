// Multi command macro
#define TEST(/* variables */) do { /* code */ } while(0)

// Remove '\n' after `fgets()`
#define REMOVE_NL(buffer) \
    buffer[strcspn(buffer, "\n")] = '\0'
