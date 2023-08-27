// https://en.cppreference.com/w/cpp/memory/weak_ptr
// https://refactoring.guru/design-patterns/singleton/cpp/example#example-1

#ifndef FIBONACCI_MEMOIZATION_HPP
#define FIBONACCI_MEMOIZATION_HPP

#include <unordered_map>
#include <mutex>

class FibonacciMemoization {
public:
    static std::shared_ptr<FibonacciMemoization> getInstance(int id);

    /**
     * Singleton should not be cloneable.
     * 
     * auto object1 = *FibonacciMemoization::getInstance(); // function "FibonacciMemoization::FibonacciMemoization(FibonacciMemoization &other)" cannot be referenced -- it is a deleted function
     * It creates a new variable `object1` and attempts to initialize it by copying the return value of `FibonacciMemoization::getInstance()`
     * Without deleting the copy constructor `object1` would be a separate instance.
     */
    FibonacciMemoization(FibonacciMemoization &other) = delete;

    ~FibonacciMemoization();

    unsigned long calculate(unsigned n);
private:
    static std::weak_ptr<FibonacciMemoization> instance;
    static std::mutex mutex;

    FibonacciMemoization(int id);

    int id;
    std::unordered_map<unsigned, unsigned> cache;

    unsigned long fibonacci(unsigned n);
};

#endif