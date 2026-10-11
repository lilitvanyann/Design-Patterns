#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int speed;

public:
    Car(string m, int s) : model(m), speed(s) {}

    void display() const {
        cout << "Model: " << model << endl;
        cout << "Speed: " << speed << endl;
    }
};

int main() {
    Car car1("BMW", 200);

    // Copy car1 into car2
    Car car2 = car1;

    car1.display();
    car2.display();

    return 0;
}
