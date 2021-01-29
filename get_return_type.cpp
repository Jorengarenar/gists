#include <iostream>

namespace test {

int foobar(int a, int b, int c)
{
    return a + b + c;
}

namespace {

template<typename R, typename ... Args>
static R return_type_of(R (*)(Args...));

} // namespace

inline decltype(return_type_of(foobar)) foo()
{
    return foobar(1,2,3);
}

} // namespace test

int main()
{
    std::cout << test::foo() << std::endl;
    return 0;
}
