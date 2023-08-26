#include "fibonacciMemoization.hpp"
#include <iostream>

FibonacciMemoization::FibonacciMemoization() {
    srand(time(0));
    id = rand();
    std::cout << typeid(*this).name() << " " << __func__ << " " << id << "\n\n";
}

FibonacciMemoization::~FibonacciMemoization() {
    std::cout << typeid(*this).name() << " " << __func__ << " " << id << "\n\n";
}

std::weak_ptr<FibonacciMemoization> FibonacciMemoization::instance;
std::mutex FibonacciMemoization::mutex;

std::shared_ptr<FibonacciMemoization> FibonacciMemoization::getInstance() {
    std::shared_ptr<FibonacciMemoization> sp;

    std::lock_guard<std::mutex> lock(mutex);
    if (instance.expired()) {
        sp = std::shared_ptr<FibonacciMemoization>(new FibonacciMemoization);
        instance = sp;
    }

    return instance.lock();
}

unsigned long FibonacciMemoization::calculate(unsigned n) {
    cache.clear();
    return fibonacci(n);
}

unsigned long FibonacciMemoization::fibonacci(unsigned n) {
    if (n < 2)
        return n;

    if (cache.find(n) != cache.end())
        return cache[n];

    unsigned long fib_n = fibonacci(n - 1) + fibonacci(n - 2);
    cache[n] = fib_n;

    return fib_n;
}