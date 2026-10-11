# Abstract Factory Pattern (C++)

## Description

The Abstract Factory Pattern creates families of related objects without specifying their concrete classes.

## Implementation

* **Abstract Products:** Chair, Sofa, Table
* **Concrete Products:** Modern and Victorian furniture
* **Abstract Factory:** FurnitureFactory
* **Concrete Factories:** ModernFactory, VictorianFactory

## Key Benefits

* Separates object creation from client code.
* Ensures related products belong to the same family.
* Makes adding new product families easier.
