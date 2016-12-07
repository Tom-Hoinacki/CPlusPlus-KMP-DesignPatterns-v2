//
//  AbstractFactory.h
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 11/27/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>


using namespace std;


class InventoryItem
{
public:
    virtual InventoryItem* addToCart(string name) = 0;
    string name_;
    
protected:
    int id_;
    static int total_;
};

class Clothing : public InventoryItem
{
public:
    Clothing();
    Clothing(string name);
    InventoryItem* addToCart(string name);
};

class Shoe : public InventoryItem
{
public:
    Shoe();
    Shoe(string name);
    InventoryItem* addToCart(string name);
};

class Factory
{
public:
    virtual InventoryItem* createClothing(string name) = 0;
    virtual InventoryItem* createShoe(string name) = 0;
};

class InventoryItemFactory : public Factory
{
public:
    Clothing* createClothing(string name);
    Shoe* createShoe(string name);
};

class ShoppingCart
{
    static ShoppingCart *s_instance;

    public:
        static ShoppingCart *instance();
        vector<InventoryItem*> cartItems;
        void purchase();
};

// Abstract Factory
void displayInventory();

// Prototype & Singleton
void startShopping();



