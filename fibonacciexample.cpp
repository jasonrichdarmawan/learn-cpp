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
    // Before C++20
    std::cout << elapsed_seconds.count() << "s\n\n";
// C++20 alternative
// operator<< chrono::duration
// std::cout << elapsed_seconds << "\n\n"; // C++20:
}

void fibonacciMemoizationExample() {
    const auto start = std::chrono::steady_clock::now();

    srand(time(0));
    int id = rand();

// Singleton should not be cloneable.
// auto object = *FibonacciMemoization::getInstance(id);
// const auto fb = object.calculate(42);
    
    auto object = FibonacciMemoization::getInstance(id);
    const auto fb = object->calculate(42);

    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> elapsed_seconds = end - start;
 
    std::cout << "fibonacci memoization example\n";
    std::cout << "f(42) = " << fb << '\n' << "elapsed time: ";
    std::cout << elapsed_seconds.count() << "s\n\n";
}