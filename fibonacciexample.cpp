#include <chrono>
#include <iostream>

#include "fibonacci.cpp"
#include "fibonacciMemoization.hpp"

void fibonacciExample() {
    const auto start = std::chrono::steady_clock::now();
    const auto fb = fibonacci(42);
    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> elapsed_seconds = end - start;
 
    std::cout << "fibonacci example\n";
    std::cout << "f(42) = " << fb << '\n' << "elapsed time: ";
    std::cout << elapsed_seconds.count() << "s\n\n"; // Before C++20
// std::cout << elapsed_seconds << "\n\n"; // C++20: operator<< chrono::duration
}

void fibonacciMemoizationExample() {
    const auto start = std::chrono::steady_clock::now();

    // example A pf the unexpected usage.
    FibonacciMemoization object;
    const auto fb = object.calculate(42);

// example B of the unexpected usage.
// auto object = new FibonacciMemoization();
// const auto fb = object->calculate(42);
    
// the expected usage
// auto object = FibonacciMemoization::getInstance();
// const auto fb = object->calculate(42);

    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> elapsed_seconds = end - start;
 
    std::cout << "fibonacci memoization example\n";
    std::cout << "f(42) = " << fb << '\n' << "elapsed time: ";
    std::cout << elapsed_seconds.count() << "s\n\n";

// example B of the unexpected usage.
// need to explicitly call destructor after use due to use of the `new` keyword.
// delete object;
}