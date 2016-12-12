//
//  Command.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/11/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Command__
#define __CPlusPlus_KMP_DesignPatterns_v2__Command__


#include <iostream>
#include <string>
using namespace std;


class Command
{
    public:
        virtual void Execute(string name) = 0;
};


class Receiver
{
    public:
        void signIn(string name);
        void viewShoppingCart(string name);
        void filterClothing(string name);
        void makePurchase(string name);
};


class Invoker
{
    Command *m_command;
    
    public:
        string name_;
        
        Invoker(Command *cmd = 0, string name = "") : m_command(cmd)
        {
            name_ = name;
        }
    
        void Invoke(string name)
        {
            if (0 != m_command)
            {
                m_command->Execute(name);
            }
        }
};


class SignInCommand : public Command
{
    Receiver *m_receiver;
    
    public:
        SignInCommand(Receiver *rcv = 0) : m_receiver(rcv)
        {
        }
        
        virtual void Execute(string name)
        {
            if (0 != m_receiver)
            {
                m_receiver->signIn(name);
            }
        }
};

class ViewShoppingCartCommand : public Command
{
    Receiver *m_receiver;
    
    public:
        ViewShoppingCartCommand(Receiver *rcv = 0) : m_receiver(rcv)
        {
        }
        
        virtual void Execute(string name)
        {
            if (0 != m_receiver)
            {
                m_receiver->viewShoppingCart(name);
            }
        }
};

class FilterClothingCommand : public Command
{
    Receiver *m_receiver;
    
public:
    FilterClothingCommand(Receiver *rcv = 0) : m_receiver(rcv)
    {
    }
    
    virtual void Execute(string name)
    {
        if (0 != m_receiver)
        {
            m_receiver->filterClothing(name);
        }
    }
};

class MakePurchaseCommand : public Command
{
    Receiver *m_receiver;
    
public:
    MakePurchaseCommand(Receiver *rcv = 0) : m_receiver(rcv)
    {
    }
    
    virtual void Execute(string name)
    {
        if (0 != m_receiver)
        {
            m_receiver->makePurchase(name);
        }
    }
};




void displayUserActivityLog();



#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Command__) */
