//
//  KMP.cpp
//  C++ Design Patterns
//
//  Created by Thomas Hoinacki on 12/4/16.
//  Copyright (c) 2016 Thomas Hoinacki. All rights reserved.
//

#include "KMP.h"
#include <vector>
#include <iostream>
using namespace std;

/* FILE VARIABLES */

/* Needles: Navigation page order possibilites to match on, each character represents a unique page */
const string needles[] = { "AAA", "AAB", "AAC", "ABA", "ABB", "ABC", "ACA", "ACB", "ACC",
    "BAA", "BAB", "BAC", "BBA", "BBB", "BBC", "BCA", "BCB", "BCC", "CAA", "CAB", "CAC", "CBA", "CBB",
    "CBC", "CCA", "CCB", "CCC" };
const int numNeedles = sizeof(needles)/sizeof(*needles);
const int numUsers = 3;



/* FUNCTIONS */

//http://joelverhagen.com/blog/2011/11/three-string-matching-algorithms-in-c/
vector<size_t> knuthMorrisPrattTable(const string & needle)
{
    const string myStr = needle;
    
    vector<size_t> table(needle.size() + 1, -1);
    for(size_t index = 1; index <= needle.size(); index++)
    {
        size_t position = table[index - 1];
        
        while(position != -1 && needle[position] != needle[index - 1])
            position = table[position];
        
        table[index] = position + 1;
    }
    
    return table;
}


vector<size_t> knuthMorrisPrattSearch(const string & needle, const string & haystack, const vector<size_t> & table)
{
    vector<size_t> matches;
    size_t haystackIndex = 0;
    size_t needleIndex = 0;
    
    size_t haystackSize = haystack.size();
    size_t needleSize = needle.size();
    
    while(haystackIndex < haystackSize)
    {
        while(needleIndex != -1 && (needleIndex == needleSize || needle[needleIndex] != haystack[haystackIndex]))
            needleIndex = table[needleIndex];
        
        needleIndex++;
        haystackIndex++;
        
        if(needleIndex == needleSize)
            matches.push_back(haystackIndex - needleSize);
    }
    
    return matches;
}


int** displayAllUserSessions()
{
    // Match table for needle
    vector<size_t> table;
    
    // Haystacks: randomized creation of 3 user navigation sessions, 10 pages navigated in each session
    const int numSessions = 3;
    const int pagesNavigated = 25;
    const int needleLength = 3;
    
    
    // Haystack - Session that has page navigation data to match inside
    string haystack;
    
    // Page navigation pattern matches data recording local variables (users, sessions, matches)
    vector< vector< vector<vector<size_t> > > > users;
    users.resize(numUsers);
    
    vector< vector<vector<size_t> > > sessions;
    sessions.resize(numSessions);
    
    vector< vector<size_t> > sessionMatches;
    sessionMatches.resize(numNeedles);
    
    // Initialize multidimensional array to store user sessions
    int** userNeedleSums = 0;
    userNeedleSums = new int*[numUsers];
    
    // Intialize possible pattern matches column for each user
    for (int i = 0; i < numUsers; i++)
    {
        userNeedleSums[i] = new int[numNeedles];
    }
    
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numNeedles; j++)
        {
            userNeedleSums[i][j] = 0;
        }
    }
    
    // Assign vectors to array elements to store session matches for each user
    for (int i = 0; i < numUsers; i++)
    {
        users[i] = sessions;
        
        for (int j = 0; j < numSessions; j++)
        {
            users[i][j] = sessionMatches;
        }
    }
    
    
    
    
    /*============================================================*/
    /* CREATE AND DISPLAY ALL USERS' SESSION PAGE NAVIGATION DATA */
    /* 3 USERS                                                    */
    /* 3 SESSIONS PER USER                                        */
    /* 25 PAGES NAVIGATED PER SESSION                             */
    /*============================================================*/
    srand(time(NULL));
    vector<size_t> needleMatches;
    
    for (int userIndex = 0; userIndex < numUsers; userIndex++)
    {
        std::cout << "\n\nUSER " << userIndex+1 << ":\n";
        
        /* CREATE A SINGLE USER'S SESSION HISTORY */
        for (int sessionIndex = 0; sessionIndex < numSessions; sessionIndex++)
        {
            // Clear haystack (session page navigation) & matches list
            haystack = "";
            
            // Create random 25 page navigation session record (haystack)
            for (int i = 0; i < pagesNavigated; i++)
            {
                haystack += 'A' + rand() % needleLength;
            }
            
            std::cout << "\n\nSession " << sessionIndex+1 << " [" << haystack << "]:\n\n";
            
            
            // Find frequency of each possible 3-page navigation pattern match and record
            for (int needleMatchIndex = 0; needleMatchIndex < numNeedles; needleMatchIndex++)
            {
                table = knuthMorrisPrattTable(needles[needleMatchIndex]);
                needleMatches = knuthMorrisPrattSearch(needles[needleMatchIndex], haystack, table);
                users[userIndex][sessionIndex][needleMatchIndex] = needleMatches;
                
                if (needleMatches.size() > 0)
                {
                    std::cout << needles[needleMatchIndex] << " (" << needleMatches.size() << " match(es) session index(es)";
                    
                    for (int m  = 0; m < needleMatches.size() ; m++)
                    {
                        std::cout << " [" << needleMatches[m] << "]";
                    }
                    
                    cout << ")\n";
                    userNeedleSums[userIndex][needleMatchIndex] += needleMatches.size();
                }
            }
        }
    }
    cout << "\n\n";
    
    return userNeedleSums;
}



