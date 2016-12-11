//
//  Proxy.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Proxy__
#define __CPlusPlus_KMP_DesignPatterns_v2__Proxy__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class GiftCashProtected
{
    int balance_;
    
    public:
        GiftCashProtected();
        int getBalance();
};

class GiftCash
{
    GiftCashProtected realCash_;
    
    public:
        GiftCash();
        int getBalance();
};

void displayGiftCardCashAvailable();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Proxy__) */
