//
//  Iterator.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Iterator.h"

InvoiceStackIter *InvoiceStack::createIterator()const
{
    return new InvoiceStackIter(this);
}

void displayCurrentInvoices()
{
    InvoiceStack stack;
    InvoiceStackIter *stackIter = stack.createIterator();
    
    stack.push("Invoice ID: 114568, L Jacket $120");
    stack.push("Invoice ID: 114569, M Pants $45");
    stack.push("Invoice ID: 114570, 6.5 Boots $95");
    stack.push("Invoice ID: 114571, XS Gloves $25");
    stack.push("Invoice ID: 114572, XXL Hat $50");
    
    cout << "Current Invoices:" << endl;
    cout << "*****************" << endl;
    
    while (!stackIter->isDone())
    {
        cout << stackIter->currentItem() << endl;
        stackIter->next();
    }
    
    cout << "\n\n";
}