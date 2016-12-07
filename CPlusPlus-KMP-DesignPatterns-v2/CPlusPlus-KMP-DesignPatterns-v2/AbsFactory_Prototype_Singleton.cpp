//
//  AbstractFactory.cpp
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 11/27/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "AbsFactory_Prototype_Singleton.h"
#include "Adapter.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* CLOTHING */
Clothing::Clothing(){};

Clothing::Clothing(string name)
{
    name_ = name;
}

// Prototype
InventoryItem* Clothing::addToCart(string name)
{
    return new Clothing(name);
}


/* SHOES */
Shoe::Shoe(){};

Shoe::Shoe(string name)
{
    name_ = name;
}

// Prototpye
InventoryItem* Shoe::addToCart(string name)
{
    return new Shoe(name);
}


/* FACTORY FUNCTIONS */
Clothing* InventoryItemFactory::createClothing(string name)
{
    return new Clothing(name);
}

Shoe* InventoryItemFactory::createShoe(string name)
{
    return new Shoe(name);
}

/* SINGLETON SHOPPING CART */
ShoppingCart* ShoppingCart::s_instance = new ShoppingCart;

ShoppingCart* ShoppingCart::instance()
{
    if (!ShoppingCart::s_instance)
        ShoppingCart::s_instance = new ShoppingCart;
    return ShoppingCart::s_instance;
};

/* CALLS ADAPTER */
void ShoppingCart::purchase()
{
    LegacyShoppingCart* lsc = new LegacyShoppingCart();
    lsc->legacyPurchase();
};



void displayInventory()
{
    InventoryItemFactory factory;
    vector<InventoryItem*> inventory;
    
    inventory.push_back(factory.createClothing("Jacket"));
    inventory.push_back(factory.createClothing("Pants"));
    inventory.push_back(factory.createClothing("Gloves"));
    inventory.push_back(factory.createClothing("Hat"));
    
    inventory.push_back(factory.createShoe("Boots"));
    
    cout << "Current inventory:\n";
    cout << "******************\n";
    
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i+1 << ". " << inventory[i]->name_ << endl;
    }
    
    cout << endl;
}

// Prototype & Singleton
void startShopping()
{
    displayInventory();
    int itemNum;
    Clothing c;
    Shoe shoe;
    
    cout << "Add items to shopping cart, when finished enter 99 to view shopping cart.\n\n";
    
    
    while (itemNum != 99)
    {
        cout << "Add item number: ";
        cin >> itemNum;
        
        while ((itemNum < 1 || itemNum > 5) && itemNum != 99)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please re-enter: ";
            cin >> itemNum;
        }
        
        switch (itemNum)
        {
            case 1:
                ShoppingCart::instance()->cartItems.push_back(c.addToCart("Jacket"));
                break;
            case 2:
                ShoppingCart::instance()->cartItems.push_back(c.addToCart("Pants"));
                break;
            case 3:
                ShoppingCart::instance()->cartItems.push_back(c.addToCart("Gloves"));
                break;
            case 4:
                ShoppingCart::instance()->cartItems.push_back(c.addToCart("Hat"));
            case 5:
                ShoppingCart::instance()->cartItems.push_back(shoe.addToCart("Boots"));
                break;
            default:
                break;
        }
    }
    cout << endl;
    cout << "Shopping cart:" << endl;
    cout << "**************" << endl;
    
    for (int i = 0; i <  ShoppingCart::instance()->cartItems.size(); i++)
    {
        cout <<  ShoppingCart::instance()->cartItems[i]->name_ << endl;
    }
    cout << endl;
}



