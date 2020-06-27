// #ifndef UTILS_H
// #define UTILS_H
// #include <random>
// #include <chrono>

// namespace Utils {
// 	float randomGauss(float mean, float d);
// }

// #endif// UTILS_H

class E
{
public:
    struct X
    {
        int v;
    };

    // 1. (a) Instantiate an 'X' within 'E':
    X x;
};

int main()
{
    // 1. (b) Modify the 'x' within an 'E':
    E e;
    e.x.v = 9;

    // 2. Instantiate an 'X' outside 'E':
    E::X x;
    x.v = 10;
}