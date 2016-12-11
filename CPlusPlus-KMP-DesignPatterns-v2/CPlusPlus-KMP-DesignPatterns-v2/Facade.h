//
//  Facade.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Facade__
#define __CPlusPlus_KMP_DesignPatterns_v2__Facade__

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class PriceList
{
    public:
        void discountAllItems();
};

class EmailList
{
    public:
        void sendSalePromotionEmails();
};

class SalePromotion
{
    private:
        PriceList priceList_;
        EmailList emailList_;
        
    public:
        void beginSale();
};

void startSalePromotion();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Facade__) */
