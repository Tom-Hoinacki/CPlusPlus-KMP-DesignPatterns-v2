//
//  ChainOfResponsibility.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "ChainOfResponsibility.h"

ShippingHandler::ShippingHandler()
{
    next_ = 0;
}

void ShippingHandler::setNext(ShippingHandler* sh)
{
    next_ = sh;
}

void ShippingHandler::add(ShippingHandler* sh)
{
    if (next_)
        next_->add(sh);
    else
        next_ = sh;
}

void ShippingHandler::handle(int i, string region)
{
    next_->handle(i, region);
}

void USAShippingHandler::handle(int i, string region)
{
    if (region != "USA")
    {
        cout << "Shipping handler responsibility passed to next handler for package ID: " << i << endl;
        ShippingHandler::handle(i, region);
    }
    else
        cout << "USA Shipping handled for package ID: " << i << endl;
}

void EuroShippingHandler::handle(int i, string region)
{
    if (region != "Euro")
    {
        cout << "Shipping handler responsibility passed to next handler for package ID: " << i << endl;
        ShippingHandler::handle(i, region);
    }
    else
        cout << "Euro Shipping handled for package ID: " << i << endl;
}

void displayHandledShipment()
{
    USAShippingHandler root;
    EuroShippingHandler two;
    
    root.add(&two);
    two.setNext(&root);
    
    cout << "Shipping log - 5 orders:" << endl;
    cout << "***********************" << endl;
    
    for (int i = 1; i < 6; i++)
    {
        if (i % 2)
            root.handle(i, "USA");
        else
            root.handle(i, "Euro");
    }
    
     cout << "\n\n";
}
