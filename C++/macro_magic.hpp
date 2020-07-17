// Simple strong typedef
#define STRONG_TYPEDEF(T, D)                                 \
    class D : public T {                                     \
    public:                                                  \
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
