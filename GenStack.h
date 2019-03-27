#include <iostream>
#include <stack>
#include<stdexcept>

using namespace std; 

template<class ST> // Stack Template "ST" class 
class GenStack 
{
    public:
        GenStack(); // constructor 
        GenStack(int maxSize); // overloaded constructor 
        ~GenStack(); // deconstructor 

        void push(char curr); 
        ST pop();
        ST peek(); // aka top()

        int setSize(int newSize); 
        int getSize(); 
        bool isEmpty(); 
        bool isFull(); 
        ST resize(); 
        void setArray(ST *a);
        ST* getArray();
        bool checkMatch(char left, char right); // match functions would most likely not be reused
        void falseMatch(char left, char right);

        int size; 
        int top; 
        int lineNum;

        ST *myArray; 
};

template<class ST>
GenStack<ST>::GenStack() // default constructor 
{
    //initialize variable to default values 
    myArray = new ST(30);
    size = myArray->size(); 
    top = -1; 
}

template<class ST>
GenStack<ST>::~GenStack() // deconstructor 
{
    delete []myArray;
}

// push to stack 
template<class ST>
void GenStack<ST>::push(char curr) 
{
    // make sure stack is not full 
    if (isFull())
    {
        resize();
    }

    myArray[top++] = curr; // top is not 0 
}

// pop top element of stack 
template<class ST>
ST GenStack<ST>::pop()
{
    // error checking 
    if(top == -1) 
    {
        cout << "Stack is empty." << endl; 
    }
	else 
    {
        ST temp = myArray[top--];
        return temp; 
    }
}

// find top element of stack 
template<class ST>
ST GenStack<ST>::peek()
{
    // error checking 
    if(top == -1) 
    {
        cout << "Stack is empty." << endl; 
    }
    else 
    {
        return myArray[top]; 
    }
}

// if stack is not large enough for given data, this resizes it
template<class ST>
ST GenStack<ST>::resize()
{
    ST *newStack;
    int newSize = (getSize()*2);
    newStack = new ST[newSize];
    for (int i = 0; i < size; i++)
    {
        newStack[i] = myArray[i];
    }
    setSize(newSize);
    setArray(newStack);
}

// checks if stack is full 
template<class ST>
bool GenStack<ST>::isFull()
{
    return (top == size-1);
}

// checks if stack is empty 
template<class ST>
bool GenStack<ST>::isEmpty()
{
    return (top == -1);
}

// returns size of stack 
template<class ST>
int GenStack<ST>::getSize() 
{
    return top+1;
}

// sets up a new array for resize 
template <class ST>
void GenStack<ST>::setArray(ST *a)
{
    myArray = a;
} 

// sets new size for resize 
template<class ST>
int GenStack<ST>::setSize(int newSize) 
{
    size = newSize; 
    return newSize;
}

// returns array 
template <class ST>
ST* GenStack<ST>::getArray()
{
    return myArray;
} 

// checks if there is a match for each delimiter 
template <class ST>
bool GenStack<ST>::checkMatch(char left, char right)
{
    // if there is a pair, match = true, else = false 
    bool match; 

    // if there is a pair of brackets, make char left and right null (/0)
    if (left == '{' && right == '}')
    {
        left = '\0'; 
        right = '\0'; 
        match = true; 
    }
    if (left == '[' && right == ']')
    {
        left = '\0'; 
        right = '\0'; 
        match = true; 
    }
    if (left == '(' && right == ')') 
    {
        left = '\0'; 
        right = '\0'; 
        match = true; 
    }
    else 
    {
        match = false; 
    }

    return match; 
}

// if there is not a match for each delimiter 
template <class ST>
void GenStack<ST>::falseMatch(char left, char right)
{               
    // missing right delimiter 
    if (left == '{')
    {
        cout << "Missing }" << endl;
    }
    else if (left == '[')
    {
        cout << "Missing ]" << endl;
    }
    else if (left == '(') 
    {
        cout << "Missing )" << endl;
    }
    // missing left delimiter 
    else if (right == '}')
    {
        cout << "Missing {" << endl;
    }
    else if (right == ']')
    {
        cout << "Missing [" << endl;
    }
    else if (right == ')') 
    {
        cout << "Missing (" << endl;
    }
} 