# Composite Design Pattern

## Overview
Composite is a structural design pattern that allows us to
treat individual objects and groups of objects uniformly.

## Example: Shopping Cart
A shopping cart can contain individual products and boxes.
Each box can contain products or other boxes.

## Structure
- **Component (Item):** Defines the common interface.
- **Leaf (Product):** Returns its own price.
- **Composite (Box):** Stores items and calculates their total price.
- **Client:** Works with all objects through the Item interface.

## Advantages
- Simplifies working with tree structures.
- Supports the Open/Closed Principle.
- Reduces dependency on concrete classes.

## Disadvantages
- Can make simple systems more complex.
- Difficult to restrict component types.

## Key Idea
Treat individual objects and collections of objects
through the same interface.

## Category
Structural Design Pattern
