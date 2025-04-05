#include <iostream>
#include <string>

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

