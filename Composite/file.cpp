#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

// Component
class Item {
public:
    virtual double getPrice() const = 0;
    virtual ~Item() = default;
};

// Leaf
class Product : public Item {
private:
    string name;
    double price;

public:
    Product(string name, double price)
        : name(name), price(price) {}

    double getPrice() const override {
        return price;
    }
};

// Composite
class Box : public Item {
private:
    vector<shared_ptr<Item>> children;

public:
    void add(shared_ptr<Item> item) {
        children.push_back(item);
    }

    void remove(shared_ptr<Item> item) {
        auto it = find(children.begin(), children.end(), item);

        if (it != children.end()) {
            children.erase(it);
        }
    }

    double getPrice() const override {
        double total = 0;

        for (const auto& child : children) {
            total += child->getPrice();
        }

        return total;
    }
};

// Client
int main() {
    // Products
    auto laptop = make_shared<Product>("Laptop", 1000);
    auto mouse = make_shared<Product>("Mouse", 50);
    auto keyboard = make_shared<Product>("Keyboard", 100);
    auto headphones = make_shared<Product>("Headphones", 150);

    // Accessories Box
    auto accessoriesBox = make_shared<Box>();

    accessoriesBox->add(keyboard);
    accessoriesBox->add(headphones);

    // Shopping Cart
    auto shoppingCart = make_shared<Box>();

    shoppingCart->add(laptop);
    shoppingCart->add(mouse);
    shoppingCart->add(accessoriesBox);

    cout << "Total price: $" << shoppingCart->getPrice() << endl;

    return 0;
}
