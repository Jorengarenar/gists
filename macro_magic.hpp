// Simple strong typedef
#define STRONG_TYPEDEF(T, D)                                 \
    struct D : public T {                                    \
        template<class... A> explicit D(A... a) : T(a...) {} \
        const T& raw() const { return *this; }               \
    }

// Use the block of code following the macro in the macro
#define BLOCK(var) \
    for (bool flag = true; flag; ) \
        for (typeof(var) foo = var; flag; flag = false)


// Alternative version of above
#define BLOCK2(var) \
    if (typeof(var) foo = var; false) {} else

// Array size (only in the same or sub scope)
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
