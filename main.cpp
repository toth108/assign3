#include "GenStack.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib> 
#include <algorithm>

using namespace std; 

// I talked to you in class that I misunderstood the directions about the classes/files asked for
// I tried to break this up into more classes but had to rework too many things and 
// wouldn't have had time to fix all the errors so I had to go back to this one

// define constructor class (I know this is weird but this is just how I got it to work)
template<class ST> GenStack<ST>::GenStack(int maxSize)
{
    if(maxSize <1) 
    {
        cout << "Please enter a number greater than 0." << endl; 
    }
	else
    {
	    myArray = new ST(maxSize);
	    size = maxSize;
	    top = -1;
	}
}

int main (int argc, char **argv)
{
    bool run; 
    
    // do while loop to run check additional files 
    do {
    
    // get file from user 
    fstream inFile; 

    cout << "Please enter a file path to the code file you would like to check: " << endl; 
    string filePath;
    cin >> filePath; 

    inFile.open(filePath); 
    while (!inFile.is_open()) 
    {
        cout << "File cannot be found, name a new path." << endl; 
        string newPath; 
        cin >> newPath; 
        inFile.open(newPath);
    }

    // initialize variables 
    string lineString; 
    int lineNum = 1; 
    char curr; 
    char left;
    char right; 

    // create new stack 
    GenStack<char> myStack(30);

    // build stack from file 
    while(getline(inFile, lineString))
    {
        // iterate through each char of line in file 
        for (int i = 0; i <= lineString.size(); i++)
        {
            curr = lineString[i];

            // left delimiters 
            if (curr == '{')
            {
                myStack.push(curr);
            }
            if (curr == '[')
            {
                myStack.push(curr);
            }
            if (curr == '(') 
            {
                myStack.push(curr);
            }
            // right delimiters 
            if (curr == '}')
            {
                left = myStack.pop();
                right = curr;
            }
            if (curr == ']')
            {
                left = myStack.pop();
                right = curr;
            }
            if (curr == ')') 
            {
                left = myStack.pop();
                right = curr;
            }
            else 
            {
                continue; 
            }
        }
        lineNum++; 
    }

    // check if any delimiters are missing from built stack
    if (myStack.isEmpty() != 1)
    {
            bool match = myStack.checkMatch(left, right); 

            if (match == false)
            {
                cout << "Error at line: " << lineNum << endl; 
                myStack.falseMatch(left, right); 
                run = false; 
            }
        
        cout << "You are missing delimiter(s)." << endl;

        left = myStack.peek();
        cout << left << " is missing a matching delimiter." << endl;
    }
    else 
    {
        cout << "You are not missing any delimiters." << endl; 
    } 

    char choice; 
    bool cont = false;
    
    // prompt user to choose if they would like to check another file 
    cout << "Would you like to check another file?" << endl; 

    while (cont == false)
    {
        cout << "Enter 'y' to check another file or 'n' to exit program." << endl; 
        cin >> choice; 

        if (choice == 'y' || choice == 'Y')
        {
            cont = true; 
            run = true; 
        }
        else if (choice == 'n' || choice == 'N')
        {
            cont = true; 
            run = false; 
            exit(0); 
        }
        else 
        {
            cont = false; 
            cout << "Invalid entry." << endl; 
        }
    }
    } 
    while (run == true);
}