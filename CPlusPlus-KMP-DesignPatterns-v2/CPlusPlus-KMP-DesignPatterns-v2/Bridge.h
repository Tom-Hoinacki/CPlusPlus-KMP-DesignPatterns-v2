//
//  Bridge.h
//  CPlusPlus-KMP-DesignPatterns-v2
//
//  Created by Thomas Hoinacki on 12/8/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#ifndef __CPlusPlus_KMP_DesignPatterns_v2__Bridge__
#define __CPlusPlus_KMP_DesignPatterns_v2__Bridge__

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class SizeImp
{
    public:
    SizeImp(vector<string> sizes);
    
    virtual void printSizes();
    
    protected:
        vector<string> sizes_;
};

class ClothingSizeImp : public SizeImp
{
    public:
    ClothingSizeImp(vector<string> sizes, string sizeRegion) : SizeImp(sizes){ sizeRegion_ = sizeRegion;; };
        void printSizes();
    
    protected:
        string sizeRegion_;
};

class ShoeSizeImp : public SizeImp
{
    public:
        ShoeSizeImp(vector<string> sizes, string sizeRegion) : SizeImp(sizes) { sizeRegion_ = sizeRegion; };
        void printSizes();
    
    protected:
        string sizeRegion_;
};

void displaySizesForItem();


#endif /* defined(__CPlusPlus_KMP_DesignPatterns_v2__Bridge__) */
