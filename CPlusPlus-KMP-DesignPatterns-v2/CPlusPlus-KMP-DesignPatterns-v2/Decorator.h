//
//  Decorator.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Decorator__
#define __CPlusPlus_KMP_DesignPatterns_v2__Decorator__

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Shipping
{
    public:
    virtual void createShippingOrder() = 0;
    
};

class ShippingOrder : public Shipping
{
    string containerSize_;
    
    public:
        ShippingOrder(string containerSize);
        void createShippingOrder();
};

class Decorator : public Shipping
{
    Shipping* ship_;
    
    public:
        Decorator(Shipping* ship);
        void createShippingOrder();
};

class WrappingDecorator : public Decorator
{
    public:
        WrappingDecorator(Shipping* s): Decorator(s){}
        void createShippingOrder();
};

class GiftCardDecorator : public Decorator
{
    public:
        GiftCardDecorator(Shipping* s): Decorator(s){}
        void createShippingOrder();
};

void displayDefaultGiftShippingSetting();


#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Decorator__) */
