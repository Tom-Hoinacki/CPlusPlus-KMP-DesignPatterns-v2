//
//  Composite.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Composite__
#define __CPlusPlus_KMP_DesignPatterns_v2__Composite__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
    public:
        Component(string name, string title);
        virtual void printNameAndTitle(int level) = 0;
        string name_;
        string title_;
};

class Worker : public Component
{
    public:
        Worker(string name, string title) : Component(name, title){}
        void printNameAndTitle(int level);
};

class Manager : public Component
{
    public:
        Manager(string name, string title) : Component(name, title){}
        void add(Component* cmp);
        void printNameAndTitle(int level);

    private:
        vector<Component*> children_;
};

void displayCompanyDirectory();


#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Composite__) */
