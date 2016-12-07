//
//  Adapter.h
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 11/22/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __C___Design_Patterns__Adapter__
#define __C___Design_Patterns__Adapter__

#include <stdio.h>
//#include "AbsFactory_Prototype_Singleton.h"

class LegacyShoppingCart
{
    public:
        void legacyPurchase();
};

// Check out & purchase
void checkOutAndPurchaseShoppingCartItems();


#endif /* defined(__C___Design_Patterns__Adapter__) */
