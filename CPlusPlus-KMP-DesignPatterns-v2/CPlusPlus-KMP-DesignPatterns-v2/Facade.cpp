//
//  Facade.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Facade.h"

void PriceList::discountAllItems()
{
    cout << "* All items have been discounted by 20%" << endl;
}

void EmailList::sendSalePromotionEmails()
{
    cout << "* Sale promotion email template sent to all users successfully" << endl;
}

void SalePromotion::beginSale()
{
    cout << "Sale promotion now in effect:" << endl;
    cout << "*****************************" << endl;
    priceList_.discountAllItems();
    emailList_.sendSalePromotionEmails();
    cout << "\n\n";
}

void startSalePromotion()
{
    SalePromotion sale;
    sale.beginSale();
}