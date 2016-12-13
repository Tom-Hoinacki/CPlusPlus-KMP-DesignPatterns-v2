//
//  State.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/12/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__State__
#define __CPlusPlus_KMP_DesignPatterns_v2__State__

#include <stdio.h>

#include <iostream>
using namespace std;
class Machine
{
    class State *current;
    
    public:
        Machine();
        void setCurrent(State *s)
        {
            current = s;
        }
        void on();
        void off();
};

class State
{
    public:
        virtual void on(Machine *m)
        {
            cout << "   already ON\n";
        }
        virtual void off(Machine *m)
        {
            cout << "   already OFF\n";
        }
};


class ON: public State
{
    public:
        ON()
        {
            cout << ", employee now has admin capabilities!";
        };
        ~ON()
        {
            cout << "   dtor-ON\n";
        };
        void off(Machine *m);
};


class OFF: public State
{
    public:
        OFF()
        {
            cout << "Admin permissions OFF for employee...";
        };
        ~OFF()
        {
            //cout << "   dtor-OFF\n";
        };
        void on(Machine *m)
        {
            cout << "Going from OFF to ON";
            m->setCurrent(new ON());
            delete this;
        }
};


void turnOnAdminPermissions();



#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__State__) */
