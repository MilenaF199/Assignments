#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <chrono>  

//Part 1: Introduction to Copy vs. Move
    
    // Task 1.1 Reading and Discussion
    int main() {
        std::vector<int> v1 = {1, 2, 3, 4};
        std::vector<int> v2 = v1;        // Copy
        std::vector<int> v3 = std::move(v1); // Move
    
        std::cout << "v1 size: " << v1.size() << std::endl;
        std::cout << "v2 size: " << v2.size() << std::endl;
        std::cout << "v3 size: " << v3.size() << std::endl;
    
        return 0;
    }
    /**
    Questions:
    What is the output of this program?
        The output will be: 
        v1 size: 0
        v2 size: 4
        v3 size: 4
    Why does v1.size() return 0 after the move?
        v1.size() return 0 because std::move(v1) move all the elements in v1 to v3
        then v1 will be empty.  

    What does std::move do?
        std::move is a function to convert a variable to a rvalue.

    Why is v1 still in a valid but unspecified state?
        After to std::move, v1 can be reused but this doesnt guarantee what the 
        new content will be 
    */


// Part 2: Implementing Move Semantics
    class Buffer {
        private:
            int* data;
            size_t size;
        
        public:
            Buffer(size_t s) : size(s), data(new int[s]) {
                std::cout << "Constructor called\n";
            }
        
            ~Buffer() {
                delete[] data;
                std::cout << "Destructor called\n";
            }
        
            // Copy constructor and assignment operator
            Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
                std::copy(other.data, other.data + other.size, data);
                std::cout << "Copy constructor called\n";
            }

            Buffer& operator=(const Buffer& other) {
                if (this != &other) {
                    delete[] data;
                    size = other.size;
                    data = new int[size];
                    std::copy(other.data, other.data + size, data);
                    std::cout << "Copy assignment called\n";
                }
                return *this;
            }
        
            // Move constructor and move assignment operator
            Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
                other.data = nullptr;
                other.size = 0;
                std::cout << "Move constructor called\n";
            }

            Buffer& operator=(Buffer&& other) noexcept {
                if (this != &other) {
                    delete[] data;
                    data = other.data;
                    size = other.size;
                    other.data = nullptr;
                    other.size = 0;
                    std::cout << "Move assignment called\n";
                }
                return *this;
            }
        };


// Part 3: Using Your Class
    int main() {
        Buffer b1(10);  
        Buffer b2 = b1;
        Buffer b3 = std::move(b1); 

        Buffer b4(60);
        b4 = b2; 
        b4 = std::move(b2);

        return 0;
    }

    /**
     * Questions:
     * What constructors and assignments are called and when?
     *   First is called the constructor Buffer b1(10), then copy and move this 
     *   constructor, then we call the next constructor Buffer b4(50).
     */


// Part 4: Performance Comparison
int main() {
    const size_t bufferSize = 10'000'000;

    std::cout << "\n--- Measuring Copy ---\n";
    Buffer original(bufferSize);

    auto start_copy = std::chrono::high_resolution_clock::now();
    Buffer copy = original;  // Copy constructor
    auto end_copy = std::chrono::high_resolution_clock::now();

    std::cout << "Copy duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_copy - start_copy).count()
              << " ms\n";

    std::cout << "\n--- Measuring Move ---\n";
    auto start_move = std::chrono::high_resolution_clock::now();
    Buffer moved = std::move(original);  // Move constructor
    auto end_move = std::chrono::high_resolution_clock::now();

    std::cout << "Move duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_move - start_move).count()
              << " ms\n";

    return 0;
}
