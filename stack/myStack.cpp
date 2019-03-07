#include <iostream>
#include "myStack.h"

using namespace std;

/*
 * Constructor
 * Usage: myStack(maxSz);
 * -------------------------
 * A new stack variable is initialized.  The initialized
 * stack is made empty.  maxSz is used to determine the
 * maximum number of character that can be held in the
 * stack.
 */

myStack::myStack(int maxSz) {
    
    contents = new int[maxSz];
    maxSize = maxSz;
    top = -1;
}


/* Destructor
 * Usage: delete ptr
 * -----------------------
 * This frees all memory associated with the stack.
 */

myStack::~myStack() {
	 delete [] contents;
}

void myStack::push(int element) {
    
     if (isFull())
         cout << "Stack is full" << endl;
     else {
         top++;
         contents[top] = element;
     }
}

int myStack::pop() {
	
    int valueHolder;
    
    if (!isEmpty()) {
        valueHolder = contents[top--];
        return valueHolder;
                }
    else
        cout << "Error!" << endl;
}

/*
 * Functions: isEmpty, isFull
 * Usage: if (s1.isEmpty()) ...
 * -----------------------------------
 * These return a true value if the stack is empty
 * or full (respectively).
 */

bool myStack::isEmpty() const {
    
    bool status;
    
    if (top == -1)
        status = true;
    else
        status = false;
    
    return status;
}

bool myStack::isFull() const {
    
    bool status;
    
    if (top == maxSize -1)
        status = true;
    else
        status = false;
    
    return status;
}

