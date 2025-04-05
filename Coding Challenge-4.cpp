#include <iostream>
#include <string>
#include <concepts>

using namespace std;

//Task 1.1: Simple Template Function
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maxValue(5, 10) << endl; // Should print 10
    cout << maxValue(3.5, 2.1) << endl; // Should print 3.5
    cout << maxValue(string("apple"), string("orange")) << endl; // Should print "orange"
    return 0;
}


//Task 1.2: Overload a Template Function
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(a, maxValue(b, c));
}

int main() {
    cout << maxValue(1, 5, 3) << endl;          // Should print 5
    cout << maxValue(2.1, 3.7, 1.9) << endl;    // Should print 3.7
    return 0;
}


//Task 2.1: Create a Template with a Concept
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << std::endl;       // Should print 7
    std::cout << add(2.5, 3.1) << std::endl;   // Should print 5.6
    // std::cout << add("a", "b");              // Should fail at compile time
    return 0;
}

//Task 3.1: Write a Variadic Template Function
template <typename T>
void printAll(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    std::cout << t << " ";
    printAll(args...);
}

int main() {
    printAll(1, 2.5, "Hello", 'c'); // Should print: 1 2.5 Hello c
    return 0;
}


//Task 3.2: Variadic Template for Summation
template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;             // Should print 15
    std::cout << sum(1.1, 2.2, 3.3) << std::endl;             // Should print 6.6
    return 0;
}


//Task 4.1: Compile-Time Factorial Using Templates
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    constexpr int result = Factorial<5>::value;
    std::cout << result << std::endl;  // Should print 120
    return 0;
}


//Task 4.2: Fibonacci Series Using Template Metaprogramming
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    constexpr int result = Fibonacci<10>::value;
    std::cout << result << std::endl; // Should print 55
    return 0;
}