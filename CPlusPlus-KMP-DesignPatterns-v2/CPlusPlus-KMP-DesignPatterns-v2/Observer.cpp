//
//  Observer.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Observer.h"

void displaySiteStats()
{
    cout << "Daily Store Stats:" << endl;
    cout << "******************" << endl;
    
    Subject subj;
    SalesObserver salesObs(&subj);
    TrafficObserver trafficObs(&subj);
    subj.set_val(3458, 8678);
    
    cout << "\n\n";
}