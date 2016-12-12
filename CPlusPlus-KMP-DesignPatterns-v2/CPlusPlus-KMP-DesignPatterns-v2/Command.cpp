//
//  Command.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "Command.h"
#include <iostream>  
#include <string>  
using namespace std;

void Receiver::signIn(string name)
{
    cout << "- " << name << " is signing into the website" << endl;
}

void Receiver::viewShoppingCart(string name)
{
    cout << "- " << name << " is viewing their shopping cart" << endl;
}

void Receiver::filterClothing(string name)
{
    cout << "- " << name << " is filtering clothing to view" << endl;
}

void Receiver::makePurchase(string name)
{
    cout << "- " << name << " is making a purchase" << endl;
}



void displayUserActivityLog()
{
    cout << "User Recent Acvitiy Log:" << endl;
    cout << "************************" << endl;
    
    Receiver r;
    
    SignInCommand signInCmd(&r);
    ViewShoppingCartCommand shopCmd(&r);
    FilterClothingCommand filterCmd(&r);
    MakePurchaseCommand purchaseCmd(&r);
    
    Invoker caller1(&signInCmd, "Bobby Bratt");
    caller1.Invoke(caller1.name_);
    
    Invoker caller2(&shopCmd, "Lucy Lowe");
    caller2.Invoke(caller2.name_);
    
    Invoker caller3(&filterCmd, "Fred Ferguson");
    caller3.Invoke(caller3.name_);
    
    Invoker caller4(&purchaseCmd, "Fred Ferguson");
    caller4.Invoke(caller4.name_);
    
    Invoker caller5(&filterCmd, "Lucy Lowe");
    caller5.Invoke(caller5.name_);
    
    Invoker caller6(&shopCmd, "Bobby Bratt");
    caller6.Invoke(caller6.name_);
    
    cout << "\n\n";
}
