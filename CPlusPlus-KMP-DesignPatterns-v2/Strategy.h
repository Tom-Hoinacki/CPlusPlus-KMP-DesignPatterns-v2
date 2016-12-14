//
//  Strategy.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/13/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Strategy__
#define __CPlusPlus_KMP_DesignPatterns_v2__Strategy__

#include <stdio.h>
#include <iostream>
using namespace std;

class PaymentBehaviour
{
    public:
        virtual void pay() = 0; // Abstract class because of this pure virtual function
};

class PayCredit : public PaymentBehaviour
{
    public:
        void pay()
        {
            cout << "The test credit transaction was successful!" << endl;
        }
};

class PayPayPal : public PaymentBehaviour
{
    public:
        void pay()
        {
            cout << "The test PayPal transaction was successful!" << endl;
        }
};

class Payment
{
    public:
        PaymentBehaviour *payBehaviour;
       
        
        void performPayment()
        {
            payBehaviour->pay();
        }
        
        void setPaymentBehaviour(PaymentBehaviour *pb)
        {
            cout << "Changing payment behaviour..." << endl;
            payBehaviour = pb;
        }
        
        virtual void display() = 0; // Make this an abstract class by having a pure virtual function
};

class Credit : public Payment
{
    public:
        Credit()
        {
            payBehaviour = new PayCredit();
        }
    
        void display() { cout << "Credit test created..."; }
};

class PayPal : public Payment
{
    public:
        PayPal()
        {
            payBehaviour = new PayPayPal();
        }
    
        void display() { cout << "PayPal test created..."; }
};

void testPayment();

#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Strategy__) */
