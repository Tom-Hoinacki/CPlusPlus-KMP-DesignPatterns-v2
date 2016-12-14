//
//  Visitor.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/13/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Visitor__
#define __CPlusPlus_KMP_DesignPatterns_v2__Visitor__

#include <stdio.h>
#include <iostream>
using namespace std;

class Warehouse
{
    public:
        virtual void accept(class Visitor*) = 0;
};

class USAWarehouse: public Warehouse
{
    public:
        /*virtual*/void accept(Visitor*);
        void usaCapacity()
        {
            cout << "USA warehouse at 77% storage capacity\n";
        }
};

class UKWarehouse: public Warehouse
{
    public:
        /*virtual*/void accept(Visitor*);
        void ukCapacity()
        {
            cout << "UK warehouse at 52% storage capacity\n";
        }
};

class Visitor
{
    public:
        virtual void visit(USAWarehouse*) = 0;
        virtual void visit(UKWarehouse*) = 0;
};


class CallVisitor: public Visitor
{
    public:
        /*virtual*/void visit(USAWarehouse *usa)
        {
            usa->usaCapacity();
        }
        /*virtual*/void visit(UKWarehouse *uk)
        {
            uk->ukCapacity();
        }
};

void warehouseReport();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Visitor__) */