void displayTopNavigationPatterns(int** userNeedleSums)
{
    const int numTopNeedlesList = 3;
    string tempNeedles;
    int tempMax;
    int currentMax;
    int needleIndex;
    bool firstTopNeedle = true;
    int topThreeNeedlePatterns[numUsers][numTopNeedlesList];
    int totalNeedleSums[numNeedles]= {0};
    
    
    /* DISPLAY TOP 3 NAVIGATION PATTERNS FOR ALL USERS */
    /***************************************************/
    
    /* SUM ALL NEEDLE PATTERN OCCURENCES FOR ALL USERS INTO SINGLE COLUMN TOTAL ARRAY */
    for (int needleIndex = 0; needleIndex < numNeedles; needleIndex++)
    {
        for (int userIndex = 0; userIndex < numTopNeedlesList; userIndex++)
        {
            totalNeedleSums[needleIndex] += userNeedleSums[userIndex][needleIndex];
        }
    }
    
    cout <<"*Note: More than one pattern listed per top place denotes a tie. The number in parentheses denotes the number of occurences found.\n\n";
    
    cout <<"Top 3 page navigation patterns for all users:\n";
    cout <<"*********************************************\n\n";
    
    tempMax = 0;
    currentMax = 0;
    
    for (int topNeedleIndex = 0; topNeedleIndex < numTopNeedlesList; topNeedleIndex++)
    {
        while (tempMax == currentMax)
        {
            // Get next top number of needle matches for all users
            tempMax = *max_element(totalNeedleSums, totalNeedleSums + numNeedles);
            
            if (tempMax < currentMax)
            {
                break;
            }
            
            // Get index of needle to be able to retrieve its string
            needleIndex = distance(totalNeedleSums, max_element(totalNeedleSums, totalNeedleSums + numNeedles));
            // Zero-out needle index's matches number value so next max may be found
            totalNeedleSums[needleIndex] = 0;
            
            // If first iteration to find max, store needle string
            if (firstTopNeedle)
            {
                currentMax = tempMax;
                tempNeedles = needles[needleIndex];
                firstTopNeedle = false;
            }
            /*
             If there is another top needle that has the same number of matches, append needle string to previously saved needles with same number of matches
             */
            else if (tempMax == currentMax)
                tempNeedles += ", " + needles[needleIndex];
        }
        
        // Needle frequency found is in next spot down in Top 3, print needles at current top spot before searching for next spot
        cout << "#" << topNeedleIndex+1 << ": " << tempNeedles << " (" << currentMax << ")\n";
        currentMax = tempMax;
        tempNeedles = needles[needleIndex];
        firstTopNeedle = true;
    }
    
    
    /* DISPLAY TOP 3 PAGE NAVIGATION PATTERNS FOR EACH USER */
    cout << "\n\nTop 3 page navigation patterns for each user:\n";
    cout << "*********************************************\n";
    
    tempNeedles = "";
    tempMax = 0;
    currentMax = 0;
    firstTopNeedle = true;
    
    for (int userIndex = 0; userIndex < numUsers; userIndex++)
    {
        cout << "\nUser " << (userIndex+1) << ":\n";
        
        for (int topNeedleIndex = 0; topNeedleIndex < numTopNeedlesList; topNeedleIndex++)
        {
            while (tempMax == currentMax)
            {
                // Get next top number of needle matches for a user
                tempMax = *max_element(userNeedleSums[userIndex], userNeedleSums[userIndex] + numNeedles);
                
                if (tempMax < currentMax)
                {
                    break;
                }
                
                // Get index of needle to be able to retrieve its string
                needleIndex = distance(userNeedleSums[userIndex], max_element(userNeedleSums[userIndex], userNeedleSums[userIndex] + numNeedles));
                // Zero-out needle index's matches number value so next max may be found
                userNeedleSums[userIndex][needleIndex] = 0;
                
                //If first iteration to find max, store needle string
                if (firstTopNeedle)
                {
                    tempNeedles = needles[needleIndex];
                    currentMax = tempMax;
                    firstTopNeedle = false;
                }
                /*
                 If there is another top needle that has the same number of matches, append needle string to previously saved needles with same number of matches
                 */
                else if (tempMax == currentMax)
                    tempNeedles += ", " + needles[needleIndex];
            }
            
            /* Needle frequency found is in next spot down in Top 3, print needles at current top spot before searching for next spot */
            cout << "#" << topNeedleIndex+1 << ": " << tempNeedles << " (" << currentMax << ")\n";
            currentMax = tempMax;
            tempNeedles = needles[needleIndex];
            firstTopNeedle = true;
        }
    }
    cout << "\n\n";
}

