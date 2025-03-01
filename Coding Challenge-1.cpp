#include <iostream>

std::tuple<std::string, std::string> getClassInfo() {
    std::string className = "Hello World";
    std::string buildingName = ":)";
    return {className, buildingName};
 }

 int main() {
    //direct initialization
    int numOne = 10.0;
    std::cout << "numOne is: " << numOne << std::endl;

    double numTwo = 6.5;
    std::cout << "numTwo is: " << numTwo << std::endl;

    std::string hello = "Hello";
    std::cout << "string: " << hello << std::endl;

    bool bool1 = true;
    std::cout << "bool: " << bool1 << std::endl;

    //uniform initialization
    int numOne{12};
    std::cout << "numOne is: " << numOne << std::endl;

    double numTwo{6.5};
    std::cout << "numTwo is: " << numTwo << std::endl;

    std::string hello{"Hello"};
    std::cout << "string: " << hello << std::endl;

    bool bool1{true};
    std::cout << "bool: " << bool1 << std::endl;

    //structured binding
    auto [className, buildingName] = getClassInfo();
    std::cout << "This is " << className << " , " << buildingName << std::endl;

    //references 
    int& ref = numOne;
    ref = 15;
    std::cout << "new numOne is(references): " << numOne << std::endl; 

    //structured binding
    struct point {
        double x;
        double y;
        double z; 
    };

    point origin {0.0, 0.0, 0.0};
    auto [x, y, z] = origin;
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

    return 0;
 }

