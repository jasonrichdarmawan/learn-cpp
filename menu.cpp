#include <iostream>
#include "mapexample.cpp"
#include "fibonacciexample.cpp"

void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1) Map Example\n";
    std::cout << "2) Fibonacci Example\n";
    std::cout << "3) Fibonacci Memoization Example\n";
    std::cout << "4) Exit\n\n";
}

int chooseNumber() {
    std::cout << "Choose number: ";
    int n;
    std::cin >> n;
    std::cout << "\n";
    return n;
}

void chooseMenu() {
    while (true) {
        printMenu();
        int n = chooseNumber();

        switch (n) {
            case 1:
                mapExample();
                continue;
            case 2:
                fibonacciExample();
                continue;
            case 3:
                fibonacciMemoizationExample();
                continue;
        }
        break;
    }
}