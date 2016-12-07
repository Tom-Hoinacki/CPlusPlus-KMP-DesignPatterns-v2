////
////  Builder.cpp
////  C++ Design Patterns
////
////  Created by Thomas Hoinacki on 11/30/16.
////  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
////

#include "Builder.h"
#include "AbsFactory_Prototype_Singleton.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Outfit
{
public:
    string name;
    vector<InventoryItem*> outfitItemList;
};

/* Outfit Builder Class */
class OutfitBuilder
{
public:
    /* Abstract functions to build parts */
    virtual void buildHat()=0;
    virtual void buildJacket()=0;
    virtual void buildBoots()=0;
    virtual void buildGloves()=0;
    virtual void buildPants()=0;
    /* The product is returned by this function */
    virtual Outfit* getOutfit()=0;
    virtual void buildOutfit(vector<int> selectionList)=0;
    virtual void displayOutfit()=0;
    
protected:
    InventoryItemFactory factory;
};

/* Concrete class for the builder interface */
class NormalOutfit : public OutfitBuilder
{
private:
    Outfit *outfit;
    
public:
    NormalOutfit()
    {
        outfit = new Outfit();
    }
    
    void buildHat()
    {
        outfit->outfitItemList.push_back(factory.createClothing("Hat"));
    }
    
    void buildJacket()
    {
        outfit->outfitItemList.push_back(factory.createClothing("Jacket"));
    }
    
    void buildGloves()
    {
        outfit->outfitItemList.push_back(factory.createClothing("Gloves"));
    }
    
    void buildPants()
    {
        outfit->outfitItemList.push_back(factory.createClothing("Pants"));
    }
    
    void buildBoots()
    {
        //outfit->outfitItemList.push_back(factory.createShoe("Boots"));
    }
    
    Outfit* getOutfit()
    {
        return this->outfit;
    }
    
    void buildOutfit(vector<int> selectionList)
    {
        vector<InventoryItem*> outfitItemList;
        int selectionType;
        
        for (int i = 0; i < selectionList.size(); i++)
        {
            selectionType = selectionList[i];
            
            switch (selectionType)
            {
                case 1:
                    buildHat();
                    break;
                case 2:
                    buildJacket();
                    break;
                case 3:
                    buildGloves();
                    break;
                case 4:
                    buildPants();
                    break;
                case 5:
                    buildBoots();
                    break;
                default:
                    break;
            }
        }
    }
    
    void displayOutfit()
    {
        cout << endl;
        cout << "Custom Outfit:\n";
        cout << "**************\n";
        
        for (int i = 0; i < this->outfit->outfitItemList.size(); i++)
        {
            cout << outfit->outfitItemList[i]->name_ << endl;
        }
        
        cout << endl;
    }
};

void displayOutfitBuilder()
{
    cout << "Build your custom outfit by entering the number for the inventory item one by one. Enter the number 99 to see your custom outfit item list.\n\n";
    
    displayInventory();
    cout << endl;
    
    int itemNum;
    vector<int> itemNumList;
    
    while (itemNum != 99)
    {
        cout << "Add item to outfit: ";
        cin >> itemNum;
        
        while ((itemNum < 1 || itemNum > 5) && itemNum != 99)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please re-enter: ";
            cin >> itemNum;
        }
        
        itemNumList.push_back(itemNum);
    }
    
    NormalOutfit normOutfit;
    
    normOutfit.buildOutfit(itemNumList);
    normOutfit.displayOutfit();
}