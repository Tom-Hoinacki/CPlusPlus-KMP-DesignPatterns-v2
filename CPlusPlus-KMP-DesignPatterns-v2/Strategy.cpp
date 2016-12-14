//
//  Strategy.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/13/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Strategy.h"

void testPayment()
{
    cout << "Test Payment System:" << endl;
    cout << "*******************" << endl;
    
    Payment *credit = new Credit();
    credit->performPayment();
    
    Payment *paypal = new PayPal();
    paypal->performPayment();
    
    cout << endl << endl;
}