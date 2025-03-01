#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>

// Coding Challenge: Inventory Management System using C++ Containers

// Task 1: Managing Products with std::map
    void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

    // Funtion to add a new product
    void addnew(std::map<std::string, int>& inventory,  const std::string& productName, int quantity) {
    // if the product exist then put a new quantity 
    inventory[productName] += quantity;
    // if the product doesnt exist then add new 
    inventory.insert({productName,quantity});
    std::cout<< "Added" << productName << "to the inventory.\n";
}

    // Function to update the quantity of a product
    void update(std::map<std::string, int>& inventory, const std::string& productName, int quantity){
    if (inventory.count(productName)){
        int quantity = inventory[productName];
        std::cout << "Updated " << productName << ".\n";
    }
    else{
        std::cout << "Product " << productName << " not found in inventory.\n";
    }
}

    int main() {
    std::map<std::string, int> inventory;

    // Adding products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;

    displayInventory(inventory);

    // Adding products
    addnew(inventory, "Apple", 6);
    addnew(inventory,"Laptop", 3); // product that exist

    displayInventory(inventory);

    // Updating products
    update(inventory, "Mouse", 13);
    update(inventory, "Rice", 5); // product that doesnt exist

    displayInventory(inventory);

    return 0;
}


// Task 2: Tracking Unique Products with std::set
    // Function to add a new category
    void addcategory(std::set<std::string>& categories, const std::string& category){
        auto newcat = categories.insert(category);
        if (newcat.second){
            std::cout << "Category '" << category << "' added\n";
        }
        else{
            std::cout << "Category '" << category << "' already exists.\n";
        }
    }
    
    // Function o display all categories
    void displayCategories(const std::set<std::string>& categories) {
        std::cout << "Product Categories:\n";
        for (const auto& category : categories) {
        std::cout << "- " << category << "\n";
    }
    }

    int main() {
    std::set<std::string> productCategories;

    // Adding categories
    productCategories.insert("Electronics");
    productCategories.insert("Accessories");
    productCategories.insert("Peripherals");

    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }

    // Adding new 
    addcategory(productCategories, "Fruits");

    // Display
    displayCategories(productCategories);

    return 0;
    }


//Task 3: Processing Orders with std::queue
    // Function to add a new order 
    void newOrder(std::queue<std::string>& orders, const std::string& order){
        orders.push(order);
        std::cout << "Added: " << order << std::endl;
    }

    // Function to process an order(remove from the queue)
    void process(std::queue<std::string>& orders) {
        while (!orders.empty()) {
            std::cout << "Processing " << orders.front() << std::endl;
            orders.pop();
        }
    }

    int main() {
    std::queue<std::string> orders;

    // Adding orders
    orders.push("Order#1: Laptop");
    orders.push("Order#2: Mouse");
    orders.push("Order#3: Keyboard");

    // Processing orders
    while (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    }

    // Adding a new order 
    newOrder(orders, "Order#4: Apple");

    // Processing orders 
    process(orders);

    return 0;
    }


// Task 4: Handling Restocks with std::stack
    // Function to add a restock batch
    void addRestock (std::stack<std::pair<std::string, int>>& restocks, const std::string& product, int quantity) {
        restocks.push(std::make_pair(product, quantity));
        std::cout << "Added " << product << std::endl;
    }

    // Fuction to process a restock batch
    void processB(std::stack<std::pair<std::string, int>>& restocks) {
        while (!restocks.empty()) {
            auto item = restocks.top();
            std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
            restocks.pop();
        }
    }

    int main() {
    std::stack<std::pair<std::string, int>> restocks;

    // Adding restock batches
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});

    // Processing restocks
    while (!restocks.empty()) {
        auto item = restocks.top();
        std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
        restocks.pop();
    }

    // Adding restock
    addRestock(restocks,"Apple",15);

    // Processing restock
    processB(restocks);

    return 0;
    }


// Task 5: Storing Customer Purchases with std::vector
    // Function to add items to a customer's cart
    void addItems(std::vector<std::string>& cart, const std::string& item){
        cart.push_back(item);
        std::cout << "Added: " << item << " to the cart\n";
    }

    // Function to display the items in the cart
    void displayItems(const std::vector<std::string>& customerCart) {
        std::cout << "Items in customer cart:\n";
        for (const auto& item : customerCart) {
            std::cout << "- " << item << "\n";
        }
    }

    int main() {
        std::vector<std::string> customerCart;
    
        // Adding items to cart
        customerCart.push_back("Laptop");
        customerCart.push_back("Mouse");
        customerCart.push_back("Keyboard");
    
        std::cout << "Items in customer cart:\n";
        for (const auto& item : customerCart) {
            std::cout << "- " << item << "\n";
        }

        // Adding items to cart 
        addItems(customerCart,"Apple");

        // Display the items
        displayItems(customerCart);
    
        return 0;
    }
