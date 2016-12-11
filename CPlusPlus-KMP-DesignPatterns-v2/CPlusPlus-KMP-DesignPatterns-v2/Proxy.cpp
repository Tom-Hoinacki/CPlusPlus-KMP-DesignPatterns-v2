//
//  Proxy.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Proxy.h"

GiftCashProtected::GiftCashProtected()
{
    balance_ = 1025;
}

int GiftCashProtected::getBalance()
{
    return balance_;
}

GiftCash::GiftCash()
{
};

int GiftCash::getBalance()
{
    return realCash_.getBalance();
}

void displayGiftCardCashAvailable()
{
    GiftCashProtected gcp;
    GiftCash gc;
    
    cout << "Total gift card cash available:" << endl;
    cout << "*******************************" << endl;
    cout << "$" << gc.getBalance() << endl;
    cout << "\n\n";
}