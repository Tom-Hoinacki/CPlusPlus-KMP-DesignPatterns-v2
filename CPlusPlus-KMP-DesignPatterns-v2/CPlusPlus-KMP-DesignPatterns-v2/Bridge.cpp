//
//  Bridge.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/8/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Bridge.h"
#include "AbsFactory_Prototype_Singleton.h"

#include <iostream>

SizeImp::SizeImp(vector<string> sizes)
{
    sizes_ = sizes;
}

void SizeImp::printSizes()
{
    cout << "\nThe sizes available are: " << endl;
    
    for (int i=0; i < sizes_.size(); i++)
    {
        cout << sizes_[i] << endl;
    }
    
    cout << "\n\n";

}

void ClothingSizeImp::printSizes()
{
    cout << "\nThe" << " " << sizeRegion_ << " clothing sizes available are: " << endl;
    
    for (int i=0; i < sizes_.size(); i++)
    {
        cout << sizes_[i] << endl;
    }
    
    cout << "\n\n";
}

void ShoeSizeImp::printSizes()
{
    cout << "\nThe" << " " << sizeRegion_ << " shoe sizes available are: " << endl;
    
    for (int i=0; i < sizes_.size(); i++)
    {
        cout << sizes_[i] << endl;
    }
    
    cout << "\n\n";
}



void displaySizesForItem()
{
    int itemNum;
    
    displayInventory();
    
    cout << "\n\n";
    cout << "Choose an item to display available sizes: ";
    cin >> itemNum;
    
    if (itemNum >= 1 && itemNum <= 4)
    {
        vector<string> sizes = { "XXS", "XS", "S", "M", "L", "XL", "XXL" };
        
        Clothing* c = new Clothing("", sizes, "U.S.");
        c->printSizes();
    }
    else if (itemNum == 5)
    {
        vector<string> sizes = { "5", "5.5", "6", "6.5", "7", "7.5", "8" };
        
        Shoe* s = new Shoe("", sizes, "UK");
        s->printSizes();
    }
}