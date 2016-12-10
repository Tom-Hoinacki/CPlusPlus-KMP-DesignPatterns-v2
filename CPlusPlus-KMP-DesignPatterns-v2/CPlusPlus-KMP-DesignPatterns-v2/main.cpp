//
//  main.cpp
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 9/6/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.

#include <iostream>
#include <vector>
#include <string>
#include "KMP.h"
#include "AbsFactory_Prototype_Singleton.h"
#include "Builder.h"
#include "Adapter.h"
#include "Bridge.h"

using namespace std;

/* FUNCTION DECLARATIONS */

vector<size_t> knuthMorrisPrattTable(const string & needle);
vector<size_t> knuthMorrisPrattSearch(const string & needle, const string & haystack, const vector<size_t> & table);
void displayMainMenu();


/* GLOBAL VARIABLES */

const int numUsers = 3;
const int numNeedles = 27;


/* MAIN */

int main(int argc, const char * argv[]) {
    displayMainMenu();
    return 0;
}


/* FUNCTIONS */

void displayMainMenu()
{
    /* MAIN MENU */
    int option;
    
    
    /* Store user data after selecting menu option #1. When selecting option #2, if array is not empty then use for getting top navigation page pattern frequencies. */
    // Initialize multidimensional array to store user sessions
    int** userNeedleSums = 0;
    userNeedleSums = new int*[numUsers];
    
    // Intialize possible pattern matches column for each user
    for (int i = 0; i < numUsers; i++)
    {
        userNeedleSums[i] = new int[numNeedles];
    }
    
    cout << "*************************************************\n";
    cout << "*   TOM'S IMAGINARY APPAREL E-COMMERCE WEBSITE  *\n";
    cout << "*************************************************\n";
    cout << "Select menu options to utilize the Knutt-Morris-Pratt string pattern matching algorithm for user page navigation session patterns/frequencies & design patterns (displayed in brackets after selection descriptions) for the navigating the e-commerce store.\n";
    cout << "*************************************************\n";
    
    while (true)
    {
        cout << "\n\n";
        cout << "MAIN MENU\n\n";
        
        cout << "User Navigation Data Menu" << endl;
        cout << "*************************" << endl;
        cout << "1. View all users' page navigation sessions data (re-randomizes each time selected).\n\n(Each page is a letter, the pages are A, B, C.  The order of the letters in the page navigation string is the page order which the user navigated during that session [3 users created, 3 sessions per user, 25 pages navigated per session (randomized page orders)]. Top lists of most frequent patterns for all users and each invidivdual user at end of data display). \n";
        
        cout << "\n\nApparel Inventory & Shopping Menu" << endl;
        cout << "*********************************" << endl;
        cout << "2. View inventory [Abstract Factory]\n";
        cout << "3. Create an outfit [Builder]\n";
        cout << "4. Add items to shopping cart [Prototype & Singleton]\n";
        cout << "5. Checkout and purchase shopping cart items [Adapter]\n";
        cout << "6. Display sizes for an item [Bridge]\n";
        
        cout << "\n\n";
        
        cout << "Enter selection number: ";
        cin >> option;
        
        while (option < 1 || option > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please re-enter: ";
            cin >> option;
        }
        
        cout << "\n\n";
        
        switch (option) {
            case 1:
                userNeedleSums = displayAllUserSessions();
                displayTopNavigationPatterns(userNeedleSums);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                displayOutfitBuilder();
                break;
            case 4:
                startShopping();
                break;
            case 5:
                checkOutAndPurchaseShoppingCartItems();
                break;
            case 6:
                displaySizesForItem();
                break;

            default:
                break;
        }
        
        option = 0;
        
        cout << "Enter 1 to return to main menu: ";
        cin >> option;
        
        while (option != 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please re-enter: ";
            cin >> option;
        }
    }
}