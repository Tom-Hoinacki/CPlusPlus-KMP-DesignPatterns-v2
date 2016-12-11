//
//  Decorator.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Decorator.h"

ShippingOrder::ShippingOrder(string containerSize)
{
    containerSize_ = containerSize;
}

void ShippingOrder::createShippingOrder()
{
    cout << "* Shipping container is a " << containerSize_ << endl;
}

Decorator::Decorator(Shipping* ship)
{
    ship_ = ship;
}

void Decorator::createShippingOrder()
{
    ship_->createShippingOrder();
}

void WrappingDecorator::createShippingOrder()
{
    Decorator::createShippingOrder();
    cout << "* Gift is wrapped" << endl;
}

void GiftCardDecorator::createShippingOrder()
{
    Decorator::createShippingOrder();
    cout << "* Gift card placed inside package" << endl;
}

void displayDefaultGiftShippingSetting()
{
    Shipping* ship = new GiftCardDecorator(new WrappingDecorator(new ShippingOrder("large box")));
    ship->createShippingOrder();
    cout << "\n\n";
}

