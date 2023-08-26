// https://en.cppreference.com/w/cpp/memory/weak_ptr

#ifndef FIBONACCI_MEMOIZATION_HPP
#define FIBONACCI_MEMOIZATION_HPP

#include <unordered_map>
#include <mutex>

class FibonacciMemoization {
public:
    static std::shared_ptr<FibonacciMemoization> getInstance();

    /**
     * Singleton should not be cloneable.
     * 
     * auto object1 = FibonacciMemoization(); // no matchng constructor for initialization of 'FibonacciMemoization'
     * This line creates an instance of the `FibonacciMemoization` class using its constructor and then assigns this newly created instance to the `object1`.
     * This involves both construction and assignment.
     * 
     * FibonacciMemoization object1;
     * FibonacciMemoization object2 = object1; // function "FibonacciMemoization::FibonacciMemoization(FibonacciMemoization &other)" cannot be referenced -- it is a deleted function
     * This line does not create a new instance of the `FibonacciMemoization` class. 
     * Instead, it creates a new variable `object2` and attempts to initialize it by copying the value of `object1`.
     * Without deleting the copy constructor `object2` would be a separate instance that could behave independently of `object1`.
     * 
     * auto object1 = FibonacciMemoization::getInstance();
     * FibonacciMemoization object2 = *object1; // function "FibonacciMemoization::FibonacciMemoization(FibonacciMemoization &other)" cannot be referenced -- it is a deleted function
     * `object2` would be a separate instance that could behave independently of `object1`.
     */
    FibonacciMemoization(FibonacciMemoization &other) = delete;

    /** 
     * Singleton should not be assignable.
     * auto object1 = FibonacciMemoization();
     * auto object2 = FibonacciMemoization();
     * object2 = object1; // function "FibonacciMemoization::operator=(const FibonacciMemoization &)" cannot be referenced - it is a deleted function
     */
    void operator=(const FibonacciMemoization &) = delete;

    FibonacciMemoization();
    ~FibonacciMemoization();

    unsigned long calculate(unsigned n);
private:
    static std::weak_ptr<FibonacciMemoization> instance;
    static std::mutex mutex;

    int id;
    std::unordered_map<unsigned, unsigned> cache;

    unsigned long fibonacci(unsigned n);
};

#endif