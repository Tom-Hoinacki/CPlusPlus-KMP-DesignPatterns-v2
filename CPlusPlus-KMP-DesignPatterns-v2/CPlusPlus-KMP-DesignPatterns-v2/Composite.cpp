//
//  Composite.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/10/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Composite.h"

Component::Component(string name, string title)
{
    name_ = name;
    title_ = title;
}

void Worker::printNameAndTitle(int level)
{
    for(int i=0; i < level; ++i)
        cout << "\t";
    
    cout << title_ << " (Worker): " << name_ << endl;
}

void Manager::add(Component* cmp)
{
    children_.push_back(cmp);
}

void Manager::printNameAndTitle(int level)
{
    for(int i=0; i < level; ++i)
        cout << "\t";
    
    cout << title_ << " (Manager): " << name_ << "\n\n";
    
    if (!children_.empty())
    {
        for (int x=0; x < level; ++x)
            cout << "\t";
        
        cout << "Workers for " << title_ << ":\n";
        ++level;
        
        for (int i = 0; i < children_.size(); ++i)
            children_[i]->printNameAndTitle(level);
    }
}

void displayCompanyDirectory()
{
    Manager ceo ("Tom Hoinacki", "CEO");
    
    Worker magicElf1 ("Magic Elf Uno", "Magic Pixel Master");
    Worker magicElf2 ("Magic Elf Dos", "Magic Pattern Master");
    Worker magicElf3 ("Magic Elf Tres", "Magic Profit Master");
    
    ceo.add(&magicElf1);
    ceo.add(&magicElf2);
    ceo.add(&magicElf3);
                      
    cout << "Company directory:" << endl;
    cout << "******************\n\n";
    
    ceo.printNameAndTitle(0);
    
    cout << "\n\n";
}