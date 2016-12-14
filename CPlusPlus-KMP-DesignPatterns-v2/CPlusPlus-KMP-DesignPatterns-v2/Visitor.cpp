//
//  Visitor.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/13/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Visitor.h"

void USAWarehouse::accept(Visitor *v)
{
    v->visit(this);
}

void UKWarehouse::accept(Visitor *v)
{
    v->visit(this);
}

void warehouseReport()
{
    cout << "Warehouse Capacity Report:" << endl;
    cout << "**************************" << endl;
   
    Warehouse *usa = new USAWarehouse;
    Warehouse *uk = new UKWarehouse;
    CallVisitor call_operation;

    usa->accept(&call_operation);
    uk->accept(&call_operation);
    
    cout << endl << endl;
}