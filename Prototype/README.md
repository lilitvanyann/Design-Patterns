# Prototype Design Pattern (C++)

## Description

The Prototype Pattern creates new objects by copying existing objects without depending on their concrete classes.

## Implementation

* **Prototype:** `Character`
* **Concrete Prototypes:** `Warrior`, `Mage`
* **Clone Method:** `clone()` creates a copy using `new Warrior(*this)` or `new Mage(*this)`.

## Key Concepts

* Polymorphism
* Object Cloning
* Copy Constructors
* Virtual Functions

## Benefits

* Copies objects without knowing their concrete types.
* Preserves the original object's type when cloning.
