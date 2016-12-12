//
//  Iterator.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Iterator__
#define __CPlusPlus_KMP_DesignPatterns_v2__Iterator__

#include <stdio.h>

#include <iostream>
using namespace std;

class InvoiceStackIter;

class InvoiceStack
{
    int sp;
    
    public:
        string items[5];
        friend class InvoiceStackIter;
        InvoiceStack()
        {
            sp =  - 1;
        }
        void push(string description)
        {
            items[++sp] = description;
        }
        string pop()
        {
            return items[sp--];
        }
        bool isEmpty()
        {
            return (sp ==  - 1);
        }
    
        InvoiceStackIter* createIterator()const; // 2. Add a createIterator() member
};


class InvoiceStackIter
{
    // 1. Design an "iterator" class
    const InvoiceStack *stk;
    int index;
    
    public:
        InvoiceStackIter(const InvoiceStack *s)
        {
            stk = s;
        }
        void first()
        {
            index = 0;
        }
        void next()
        {
            index++;
        }
        bool isDone()
        {
            return index == stk->sp + 1;
        }
        string currentItem()
        {
            return stk->items[index];
        }
};



void displayCurrentInvoices();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Iterator__) */
