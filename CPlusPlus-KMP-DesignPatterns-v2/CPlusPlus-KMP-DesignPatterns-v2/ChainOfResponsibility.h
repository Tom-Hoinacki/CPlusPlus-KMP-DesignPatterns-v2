//
//  ChainOfResponsibility.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__ChainOfResponsibility__
#define __CPlusPlus_KMP_DesignPatterns_v2__ChainOfResponsibility__

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class ShippingHandler
{
    ShippingHandler* next_;
    
    public:
        ShippingHandler();
        void setNext(ShippingHandler* sh);
        void add(ShippingHandler* sh);
        virtual void handle(int i, string region);
};

class USAShippingHandler : public ShippingHandler
{
    public:
        void handle(int i, string region);
    
};

class EuroShippingHandler : public ShippingHandler
{
    public:
        void handle(int i, string region);
    
};

void displayHandledShipment();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__ChainOfResponsibility__) */
