// https://en.cppreference.com/w/cpp/chrono

#include <unordered_map>
#include <iostream>

unsigned long fibonacci(unsigned n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}