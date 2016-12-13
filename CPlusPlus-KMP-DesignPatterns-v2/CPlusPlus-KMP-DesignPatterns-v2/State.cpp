//
//  State.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/12/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "State.h"


Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

void turnOnAdminPermissions()
{
    Machine fsm;
    (fsm.on)();
    cout << "\n\n";
}

void ON::off(Machine *m)
{
    cout << "Going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}
