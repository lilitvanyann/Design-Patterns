#include <iostream>
#include <string>
using namespace std;

class Chair {
    public:
        virtual void sitOn() = 0;
        virtual ~Chair() = default;
};

class Sofa {
    public:
        virtual void lieOn() = 0;
        virtual ~Sofa() = default;
};

class Table {
    public:
        virtual void use() = 0;
        virtual ~Table() = default;
};

//Modern

class ModernChair:public Chair {
    public:
        void sitOn() override {
            cout << "Sitting on Modern Chair\n";
        }
};

class ModernSofa:public Sofa {
    public:
        void lieOn() override {
            cout << "Lie on Modern Sofa\n";
        }
};

class ModernTable:public Table {
    public:
        void use() override {
            cout << "use Modern Table\n";
        }
};

//Victorian

class VictorianChair:public Chair {
    public:
        void sitOn() override {
            cout << "Sitting on Victorian Chair\n";
        }
};

class VictorianSofa:public Sofa {
    public:
        void lieOn() override {
            cout << "Lie on Victorian Sofa\n";
        }
};

class VictorianTable:public Table {
    public:
        void use() override {
            cout << "use Victorian Table\n";
        }
};

class FurnitureFactory{
    public:
        virtual Chair* createChair()=0;
        virtual Sofa* createSofa()=0;
        virtual Table* createTable()=0;
        
        virtual ~FurnitureFactory() = default;

};

class ModernFactory:public FurnitureFactory {
    public:
        Chair* createChair() override{
            cout << "Modern Chair was created\n";
                return new ModernChair();
        }
        
        Sofa* createSofa() override{
            cout << "Modern Sofa was created\n";
                return new ModernSofa();
        }
        
        Table* createTable() override{
            cout << "Modern Table was created\n";
                return new ModernTable();
        }
};

class VictorianFactory:public FurnitureFactory {
    public:
        Chair* createChair() override{
            cout << "Victorian Chair was created\n";
                return new VictorianChair();
        }
        
        Sofa* createSofa() override{
            cout << "Victorian Sofa was created\n";
                return new VictorianSofa();
        }
        
        Table* createTable() override{
            cout << "Victorian Table was created\n";
                return new VictorianTable();
        }
};

int main() {
    FurnitureFactory* factory = new VictorianFactory();
    Chair* chair = factory->createChair();
    Sofa* sofa = factory->createSofa();
    Table* table = factory->createTable();
    
    chair->sitOn();
    sofa->lieOn();
    table->use();
    
    delete table;
    delete sofa;
    delete chair;
    delete factory;

    return 0;
}
