#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// linked list to use in stack
struct Node {
	int  value;
	Node *next;
};

// stack class
class Stack {
private:
	Node *listPointer;							// stores int values from RPN file
public:
	Stack();									// constructor
	~Stack();									// destructor
	void push(const int value);					// adds int value to top of stack
	void pop();									// removes top int value from stack
	bool isEmpty();								// checks if stack is empty
	int  top();									// returns value of top element
};


int errArguments();                                                             // exits program if incorrect number of command arguments
int errFile(const string fileName);                                             // exits program if file cannot be opened
int errOpers();                                                                 // exits program if too many operators in file
int errValues();                                                                // exits program if too many values in file
int calculateRPN(const char *file);                                             // calculates and outputs final result
