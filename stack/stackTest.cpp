#include <iostream>
#include "myStack.h"

using namespace std;

void postfixTest() {
	myStack operandStack(100);
	cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
	cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;
	
    int operand1;
    int operand2;
    int valueHolder;
    
	while(!operandStack.isFull()){
		char inputHolder;
		cin >> inputHolder;
        
        if (inputHolder >= 48 && inputHolder <= 57)
            operandStack.push(inputHolder - 48);
        else if (inputHolder == '=') {
            
            valueHolder = operandStack.pop();
            
            if(!operandStack.isEmpty())
                cout << "The entered post-fix expression was not a legal one" << endl;
            else
                cout<< "The entered post fix expression results in " << valueHolder;
        }
        else{

        operand1 = operandStack.pop();
        operand2 = operandStack.pop();

            if (inputHolder == '+')
                operandStack.push(operand2 + operand1);
            else if (inputHolder == '-')
                operandStack.push(operand2 - operand1);
            else if (inputHolder == '*')
                operandStack.push(operand2 * operand1);
            else if (inputHolder == '/')
                operandStack.push(operand2/operand1);
            else
                cout << "Error! no such operands allowed" << endl;

        }
    }
}


int main()
{
    cout << "Testing the basic functions of the stack..." << endl;
	cout << "Please enter the max capacity of the testStack: ";
	int testSize;
	cin >> testSize;
	myStack testStack(testSize);
	
	cout << "Testing..." << endl;
	while(1) {
		cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		cin >> userChoice;
		
		if(userChoice == 'e')
			break;
		
		switch (userChoice) {
			case 'p':			
				if(!testStack.isFull()) {
					cout << "Please enter the integer you would like to push: ";
					int userInt;
					cin >> userInt;
					testStack.push(userInt);
				}
				else
					cout << "Nothing has been pushed in. The stack is full!" << endl;
				break;
			case 'o':
				if(!testStack.isEmpty())
					cout << testStack.pop() << " has been popped out" << endl;
				else
					cout << "Nothing has been popped out. The stack is empty!" << endl;
				break;
			default:
				cout << "Illegal user-input character. Please try again." << endl;
		}
	}

	cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
	postfixTest();	
	
	return 0;
}

