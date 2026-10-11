#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    virtual Character* clone() const = 0;
    virtual void display() const = 0;

    virtual ~Character() = default;
};

class Warrior : public Character {
private:
    string name;
    int health;
    string weapon;

public:
    Warrior(string n, int h, string w)
        : name(n), health(h), weapon(w) {}

    Warrior* clone() const override {
        return new Warrior(*this);
    }

    void display() const override {
        cout << "Warrior: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Weapon: " << weapon << endl;
    }
};

class Mage : public Character {
private:
    string name;
    int health;
    int magicPower;

public:
    Mage(string n, int h, int m)
        : name(n), health(h), magicPower(m) {}

    Mage* clone() const override {
        return new Mage(*this);
    }

    void display() const override {
        cout << "Mage: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Magic Power: " << magicPower << endl;
    }
};

int main() {
    Character* warrior = new Warrior("Aragorn", 100, "Sword");
    Character* mage = new Mage("Gandalf", 80, 150);

    Character* warriorCopy = warrior->clone();
    Character* mageCopy = mage->clone();

    cout << "Original Warrior:\n";
    warrior->display();

    cout << "\nCopied Warrior:\n";
    warriorCopy->display();

    cout << "\nOriginal Mage:\n";
    mage->display();

    cout << "\nCopied Mage:\n";
    mageCopy->display();

    delete warrior;
    delete mage;
    delete warriorCopy;
    delete mageCopy;

    return 0;
}
