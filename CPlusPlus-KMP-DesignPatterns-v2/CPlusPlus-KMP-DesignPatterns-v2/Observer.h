//
//  Observer.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Observer__
#define __CPlusPlus_KMP_DesignPatterns_v2__Observer__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer
{
    public:
        virtual void update(int sales, int traffic) = 0;
};

class Subject
{
    int sale_value;
    int traffic_value;
    vector<Observer*> m_views;

    public:
        void attach(Observer *obs)
        {
            m_views.push_back(obs);
        }
        void set_val(int sale, int traf)
        {
            sale_value = sale;
            traffic_value = traf;
            notify();
        }
        void notify()
        {
            for (int i = 0; i < m_views.size(); ++i)
                m_views[i]->update(sale_value, traffic_value);
        }
};

class SalesObserver: public Observer
{
    public:
        SalesObserver(Subject *model)
        {
            model->attach(this);
        }
        /* virtual */void update(int sales, int traf)
        {
            cout << "Sales today: $" << sales << endl;
        }
};

class TrafficObserver: public Observer
{
    public:
        TrafficObserver(Subject *model)
        {
            model->attach(this);
        }
        /* virtual */void update(int sales, int traf)
        {
            cout << "Visitor traffic today: " << traf << endl;
        }
};

void displaySiteStats();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Observer__) */
