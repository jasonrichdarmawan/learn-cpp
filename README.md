# Usage

```
g++ -std=c++11 main.cpp fibonacciMemoization.cpp -o main && ./main
```

# To Do

- [ ] prevent initializing `FibonacciMemoization` class except with the `FibonacciMemoization::getInstance()` function.
    - [ ] prevent initializing with `FibonacciMemoization* object1 = new FibonacciMemoization();`
    - [ ] prevent initializing with `FibonacciMemoization object1;`
    - [x] prevent initializing with `auto object1 = FibonacciMemoization();`
- [ ] prevent copying `FibonacciMemoization` class to initialize new instance.
    - [x] prevent copying with
        ```
        auto object1 = FibonacciMemoization::getInstance();
        FibonacciMemoization object2 = *object1;
        ```