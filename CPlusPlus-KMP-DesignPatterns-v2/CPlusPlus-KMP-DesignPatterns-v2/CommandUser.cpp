//
//  CommandUser.cpp
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "CommandUser.h"

//class User
//{
//    string name_;
//    Command cmd_;
//    
//public:
//    User(string n, Command c): cmd_(c)
//    {
//        name_ = n;
//    }
//    void signIn()
//    {
//        // "this" is the sender, cmd has the receiver
//        cout << name_ << " is signing into the website" << endl;
//        cmd_.execute(); // ask the "black box" to callback the receiver
//    }
//    void viewShoppingCart()
//    {
//        cout << name_ << " is viewing their shopping cart" << endl;
//        
//        // 4. When the sender is ready to callback to the receiver,
//        // it calls execute()
//        cmd_.execute();
//    }
//    void filterClothing()
//    {
//        cout << name_ << " is filtering clothes to view" << endl;
//        cmd_.execute();
//    }
//    void makePurchase()
//    {
//        cout << name_ << " is make a purchase" << endl;
//    }
//};
