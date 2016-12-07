
//
//  Adapter.cpp
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 11/22/16.
//  Copyright (c) 2016
//Thomas Hoinacki. All rights reserved.
//
//
#include "Adapter.h"
#include "AbsFactory_Prototype_Singleton.h"
#include <string>
#include <iostream>

/* ADAPTER PATTERN */
//Store implements a newly desired interface to purchase items from the store that implements a legacy purchasing system


//Legacy component
void LegacyShoppingCart::legacyPurchase()
{
    if (ShoppingCart::instance()->cartItems.size() == 0)
    {
        cout << "Your shopping cart is empty, no purchases were made!\n";
        cout << "****************************************************\n";
        return;
    }
  
    cout << "Your purchase is complete! Here is what you bought:\n\n";
    
    for (int i = 0; i < ShoppingCart::instance()->cartItems.size(); i++)
    {
        cout << ShoppingCart::instance()->cartItems[i]->name_ << endl;
    }
    
    cout << endl;
    ShoppingCart::instance()->cartItems.clear();
}

// Adapter wrapper
class ShoppingCartAdapter: public ShoppingCart, private LegacyShoppingCart
{
public:
    ShoppingCartAdapter():
    LegacyShoppingCart() {}
    
    virtual void purchase()
    {
        legacyPurchase();
    }
};

// Adapter used to call legacy purchase function
void checkOutAndPurchaseShoppingCartItems()
{
    ShoppingCart* s = new ShoppingCartAdapter;
    s->purchase();
}