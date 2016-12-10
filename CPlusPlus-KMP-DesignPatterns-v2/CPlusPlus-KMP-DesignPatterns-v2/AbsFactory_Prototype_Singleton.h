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
#include "Bridge.h"
using namespace std;


class InventoryItem
{
    public:
        string name_;
        vector<string> sizes_;
    
        // Prototype
        virtual InventoryItem* addToCart(string name) = 0;
        // Bridge
        virtual void printSizes();
    
    protected:
        int id_;
        static int total_;
    
        // Bridge
        SizeImp *sizeImp_;
};

class Clothing : public InventoryItem
{
    public:
        Clothing();
        Clothing(string name);
        Clothing(string name, vector<string> sizes, string sizeRegion);
        InventoryItem* addToCart(string name);
        //void printSizes();
        
    protected:
        string sizeRegion_;
};

//class Clothing : public InventoryItem, public Bridge
//{
//    public:
//        Clothing(string name, IImplementSizes* iSizes) : Bridge(iSizes)
//        {
//            name_ = name;
//        }
//        InventoryItem* addToCart(string name);
//        //void printSizes();
//};

class Shoe : public InventoryItem
{
    public:
        Shoe();
        Shoe(string name);
        Shoe(string name, vector<string> sizes, string sizeRegion);
        InventoryItem* addToCart(string name);
        //void printSizes();
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



