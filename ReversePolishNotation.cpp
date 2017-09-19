//////////////////////////////////////////////
//	Cai Gwatkin								//
//////////////////////////////////////////////
//	This application reads in a text file	//
//	with an equation written in Reverse		//
//	Polish Notation and outputs the result	//
//////////////////////////////////////////////

#include "ReversePolishNotation.h"


int main(int argc, char **argv)
{
	if (argc != 2) return errArguments();
	
	calculateRPN(argv[1]);

	return 0;
}

// stack constructor
Stack::Stack()
{
	listPointer = NULL;
}

// stack destructor
Stack::~Stack()
{
	while (listPointer != NULL)
	{
		Node *temp = listPointer;
		listPointer = listPointer->next;
		delete temp;
	}
}

// adds int value to top of stack
void Stack::push(const int value)
{
	Node *temp;
	temp = new Node;
	temp->value = value;
	temp->next = listPointer;
	listPointer = temp;
}

// removes top int value from stack
void Stack::pop()
{
	Node *temp;
	temp = listPointer;
	if (listPointer != NULL)
	{
		listPointer = listPointer->next;
		delete temp;
	}
}

// checks if stack is empty
bool Stack::isEmpty()
{
	if (listPointer == NULL) return true;

	return false;
}

// returns value of top element
int Stack::top()
{
	return listPointer->value;
}

// exits program if incorrect number of command arguments
int errArguments()
{
	cout << "Error: Need a filename as argument" << endl;
	return 0;
}

// exits program if file cannot be opened
int errFile(const string fileName)
{
	cout << "Error: Cannot open file " << fileName << endl;
	return 0;
}

// exits program if too many operators in file
int errOpers()
{
	cout << "too many operators" << endl;
	return 0;
}

// exits program if too many values in file
int errValues()
{
	cout << "too many numbers" << endl;
	return 0;
}

// calculates and outputs final result
int calculateRPN(const char *file)
{
	// open file
	ifstream inFile(file);

	// returns error code if file cannot open
	if (!inFile) return errFile(file);

	Stack S;

	while (!inFile.eof())
	{
		// gets string from inFile
		string input;
		inFile >> input;

		// if input is a digit push that value onto stack
		if (isdigit(input[0]))
		{
			// change input string to int
			stringstream line(input);
			int value;
			line >> value;

			cout << "reading number " << value << endl;

			// push value onto stack
			S.push(value);
		}
		// if input is an operator top and pop 2 values from stack, then calculate and push result onto stack
		else
		{
			if ((input[0] == '+') || (input[0] == '-') || (input[0] == '*') || (input[0] == '/'))
			{

				// change input string to char
				stringstream line(input);
				char oper;
				line >> oper;

				cout << "reading operator " << oper << endl;

				// returns error code if stack is empty
				if (S.isEmpty()) return errOpers();

				// get value and pop it off stack
				int op1 = S.top();
				S.pop();

				// returns error code if stack is empty
				if (S.isEmpty()) return errOpers();

				// get value and pop it off stack
				int op2 = S.top();
				S.pop();

				// calculate result
				int result = 0;
				if (oper == '+') result = op2 + op1;
				else if (oper == '-') result = op2 - op1;
				else if (oper == '*') result = op2 * op1;
				else if (oper == '/') result = op2 / op1;
				
				// push result onto stack
				S.push(result);
			}
		}
	}

	// get final result
	int finalResult = S.top();

	// returns error code if too many values
	S.pop();
	if (!S.isEmpty()) return errValues();

	// outputs final result
	cout << "The result is " << finalResult << endl;

	inFile.close();

	return 0;
}
